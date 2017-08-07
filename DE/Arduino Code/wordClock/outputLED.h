//------------------------------------------------------------------------------------------
//                                     MOSFET
//------------------------------------------------------------------------------------------
//
// Where is the MOSFET connected to?
const int MOSFET = 30;

// Please define the value of the max. brightniss at 100 %. Number beetween 1 and 255.
const int MOSFET_Max = 255;
//------------------------------------------------------------------------------------------
//                                 WordClock_Words
//------------------------------------------------------------------------------------------
//
// Word "ES"
const int ES = 2;
// Word "IST"
const int IST = 3;
// Word "WAR"
const int WAR = 4;
// Word "JETZT"
const int JETZT = 5;
// Word "GLEICH"
const int GLEICH = 6;
// Word "ZEHN"
const int ZEHN_1 = 7;
// Word "ZWANZIG"
const int ZWANZIG = 8;
// Word "VIERTEL"
const int VIERTEL = 9;
// Word "HALB"
const int HALB = 10;
// Word "FÜNF"
const int FUENF_1 = 31;
// Word "VOR"
const int VOR = 12;
// Word "NACH"
const int NACH = 13;
// Word "EIN"
const int EIN = 14;
// Word "S"
const int S = 15;
// Word "ZWEI"
const int ZWEI = 16;
// Word "DREI"
const int DREI = 17;
// Word "VIER"
const int VIER = 18;
// Word "FÜNF"
const int FUENF_2 = 19;
// Word "SECHS"
const int SECHS = 52;
// Word "SIEBEN"
const int SIEBEN = 53;
// Word "ACHT"
const int ACHT = 22;
// Word "NEUN"
const int NEUN = 23;
// Word "ZEHN"
const int ZEHN_2 = 27;
// Word "ELF"
const int ELF = 24;
// Word "ZWÖLF"
const int ZWOELF = 25;
// Word "UHR"
const int UHR = 26;



void OFF();
void setLED(int stunde, int minute);
void initLED();
