// HEY! Welcome to the WordClock Program. Please check the Legal.h file to get an explenation of the code. <3

#include "LEDConfig_and_Output.h";   //---┐
#include "RTCModule.h";              //   │─> Include the other scetches of the prgram. 
#include "dcf77.h";                  //   │
#include "Settings.h";               //---┘
#include <Wire.h>                    // Inculude the Wire.h libary.
void setup() { 
  Serial.begin(9600); // open Serial Channel with a baud rate of 9600.
  startupSerial(); // Serial output void in "serialOutput.h"
  Serial.println("begin communication over the Wire.h libary..."); 
  Wire.begin();
  Serial.print(" ...done! \r \n Now starting LED-Init. It will turn on all LEDs.");
  initLED();
  OFF();
  Startup_Effects();
  Serial.print("\r \n \r \n Done with LED-Init. Now the DCF77 Setup");
  DCF77Process();
  Serial.print("Done with the setup. Go to main loop and begin with normal processing.");
}

void loop() {
    rtcReadTime();  
    setLED(stunde, minute);
}


