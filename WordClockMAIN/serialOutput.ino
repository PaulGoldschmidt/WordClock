//Serial Output

void startupSerial() {
  if (Serial.available()) {
  Serial.println("======================================================================");
  Serial.println("                                                                      ");
  Serial.println("                     WORDCLOCK MASTER PROGRAM                         ");
  Serial.println("                                                                      ");
  Serial.println("======================================================================");
  delay(100);
  Serial.println("                                                                      ");
  Serial.println("                                                                      ");
  Serial.println("The WORDCLOCK Master Program...                                       ");
  delay(100);
  Serial.print("...launching...                                                         ");
  delay(500);
  Serial.println("......................................................................");
  Serial.println(" Final Version of WordClock Version 2.0 without ShiftregisterLEDs     ");
  Serial.println(" This is the last Version of the WordClock Project 2.0.               ");
  Serial.println(" The next Versions will be incompatible to the concurrent Version.    ");
  Serial.println(" This program is compatible with all types of Verion 2.X.             ");
  Serial.println(" .....................................................................");
  Serial.println("                                                                      ");
  Serial.println("                                                                      ");
  Serial.println(" Copyright CODE: (C) 2017 by Paul Goldschmidt                         ");
  Serial.println("                                                                      ");
  Serial.println(" This code is published under the CC-Attribution-NonCommercial-       ");
  Serial.println(" NoDerivatives 4.0 licence.                                           ");
  delay(5000); 
  Serial.println("                                                                      ");
  Serial.println("                                                                      ");
  Serial.println("                                                                      ");
  Serial.println("                                                                      ");
  Serial.println("                                                                      ");
  Serial.println("                                                                      ");
  Serial.println("                                                                      ");
  Serial.println("                                                                      ");
  Serial.println("                                                                      ");
  Serial.println("                                                                      ");
  Serial.println("                                                                      ");
  Serial.println("======================================================================");
  Serial.println("                                                                      ");
  }
  else {
    delay(1);
  }
}

