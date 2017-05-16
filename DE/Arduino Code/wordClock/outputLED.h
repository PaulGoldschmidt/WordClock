//------------------------------------------------------------------------------------------
//                                     MOSFET
//------------------------------------------------------------------------------------------
//
// Where is the MOSFET connected to?
int MOSFET = 7;

// Please define the value of the max. brightniss at 100 %. Number beetween 1 and 255.
int MOSFET_Max = 100;
//------------------------------------------------------------------------------------------
//                                 WordClock_Words
//------------------------------------------------------------------------------------------
//
// Word "ES"
const int ES = 22;
// Word "IST"
const int IST = 23;
// Word "WAR"
const int WAR = 24;
// Word "JETZT"
const int JETZT = 25;
// Word "GLEICH"
const int GLEICH = 26;
// Word "ZEHN"
const int ZEHN_1 = 27;
// Word "ZWANZIG"
const int ZWANZIG = 28;
// Word "VIERTEL"
const int VIERTEL = 29;
// Word "HALB"
const int HALB = 30;
// Word "FÜNF"
const int FUENF_1 = 31;
// Word "VOR"
const int VOR = 32;
// Word "NACH"
const int NACH = 33;
// Word "EIN"
const int EIN = 34;
// Word "S"
const int S = 35;
// Word "ZWEI"
const int ZWEI = 36;
// Word "DREI"
const int DREI = 37;
// Word "VIER"
const int VIER = 38;
// Word "FÜNF"
const int FUENF_2 = 39;
// Word "SECHS"
const int SECHS = 43;
// Word "SIEBEN"
const int SIEBEN = 41;
// Word "ACHT"
const int ACHT = 40;
// Word "NEUN"
const int NEUN = 45;
// Word "ZEHN"
const int ZEHN_2 = 42;
// Word "ELF"
const int ELF = 47;
// Word "ZWÖLF"
const int ZWOELF = 46;
// Word "UHR"
const int UHR = 44;
//
// Creating "THE DEATH FUNCTION": This function will turn off all LEDs at the same time.
//
void OFF();
void setLED(int stunde, int minute);
void initLED();
