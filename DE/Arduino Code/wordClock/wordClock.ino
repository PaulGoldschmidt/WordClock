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

// -----------------------------------------------------------------------------------------
//                                   DCF77-Module variables
//------------------------------------------------------------------------------------------
//
// Where is the DCF-Module connected to?
#define DCF77PIN 2

// Not nessesary LED-Blink Pin.
#define BLINKPIN 13

// Turn debugging on or off
#define DCF_DEBUG 1

// Number of milliseconds to elapse before we assume a "1",
// if we receive a falling flank before - its a 0.
#define DCF_split_millis 140

// There is no signal in second 59 - detect the beginning of
// a new minute.
#define DCF_sync_millis 1200
// Definitions for the timer interrupt 2 handler:
// The Arduino runs at 16 Mhz, we use a prescaler of 64 -> We need to
// initialize the counter with 6. This way, we have 1000 interrupts per second.
// We use tick_counter to count the interrupts.
#define INIT_TIMER_COUNT 6
#define RESET_TIMER2 TCNT2 = INIT_TIMER_COUNT
int tick_counter = 0;
int TIMSK;
int TCCR2;
int OCIE2;


//------------------------------------------------------------------------------------------
//                                     MOSFET
//------------------------------------------------------------------------------------------
//
// Where is the MOSFET connected to?
int MOSFET = 7;

// Please define the value of the max. brightniss at 100 %. Number beetween 1 and 255.
int MOSFET_Max = 255;

//------------------------------------------------------------------------------------------
//                                 WordClock_Words
//------------------------------------------------------------------------------------------
//
// Word "ES"
int ES = 22;
// Word "IST"
int IST = 23;
// Word "WAR"
int WAR = 24;
// Word "JETZT"
int JETZT = 25;
// Word "GLEICH"
int GLEICH = 26;
// Word "ZEHN"
int ZEHN_1 = 27;
// Word "ZWANZIG"
int ZWANZIG = 28;
// Word "VIERTEL"
int VIERTEL = 29;
// Word "HALB"
int HALB = 30;
// Word "FÜNF"
int FUENF_1 = 31;
// Word "VOR"
int VOR = 32;
// Word "NACH"
int NACH = 33;
// Word "EIN"
int EIN = 34;
// Word "S"
int S = 35;
// Word "ZWEI"
int ZWEI = 36;
// Word "DREI"
int DREI = 37;
// Word "VIER"
int VIER = 38;
// Word "FÜNF"
int FUENF_2 = 39;
// Word "SECHS"
int SECHS = 40;
// Word "SIEBEN"
int SIEBEN = 41;
// Word "ACHT"
int ACHT = 42;
// Word "NEUN"
int NEUN = 43;
// Word "ZEHN"
int ZEHN_2 = 44;
// Word "ELF"
int ELF = 45;
// Word "ZWÖLF"
int ZWOELF = 46;
// Word "UHR"
int UHR = 47;
//
// Creating "THE DEATH FUNCTION": This function will turn off all LEDs at the same time.
//
void OFF() {
  delay(50);
  digitalWrite(ES, HIGH);
  digitalWrite(IST, LOW);
  digitalWrite(WAR, LOW);
  digitalWrite(JETZT, LOW);
  digitalWrite(GLEICH, LOW);
  digitalWrite(ZEHN_1, LOW);
  digitalWrite(ZWANZIG, LOW);
  digitalWrite(VIERTEL, LOW);
  digitalWrite(HALB, LOW);
  digitalWrite(FUENF_1, LOW);
  digitalWrite(VOR, LOW);
  digitalWrite(NACH, LOW);
  digitalWrite(EIN, LOW);
  digitalWrite(S, LOW);
  digitalWrite(ZWEI, LOW);
  digitalWrite(DREI, LOW);
  digitalWrite(VIER, LOW);
  digitalWrite(FUENF_2, LOW);
  digitalWrite(SECHS, LOW);
  digitalWrite(SIEBEN, LOW);
  digitalWrite(ACHT, LOW);
  digitalWrite(NEUN, LOW);
  digitalWrite(ZEHN_2, LOW);
  digitalWrite(ELF, LOW);
  digitalWrite(ZWOELF, LOW);
  digitalWrite(UHR, LOW);
  analogWrite(MOSFET, MOSFET_Max);
  return;
}
/**
   DCF time format struct
*/
struct DCF77Buffer {
  unsigned long long prefix  : 21;
  unsigned long long Min  : 7; // minutes
  unsigned long long P1   : 1; // parity minutes
  unsigned long long Hour : 6; // hours
  unsigned long long P2   : 1; // parity hours
  unsigned long long Day  : 6; // day
  unsigned long long Weekday  : 3; // day of week
  unsigned long long Month  : 5; // month
  unsigned long long Year : 8; // year (5 -> 2005)
  unsigned long long P3   : 1; // parity
};
struct {
  unsigned char parity_flag : 1;
  unsigned char parity_min    : 1;
  unsigned char parity_hour : 1;
  unsigned char parity_date : 1;
} flags;
/**
   Clock variables
*/
volatile unsigned char DCFSignalState = 0;
unsigned char previousSignalState;
int previousFlankTime;
int bufferPosition;
unsigned long long dcf_rx_buffer;
/**
   time vars: the time is stored here!
*/
volatile unsigned char ss;
volatile unsigned char mm;
volatile unsigned char hh;
volatile unsigned char day;
volatile unsigned char mon;
volatile unsigned int year;


/**
   used in main loop: detect a new second...
*/
unsigned char previousSecond;

/**
   Initialize the DCF77 routines: initialize the variables,
   configure the interrupt behaviour.
*/
void DCF77Init() {
  previousSignalState = 0;
  previousFlankTime = 0;
  bufferPosition = 0;
  dcf_rx_buffer = 0;
  ss = mm = hh = day = mon = year = 0;
#ifdef DCF_DEBUG
  Serial.println("Initializing DCF77 routines");
  Serial.print("Using DCF77 pin #");
  Serial.println(DCF77PIN);
  pinMode(BLINKPIN, OUTPUT);
  pinMode(DCF77PIN, INPUT);
#endif
  pinMode(DCF77PIN, INPUT);
#ifdef DCF_DEBUG
  Serial.println("Initializing timerinterrupt");
#endif
  //Timer2 Settings: Timer Prescaler /64,
  TCCR2 |= (1 << CS22);  // turn on CS22 bit
  TCCR2 &= ~((1 << CS21) | (1 << CS20)); // turn off CS21 and CS20 bits
  // Use normal mode
  TCCR2 &= ~((1 << WGM21) | (1 << WGM20)); // turn off WGM21 and WGM20 bits
  // Use internal clock - external clock not used in Arduino
  ASSR |= (0 << AS2);
  TIMSK |= (1 << TOIE2) | (0 << OCIE2);    //Timer2 Overflow Interrupt Enable
  RESET_TIMER2;
#ifdef DCF_DEBUG
  Serial.println("Initializing DCF77 signal listener interrupt");
#endif
  attachInterrupt(0, int0handler, CHANGE);
}

/**
   Append a signal to the dcf_rx_buffer. Argument can be 1 or 0. An internal
   counter shifts the writing position within the buffer. If position > 59,
   a new minute begins -> time to call finalizeBuffer().
*/
void appendSignal(unsigned char signal) {
#ifdef DCF_DEBUG
  Serial.print(", appending value ");
  Serial.print(signal, DEC);
  Serial.print(" at position ");
  Serial.println(bufferPosition);
#endif
  dcf_rx_buffer = dcf_rx_buffer | ((unsigned long long) signal << bufferPosition);
  // Update the parity bits. First: Reset when minute, hour or date starts.
  if (bufferPosition ==  21 && bufferPosition ==  29 && bufferPosition ==  36) {
    flags.parity_flag = 0;
  }
  // save the parity when the corresponding segment ends
  if (bufferPosition ==  28) {
    flags.parity_min = flags.parity_flag;
  };
  if (bufferPosition ==  35) {
    flags.parity_hour = flags.parity_flag;
  };
  if (bufferPosition ==  58) {
    flags.parity_date = flags.parity_flag;
  };
  // When we received a 1, toggle the parity flag
  if (signal == 1) {
    flags.parity_flag = flags.parity_flag ^ 1;
  }
  bufferPosition++;
  if (bufferPosition > 59) {
    finalizeBuffer();
  }
}

/**
   Evaluates the information stored in the buffer. This is where the DCF77
   signal is decoded and the internal clock is updated.
*/
void finalizeBuffer(void) {
  if (bufferPosition == 59) {
#ifdef DCF_DEBUG
    Serial.println("Finalizing Buffer");
#endif
    struct DCF77Buffer *rx_buffer;
    rx_buffer = (struct DCF77Buffer *)(unsigned long long)&dcf_rx_buffer;
    if (flags.parity_min == rx_buffer->P1  &&
        flags.parity_hour == rx_buffer->P2  &&
        flags.parity_date == rx_buffer->P3)
    {
#ifdef DCF_DEBUG
      Serial.println("Parity check OK - updating time.");
#endif
      //convert the received bits from BCD
      mm = rx_buffer->Min - ((rx_buffer->Min / 16) * 6);
      hh = rx_buffer->Hour - ((rx_buffer->Hour / 16) * 6);
      day = rx_buffer->Day - ((rx_buffer->Day / 16) * 6);
      mon = rx_buffer->Month - ((rx_buffer->Month / 16) * 6);
      year = 2000 + rx_buffer->Year - ((rx_buffer->Year / 16) * 6);
    }
#ifdef DCF_DEBUG
    else {
      Serial.println("Parity check NOK - running on internal clock.");
    }
#endif
  }
  // reset stuff
  ss = 0;
  bufferPosition = 0;
  dcf_rx_buffer = 0;
}

/**
   Dump the time to the serial line.
*/
void serialDumpTime(void) {
  Serial.print("Time: ");
  Serial.print(hh, DEC);
  Serial.print(":");
  Serial.print(mm, DEC);
  Serial.print(":");
  Serial.print(ss, DEC);
  Serial.print(" Date: ");
  Serial.print(day, DEC);
  Serial.print(".");
  Serial.print(mon, DEC);
  Serial.print(".");
  Serial.println(year, DEC);
}


/**
   Evaluates the signal as it is received. Decides whether we received
   a "1" or a "0" based on the
*/
void scanSignal(void) {
  if (DCFSignalState == 1) {
    int thisFlankTime = millis();
    if (thisFlankTime - previousFlankTime > DCF_sync_millis) {
#ifdef DCF_DEBUG
      serialDumpTime();
      Serial.println("####");
      Serial.println("#### Begin of new Minute!!!");
      Serial.println("####");
#endif
      finalizeBuffer();
    }
    previousFlankTime = thisFlankTime;
#ifdef DCF_DEBUG
    Serial.print(previousFlankTime);
    Serial.print(": DCF77 Signal detected, ");
#endif
  }
  else {
    /* or a falling flank */
    int difference = millis() - previousFlankTime;
#ifdef DCF_DEBUG
    Serial.print("duration: ");
    Serial.print(difference);
#endif
    if (difference < DCF_split_millis) {
      appendSignal(0);
    }
    else {
      appendSignal(1);
    }
  }
}

/**
   The interrupt routine for counting seconds - increment hh:mm:ss.
*/
ISR(TIMER2_OVF_vect) {
  RESET_TIMER2;
  tick_counter += 1;
  if (tick_counter == 1000) {
    ss++;
    if (ss == 60) {
      ss = 0;
      mm++;
      if (mm == 60) {
        mm = 0;
        hh++;
        if (hh == 24)
          hh = 0;
      }
    }
    tick_counter = 0;
  }
};

/**
   Interrupthandler for INT0 - called when the signal on Pin 2 changes.
*/
void int0handler() {
  // check the value again - since it takes some time to
  // activate the interrupt routine, we get a clear signal.
  DCFSignalState = digitalRead(DCF77PIN);
}


/**
   Standard Arduino methods below.
*/

void setup(void) {
  // We need to start serial here again,
  // for Arduino 007 (new serial code)
  Serial.begin(9600);
  DCF77Init();
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

}

void loop(void) {
  if (ss != previousSecond) {
    serialDumpTime();
    previousSecond = ss;
  }
  if (DCFSignalState != previousSignalState) {
    scanSignal();
    if (DCFSignalState) {
      digitalWrite(BLINKPIN, HIGH);
    } else {
      digitalWrite(BLINKPIN, LOW);
    }
    previousSignalState = DCFSignalState;
  }
  // -------------------------------------------------------------------------------------------------
  //                                       WORDCLOCK VARIABLES
  // -------------------------------------------------------------------------------------------------
  if (year != 0) 
  {
    if (mm == 0)
    {
      OFF();
      digitalWrite(IST, HIGH);
      digitalWrite(JETZT, HIGH);
      digitalWrite(UHR, HIGH);
    }
    else if ((mm > 0) && (mm <= 3))
    {
      OFF();
      digitalWrite(WAR, HIGH);
      digitalWrite(UHR, HIGH);
    }
    else if ((mm > 3) && (mm < 5))
    {
      OFF();
      digitalWrite(IST, HIGH);
      digitalWrite(GLEICH, HIGH);
      digitalWrite(FUENF_1, HIGH);
    }
    else if (mm == 5)
    {
      OFF();
      digitalWrite(IST, HIGH);
      digitalWrite(JETZT, HIGH);
      digitalWrite(FUENF_1, HIGH);
      digitalWrite(NACH, HIGH);
    }
    else if ((mm > 5) && (mm <= 7))
    {
      OFF();
      digitalWrite(WAR, HIGH);
      digitalWrite(FUENF_1, HIGH);
      digitalWrite(NACH, HIGH);
    }
    else if ((mm > 7) && (mm < 10))
    {
      OFF();
      digitalWrite(IST, HIGH);
      digitalWrite(GLEICH, HIGH);
      digitalWrite(ZEHN_2, HIGH);
      digitalWrite(NACH, HIGH);
    }
    else if (mm == 10)
    {
      OFF();
      digitalWrite(IST, HIGH);
      digitalWrite(JETZT, HIGH);
      digitalWrite(ZEHN_1, HIGH);
      digitalWrite(NACH, HIGH);
    }
    else if ((mm > 10) && (mm <= 12))
    {
      OFF();
      digitalWrite(WAR, HIGH);
      digitalWrite(ZEHN_1, HIGH);
      digitalWrite(NACH, HIGH);
    }
    else if ((mm > 12) && (mm < 15))
    {
      OFF();
      digitalWrite(IST, HIGH);
      digitalWrite(GLEICH, HIGH);
      digitalWrite(VIERTEL, HIGH);
      digitalWrite(NACH, HIGH);
    }
    else if (mm == 15)
    {
      OFF();
      digitalWrite(IST, HIGH);
      digitalWrite(JETZT, HIGH);
      digitalWrite(VIERTEL, HIGH);
      digitalWrite(NACH, HIGH);
    }
    else if ((mm > 15) && (mm <= 17))
    {
      OFF();
      digitalWrite(WAR, HIGH);
      digitalWrite(VIERTEL, HIGH);
      digitalWrite(NACH, HIGH);
    }
    else if ((mm > 17) && (mm < 20))
    {
      OFF();
      digitalWrite(IST, HIGH);
      digitalWrite(GLEICH, HIGH);
      digitalWrite(ZWANZIG, HIGH);
      digitalWrite(NACH, HIGH);
    }
    else if (mm == 20)
    {
      OFF();
      digitalWrite(IST, HIGH);
      digitalWrite(JETZT, HIGH);
      digitalWrite(ZWANZIG, HIGH);
      digitalWrite(NACH, HIGH);
    }
    else if ((mm > 20) && (mm < 25))
    {
      OFF();
      digitalWrite(WAR, HIGH);
      digitalWrite(ZWANZIG, HIGH);
      digitalWrite(NACH, HIGH);
    }
    else if ((mm >= 25) && (mm < 30))
    {
      OFF();
      digitalWrite(IST, HIGH);
      digitalWrite(GLEICH, HIGH);
      digitalWrite(HALB, HIGH);
    }
    else if (mm == 30)
    {
      OFF();
      digitalWrite(IST, HIGH);
      digitalWrite(JETZT, HIGH);
      digitalWrite(HALB, HIGH);
    }
    else if ((mm > 30) && (mm <= 34))
    {
      OFF();
      digitalWrite(WAR, HIGH);
      digitalWrite(HALB, HIGH);
    }
    else if ((mm >= 35) && (mm < 40))
    {
      OFF();
      digitalWrite(IST, HIGH);
      digitalWrite(GLEICH, HIGH);
      digitalWrite(ZWANZIG, HIGH);
      digitalWrite(VOR, HIGH);
    }
    else if (mm == 40)
    {
      OFF();
      digitalWrite(IST, HIGH);
      digitalWrite(JETZT, HIGH);
      digitalWrite(ZWANZIG, HIGH);
      digitalWrite(VOR, HIGH);
    }
    else if ((mm > 40) && (mm <= 42))
    {
      OFF();
      digitalWrite(WAR, HIGH);
      digitalWrite(ZWANZIG, HIGH);
      digitalWrite(VOR, HIGH);
    }
    else if ((mm > 42) && (mm < 45))
    {
      OFF();
      digitalWrite(IST, HIGH);
      digitalWrite(GLEICH, HIGH);
      digitalWrite(VIERTEL, HIGH);
      digitalWrite(VOR, HIGH);
    }
    else if (mm == 45)
    {
      OFF();
      digitalWrite(IST, HIGH);
      digitalWrite(JETZT, HIGH);
      digitalWrite(VIERTEL, HIGH);
      digitalWrite(VOR, HIGH);
    }
    else if ((mm > 45) && (mm < 47))
    {
      OFF();
      digitalWrite(WAR, HIGH);
      digitalWrite(VIERTEL, HIGH);
      digitalWrite(VOR, HIGH);
    }
    else if ((mm >= 47) && (mm < 50))
    {
      OFF();
      digitalWrite(IST, HIGH);
      digitalWrite(GLEICH, HIGH);
      digitalWrite(ZEHN_1, HIGH);
      digitalWrite(VOR, HIGH);
    }
    else if (mm == 50)
    {
      OFF();
      digitalWrite(IST, HIGH);
      digitalWrite(JETZT, HIGH);
      digitalWrite(ZEHN_1, HIGH);
      digitalWrite(VOR, HIGH);
    }
    else if ((mm > 50) && (mm < 52))
    {
      OFF();
      digitalWrite(WAR, HIGH);
      digitalWrite(ZEHN_1, HIGH);
      digitalWrite(VOR, HIGH);
    }
    else if ((mm >= 52) && (mm < 55))
    {
      OFF();
      digitalWrite(IST, HIGH);
      digitalWrite(GLEICH, HIGH);
      digitalWrite(FUENF_1, HIGH);
      digitalWrite(VOR, HIGH);
    }
    else if (mm == 55)
    {
      OFF();
      digitalWrite(IST, HIGH);
      digitalWrite(JETZT, HIGH);
      digitalWrite(FUENF_1, HIGH);
      digitalWrite(VOR, HIGH);
    }
    else if ((mm > 55) && (mm < 57))
    {
      OFF();
      digitalWrite(WAR, HIGH);
      digitalWrite(FUENF_1, HIGH);
      digitalWrite(VOR, HIGH);
    }
    else if ((mm >= 57) && (mm < 59))
    {
      OFF();
      digitalWrite(IST, HIGH);
      digitalWrite(GLEICH, HIGH);
      digitalWrite(UHR, HIGH);
    }
    //
    //----------------------------------------------------------------------------------------------
    //
    if ((hh == 1) || (hh == 13))
    {
      digitalWrite(EIN, HIGH);
    }
    else if ((hh == 2) || (hh == 14))
    {
      digitalWrite(ZWEI, HIGH);
    }
    else if ((hh == 3) || (hh == 15))
    {
      digitalWrite(DREI, HIGH);
    }
    else if ((hh == 4) || (hh == 16))
    {
      digitalWrite(VIER, HIGH);
    }
    else if ((hh == 5) || (hh == 17))
    {
      digitalWrite(FUENF_2, HIGH);
    }
    else if ((hh == 6) || (hh == 18))
    {
      digitalWrite(SECHS, HIGH);
    }
    else if ((hh == 7) || (hh == 19))
    {
      digitalWrite(SIEBEN, HIGH);
    }
    else if ((hh == 8) || (hh == 20))
    {
      digitalWrite(ACHT, HIGH);
    }
    else if ((hh == 9) || (hh == 21))
    {
      digitalWrite(NEUN, HIGH);
    }
    else if ((hh == 10) || (hh == 22))
    {
      digitalWrite(ZEHN_2, HIGH);
    }
    else if ((hh == 11) || (hh == 23))
    {
      digitalWrite(ELF, HIGH);
    }
    else if ((hh == 12) || (hh == 0))
    {
      digitalWrite(ZWOELF, HIGH);
    }
  }
}
