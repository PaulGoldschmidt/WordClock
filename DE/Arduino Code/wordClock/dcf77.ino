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

void getSignal() {
  bool signalFound = false;
  while (signalFound == false)
  {
    old_loop();
    if (year != 0) {
      Serial.println(year);
      signalFound = true;
    }
  }
}

// original Loop Schleife
void old_loop() {
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
}


