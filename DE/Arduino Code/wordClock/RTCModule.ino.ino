#include <Wire.h>
#define RTC_I2C_ADDRESS 0x68 // I2C Adresse des RTC  DS3231
 
//Membervariablen

//Ließt den aktuellen Zeitstempel aus dem RTC Modul.
void rtcReadTime(){
  Wire.beginTransmission(RTC_I2C_ADDRESS); //Aufbau der Verbindung zur Adresse 0x68
  Wire.write(0);
  Wire.endTransmission();
  Wire.requestFrom(RTC_I2C_ADDRESS, 7);
  sekunde    = bcdToDec(Wire.read() & 0x7f);
  minute     = bcdToDec(Wire.read()); 
  stunde     = bcdToDec(Wire.read() & 0x3f); 
  //Der Wochentag wird hier nicht ausgelesen da dieses mit 
  //dem Modul RTC DS3231 nicht über die Wire.h zuverlässig funktioniert.
  /* wochentag  =*/ bcdToDec(Wire.read());
  tag        = bcdToDec(Wire.read());
  monat      = bcdToDec(Wire.read());
  jahr       = bcdToDec(Wire.read())+2000;    
}
 
//Funktion zum schreiben / setzen der Uhrzeit.
void rtcWriteTime(int jahr, int monat, int tag, int stunde, int minute, int sekunde){
  Wire.beginTransmission(RTC_I2C_ADDRESS);
  Wire.write(0); // Der Wert 0 aktiviert das RTC Modul.
  Wire.write(decToBcd(sekunde));    
  Wire.write(decToBcd(minute));
  Wire.write(decToBcd(stunde));                                  
  Wire.write(decToBcd(0)); // Wochentag unberücksichtigt
  Wire.write(decToBcd(tag));
  Wire.write(decToBcd(monat));
  Wire.write(decToBcd(jahr-2000));  
  Wire.endTransmission();  
}
 
//Berechnet den Tag der Woche aus dem übergebenen Datumswerten.
byte calcDayOfWeek(int jahr, byte monat, byte tag) {
  static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
  jahr -= monat < 3;
  return ((jahr + jahr/4 - jahr/100 + jahr/400 + t[monat-1] + tag) % 7); 
}
 
//Convertiert Dezimalzeichen in binäre Zeichen.
byte decToBcd(byte val){
  return ( (val/10*16) + (val%10) );
}
 
//Convertiert binäre Zeichen in Dezimal Zeichen.
byte bcdToDec(byte val){
  return ( (val/16*10) + (val%16) );
}
 
//Ließt einen String und liefert einen Integer Wert von einer 
//definierten Stelle (byte num) des Stringwertes.
int getIntFromString (char *stringWithInt, byte num){
  char *tail; 
  while (num>0){
    num--;
    //Bei Kommanseparierten Listen werden die Kommata 
    //übersprungen und geben damit die Unterteilung des Strings an.
    while ((!isdigit (*stringWithInt))&&(*stringWithInt!=0)){
      stringWithInt++;
    }
    tail=stringWithInt;
    //Schleife solange ausführen bis eine Zahl gefunden wurde
    //welche größer 0 ist.
    while ((isdigit(*tail))&&(*tail!=0)){
      tail++;
    }
   
    if (num>0){
      stringWithInt=tail;
    }
  }  
  return(strtol(stringWithInt, &tail, 10));
}  
 

//Gibt einen Zeitstempel auf der Seriellen Schnittstelle aus.
void printRTCDateTime(){
  char linebuf[60];
  int dOW = calcDayOfWeek(jahr, monat, tag);
  String wochentagC = daysInWeek[dOW];
  String monatC = monthInYear[monat-1];
 
  String result = "";
  result += wochentagC;
  result += ", ";
  result += tag;
  result += ".";
  result += monatC;
  result += " ";  
  result += jahr;  
  result += " "; 
  if(stunde<10) { result += "0"; }
  result += stunde;  
  result += ":";  
  if(minute<10) { result += "0"; }
  result += minute;  
  result += ":"; 
  if(sekunde<10) { result += "0"; }
  result += sekunde;  
  Serial.println(result); 
}
 
//Manuelles setzen der Uhrzeit über den Seriellen Monitor der IDE.
void setRTCTime(){
  char linebuf[30];
  byte counter;
  if (Serial.available()){
    delay(100); // Warte auf das Eintreffen aller Zeichen vom seriellen Monitor
    memset(linebuf,0,sizeof(linebuf)); // Zeilenpuffer löschen
    counter=0; // Zähler auf Null
    while (Serial.available()){
      linebuf[counter]=Serial.read(); // Zeichen in den Zeilenpuffer einfügen
      if (counter<sizeof(linebuf)-1) counter++; // Zeichenzähler erhöhen
    }
    // Wenn in der gelesenen Zeile das Wort 'set' vorkommt dann...
    //(Hier muss man bedenken das die Suche nach 'set' auch nach x Zeichen ein positives Ergebnis liefern wird, zbsp. 123set 09.01.2016 12:00:00)
    if (strstr(linebuf,"set")==linebuf){ 
      tag=getIntFromString (linebuf,1);
      monat=getIntFromString (linebuf,2);
      jahr=getIntFromString (linebuf,3);
      stunde=getIntFromString (linebuf,4);
      minute=getIntFromString (linebuf,5);
      sekunde=getIntFromString (linebuf,6);
    } else {
      Serial.println("Befehl unbekannt.");
      return;
    }
    // Ausgelesene Werte einer groben Plausibilitätsprüfung unterziehen:
    if (!checkDateTime(jahr, monat, tag, stunde, minute, sekunde)){
      Serial.println(linebuf);
      Serial.println("Fehlerhafte Zeitangabe im 'set' Befehl");
      Serial.println("Beispiel: set 28.08.2013 10:54");
      return;
    }
    rtcWriteTime(jahr, monat, tag, stunde, minute, sekunde);
    Serial.println("Zeit und Datum wurden auf neue Werte gesetzt.");
  }
}
 
//Prüft das eingegebene Datum auf korrektheit.
boolean checkDateTime(int jahr, int monat, int tag, int stunde, int minute, int sekunde){
   boolean result = false;
   if(jahr>2000){
     result = true;  
   } else {
     return false;
   }
   // Schaltjahr prüfen
   if(jahr % 400 == 0 || (jahr % 100 != 0 && jahr % 4 == 0)){
     //Wenn es ein Schaltjahr ist dann den Wert 29 in das Array an der Stelle 1 für den Monat Februar schreiben.
     daysInMonth[1]=29;
   }
   
   //Monat muss kleiner 13 sein.
   if (monat<13){
      if( tag <= daysInMonth[monat-1] ){
        result = true;
      }
   } else {
     return false;
   }
    
  //Wert für Stunde muss zwischen 0 und 24 liegen,
  //Wert für Minute und sekunde muss zwischen 0 und 59 liegen
  if(stunde <24 && minute <60 && sekunde <60 && stunde >= 0 && minute >=0 && sekunde >=0){
        result = true;
  } else {
     return false;
   }
   
   return result;
}

