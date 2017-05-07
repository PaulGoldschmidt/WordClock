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
//#include "time.h";

void setup(void) {
  // We need to start serial here again,
  // for Arduino 007 (new serial code)
  Serial.begin(9600);
  // init RTC
  Wire.begin(); //Kommunikation über die Wire.h bibliothek beginnen.
  // init DCF77
  DCF77Init();
  // init LEDOutput
  pinMode(ES, OUTPUT);
  pinMode(IST, OUTPUT);
  pinMode(WAR, OUTPUT);
  pinMode(JETZT, OUTPUT);
  pinMode(GLEICH, OUTPUT);
  pinMode(ZEHN_1, OUTPUT);
  pinMode(ZWANZIG, OUTPUT);
  pinMode(VIERTEL, OUTPUT);
  pinMode(HALB, OUTPUT);
  pinMode(FUENF_1, OUTPUT);
  pinMode(VOR, OUTPUT);
  pinMode(NACH, OUTPUT);
  pinMode(EIN, OUTPUT);
  pinMode(S, OUTPUT);
  pinMode(ZWEI, OUTPUT);
  pinMode(DREI, OUTPUT);
  pinMode(VIER, OUTPUT);
  pinMode(FUENF_2, OUTPUT);
  pinMode(SECHS, OUTPUT);
  pinMode(SIEBEN, OUTPUT);
  pinMode(ACHT, OUTPUT);
  pinMode(NEUN, OUTPUT);
  pinMode(ZEHN_2, OUTPUT);
  pinMode(ELF, OUTPUT);
  pinMode(ZWOELF, OUTPUT);
  pinMode(UHR, OUTPUT);
//  getSignal();
//  Serial.println(hh);
//  Serial.println(mm);
//  Serial.println(ss);
  rtcReadTime();
  Serial.println(stunde);
  Serial.println(minute);
  Serial.println(sekunde);
}

void loop(void) {

  // -------------------------------------------------------------------------------------------------
  //                                       WORDCLOCK VARIABLES
  // -------------------------------------------------------------------------------------------------
  setLED(stunde, minute);
  delay(1000);
}
