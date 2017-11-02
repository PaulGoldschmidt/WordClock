#include <Wire.h>
#define RTC_I2C_ADDRESS 0x68 // I2C Adresse des RTC  DS3231
 
//Membervariablen
int jahr,monat,tag,stunde,minute,sekunde, wochentag;
int daysInMonth[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
String daysInWeek[7] = {"Sonntag", "Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag"};
String monthInYear[12] = {"Januar","Februar", "März", "April", "Mai", "Juni", "Juli", "August", "September", "Oktober", "November", "Dezember"};
String outputFormat = "%s, %02d.%s %04d %02d:%02d:%02d Uhr";
 
//Ließt den aktuellen Zeitstempel aus dem RTC Modul.
void rtcReadTime();
//Funktion zum schreiben / setzen der Uhrzeit.
void rtcWriteTime(int jahr, int monat, int tag, int stunde, int minute, int sekunde);
//Berechnet den Tag der Woche aus dem übergebenen Datumswerten.
byte calcDayOfWeek(int jahr, byte monat, byte tag) ;
 
//Convertiert Dezimalzeichen in binäre Zeichen.
byte decToBcd(byte val);
 
//Convertiert binäre Zeichen in Dezimal Zeichen.
byte bcdToDec(byte val);

//Ließt einen String und liefert einen Integer Wert von einer 
//definierten Stelle (byte num) des Stringwertes.
int getIntFromString (char *stringWithInt, byte num);  
 
 
//Gibt einen Zeitstempel auf der Seriellen Schnittstelle aus.
void printRTCDateTime();
 
//Manuelles setzen der Uhrzeit über den Seriellen Monitor der IDE.
void setRTCTime();
 
//Prüft das eingegebene Datum auf korrektheit.
boolean checkDateTime(int jahr, int monat, int tag, int stunde, int minute, int sekunde);
