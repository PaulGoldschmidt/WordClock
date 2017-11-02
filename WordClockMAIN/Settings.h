/* settings.ino file.

HERE IS THE SETTINGS FILE. PLEASE READ CAREFULLY THE CAPTIONS. BE CARFUL WHEN EDITING.

Also edit the LEDConfig_and_Output.h file! (LED-PINS)

CONTENS OF THIS FILE:
- MOSFET SETTINGS
- DCF77 SETTINGS
- RTC SETTINGS
- STARTUP EFFECTS
- NIGHT-TURN-OFF SETTINGS
- TIME-CHANGE SETTINGS
- AUTO-BRIGHTNESS FEATURES (REQUIRES PHOTORESITOR) 
- DEBUGGING FEATURES 
- ...

*/

//------------------------------------------------------------------------------------------
//                                  MOSFET SETTINGS
//------------------------------------------------------------------------------------------
//
// Where is the MOSFET connected to? MOSFET PIN on the Arduino
int MOSFET = 8;

// Please define the value of the max. brightniss at 100%. Number beetween 1 and 255.
int MOSFET_Max = 255;

//
//------------------------------------------------------------------------------------------
//                                  DCF77 SETTINGS
//------------------------------------------------------------------------------------------
//
// Is in your model a DCF77-Module? (1 = available, 0 = unavailable)
int DCFAvailable = 0;

// If you've got a DCF-Module in your Clock, please specify the pin where it is 
// connected to.
int DCF77PIN = 8;

// Which mode do you want for encoding of the time signal? (1 = intelligent (recommended),
// 2 (force DCF signal), 3 (disable DCF Module))
int DCFMode = 1;

// In Mode 1, how long should it take till timeout? (Seconds)
int TimeoutDCF77Setting = 500;

//
//------------------------------------------------------------------------------------------
//                                  RTC Module Settings
//------------------------------------------------------------------------------------------
//

// Theres nothing to configure here, brb. Just connect the module to 
// Pin 20 (SDA) and Pin 21 (SCL).

//
//------------------------------------------------------------------------------------------
//                                   STARTUPEFFCTS
//------------------------------------------------------------------------------------------
//
// Enable the Startup Effect? (0 = off, 1 = on)
int StartupEnabled = 1;

// Which StartupEffect? (1 = dynamic (normal), 2 = party, 3 = debugging)
int StartupEffectMode = 2;

// How much time should be between the LEDs Turn on/off? 500 ms is normal. Less difference
// could cause in crashing while power drop, more needs longer to startup.
int StartupEffectDifference = 500;

//
//------------------------------------------------------------------------------------------
//                                NIGHT-SHUTDOWN SETTINGS
//------------------------------------------------------------------------------------------
//
// Should be enable the Night-Shutdown? (0 = off, 1 = on)
int NightOn = 0;

// If Night-Shutdown enabled than specify the time. Just houres, not minutes.
int NightTime_Off = 23; // here is when it go into night mode
int NightTime_On = 8; // here it ends.

// How bright should be the WordClock at night? (0 = all LEDs Off, 255 = max. brightness)
int NightBrightness = 0;

//
//------------------------------------------------------------------------------------------
//                                TIME-CHANGE SETTINGS
//------------------------------------------------------------------------------------------
//
// Enable the auto-Time-Change? (0 = off, 1 = on)
int TimeChange = 1;

// Because you can't calculate the date of the time-change, you have to define it.
int TimeChange_WinterTime = 30; // The date in October on which the clock steps 1 hour back.
int TimeChange_SummerTime = 16; // The date in March on which the clock steps 1 hour 
                                // forward.

//
//------------------------------------------------------------------------------------------
//                           Autobrightness with Phototransistor
//------------------------------------------------------------------------------------------
//
// Is there a Phototransistor connected to the Arduino? (0 = no, 1 = yes)
int PhototransistorAvailable = 0;

// When you connected a Phototransistor to the Arduino, specify the Pin on which 
// it's connected to
int PhototransistorPin = A1;

// What is the minimum and maximum brightness of the WordClock?
int PhototransistorMin = 70;  // Minimum brightness
int PhototransistorMax = 255; // Maximum brightness

//
//------------------------------------------------------------------------------------------
//                                  DEEBUGGING FEATURES
//------------------------------------------------------------------------------------------
//
void DCF77Process();
