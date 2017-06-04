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
#include "RTCModule.h";
#include "outputLED.h";
#include "dcf77.h";
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
  LEDInit();
  // init DCF77
}
void software_Reset() // Restarts program from beginning but does not reset the peripherals and registers
  {
    asm volatile ("jmp 0");  
  } 
void loop(void) {

  // -------------------------------------------------------------------------------------------------
  //                                       WORDCLOCK VARIABLES
  // -------------------------------------------------------------------------------------------------
  if (stunde == 23)
  { // Nachtschaltung
    Serial.println("NACHT AKTIVIERT. 23");
    Nacht();
  }
  else if (stunde == 24)
    { // Nachtschaltung
    Serial.println("NACHT AKTIVIERT. 24");
    Nacht();
  }
  else if (stunde == 0)
    { // Nachtschaltung
    Serial.println("NACHT AKTIVIERT. 0");
    Nacht();
  Serial.println(hh);
  Serial.println(mm);
  Serial.println(ss);
  rtcWriteTime(year, mon, day, hh, mm, ss);
  rtcReadTime();
  Serial.println(stunde);
  Serial.println(minute);
  Serial.println(sekunde);
  }
  else if (stunde == 1)
    { // Nachtschaltung
    Serial.println("NACHT AKTIVIERT. 1");
    Nacht();
  }
  else if (stunde == 2)
    { // Nachtschaltung
    Serial.println("NACHT AKTIVIERT. 2");
    Nacht();
  }
  else if (stunde == 3)
    { // Nachtschaltung
    Serial.println("NACHT AKTIVIERT. 3");
    Nacht();
  }
  else if (stunde == 4)
    { // Nachtschaltung
    Serial.println("NACHT AKTIVIERT. 4");
    Nacht();
  }
  else if (stunde == 5)
    { // Nachtschaltung
    Serial.println("NACHT AKTIVIERT. 5");
    Nacht();
    }
    else if (stunde == 6)
    { // Nachtschaltung
    Serial.println("NACHT AKTIVIERT. 6");
    Nacht();
  }
    else if (stunde == 7)
    { // Nachtschaltung
    Serial.println("NACHT AKTIVIERT. 7");
    Nacht();
    software_Reset;
  }
  else
  {
    rtcReadTime();  
    setLED(stunde, minute);
  } 
}
