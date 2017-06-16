/**
                                                        VERSION 0.7, May 2017
   --------------------------------------------------------------------------
                             WORDCLOCK Master
   ========================== GERMAN VERSION ================================
   --------------------------------------------------------------------------
   The WordClock Project.
   Project by Paul Goldschmidt

   Bord / Processor               ATMEGA 2560
   I / O occupied:                25
   DCF77 Version:                 YES
        DCF-Sensor Type           DCF-1 Module by Pollin
   ambient light sensor:          N/A
        Resistance:               N/A
        MOSFET Type:              IRLZ44N
   Fuse rated to:                 1.5 Ampere
   Voltage:                       5 Volt DC


   GERMAN VERSION


   Copyright (C) 2017 by Paul Goldschmidt


   DCF77 translation by Mathias Dalheimer (md@gonium.net), Copyright (C) 2006.
   Website:
   https://gonium.net
   The code is published under the GNU General Public License.
*/
#include <Wire.h>
#include "RTCModule.h"
#include "outputLED.h"
#include "dcf77.h"

void setRealClock() {
  getSignal();
  Serial.println(hh);
  Serial.println(mm);
  Serial.println(ss);
  rtcWriteTime(year, mon, day, hh, mm, ss);
  rtcReadTime();
  Serial.println(stunde);
  Serial.println(minute);
  Serial.println(sekunde);
}

void setup(void) {
  // We need to start serial here again,
  // for Arduino 007 (new serial code)
  Serial.begin(9600);
  // init RTC
  Wire.begin(); //Kommunikation über die Wire.h bibliothek beginnen.
  initLED();
  // init DCF77
  DCF77Init(); 
  setRealClock();
}

void loop(void) {

  // -------------------------------------------------------------------------------------------------
  //                                       WORDCLOCK VARIABLES
  // -------------------------------------------------------------------------------------------------
  rtcReadTime();
  if ((stunde >= 23) && (stunde <= 5))
  { // Nachtschaltung
    Nacht();
    delay(600000);
  }
  else
  {
    setLED(stunde, minute);
    delay(30000);
  }
  
  /*if ((stunde == 4) && (minute==0)) {
    Serial.println("suche DCF77 Signal und setze RTC Uhr");
    setRealClock();
  }*/
}
