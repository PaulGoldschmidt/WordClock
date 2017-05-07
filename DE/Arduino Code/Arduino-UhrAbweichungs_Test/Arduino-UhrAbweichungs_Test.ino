/*
 * Test zum Messen der Abweichung des internen Oszillators des Arudinos.
 * Test starten, startzeit aufschreiben und zwischen 10 und 30 Stunden laufen lassen. Am Ende differenz berechnen.
 * 
 * Mein Arduino Mega 2560 hat auf 12 Stunden rund 3 Minuten und 20 Sekunden Abweichung.
 */
int Sekunde = 0;
int Minute = 0;
int Stunde = 0;
int StartzeitStunde = 20; // Startzeit des Testes festlegen, nur zur uebersicht.
int StartzeitMinute = 30; // Startzeit Minute
void setup() {
Serial.begin(9600);      // Serien Port mit 9600 bps oeffnen.
Serial.println("------------------------------------------------------------------");
Serial.print("Test gestartet um ");
Serial.print(StartzeitStunde);
Serial.print(":");
Serial.print(StartzeitMinute);
Serial.println(" Uhr.");
Serial.println("--------------------------------------------------------------------");
Serial.println("");
}
void loop() {
Serial.print(Sekunde);
Serial.print(" Sekunden, ");
Serial.print(Minute);
Serial.print(" Minuten und ");
Serial.print(Stunde);
Serial.print(" Stunden ");
Serial.println("seid start");
Serial.println("");
Serial.println("-------------------");
Serial.println("");
Sekunde++;
if (Sekunde >= 60)
{
  Minute++;
  Sekunde = 0;
}
if (Minute >= 60)
{
  Stunde++;
  Minute = 0;
}
delay(1000);
}
