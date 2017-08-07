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
#define DCF77PIN A2

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
void DCF77Init();

/**
   Append a signal to the dcf_rx_buffer. Argument can be 1 or 0. An internal
   counter shifts the writing position within the buffer. If position > 59,
   a new minute begins -> time to call finalizeBuffer().
*/
void appendSignal(unsigned char signal);

/**
   Evaluates the information stored in the buffer. This is where the DCF77
   signal is decoded and the internal clock is updated.
*/
void finalizeBuffer(void);

/**
   Dump the time to the serial line.
*/
void serialDumpTime(void);


/**
   Evaluates the signal as it is received. Decides whether we received
   a "1" or a "0" based on the
*/
void scanSignal(void);

/**
   The interrupt routine for counting seconds - increment hh:mm:ss.
*/
ISR(TIMER2_OVF_vect);

/**
   Interrupthandler for INT0 - called when the signal on Pin 2 changes.
*/
void int0handler();
void old_loop();
void getSignal();
