int PartyDelay = 50; // Party elay for fast swiching off the LEDs in party mode.
int DebuggingDelay = 500; // 0.5 second delay for debugging. 
int DynamicDelay = StartupEffectDifference; // You can change the delay in the settings.
//---------------------------------------------------
void Startup_Effects() { 
  delay(PartyDelay);
  Serial.println("Start Up Effect Loop ready.");
  analogWrite(MOSFET, MOSFET_Max); // swich MOSFET on...
  Serial.println("MOSFET set to MAX.");
  if ((StartupEnabled == 1) && (StartupEffectMode == 1)) {
   Serial.println("StartupEffect active. Begining the Effect #1.");
   DynamicVoid();
   Serial.println("StartupEffectMode 1 executing. Please wait.");
   delay(DynamicDelay);
   DynamicVoid();
   delay(DynamicDelay);
  }
  else if ((StartupEnabled == 1) && (StartupEffectMode == 2)) {
   Serial.println("StartupEffect active. Begining the Effect #2.");
   Party();
   Serial.println("StartupEffectMode 2 executing. Please wait.");
   delay(PartyDelay);
   Party();
   Serial.println("StartupEffectMode 2 executing. Please wait.");
   delay(PartyDelay);
   Party();
   Serial.println("StartupEffectMode 2 executing. Please wait.");
   delay(PartyDelay);
   Party();
   Serial.println("StartupEffectMode 2 executing. Please wait.");
   delay(PartyDelay);
   Party();
   Serial.println("StartupEffectMode 2 executing. Please wait.");
   delay(PartyDelay);
   Party();
   delay(DynamicDelay);
  }
  else if ((StartupEnabled == 1) && (StartupEffectMode == 3)) {
   Serial.println("StartupEffect active. Begining the Effect #3.");
   AllOn();
   delay(DebuggingDelay);
   AllOn();
   Serial.println("StartupEffectMode 3 executing. Please wait.");
   delay(DebuggingDelay);
   Blink();
   delay(DebuggingDelay);
   Blink();
   delay(DebuggingDelay);
   Blink();
   delay(DynamicDelay);
  }
  else {
    delay(30);
    Serial.println("StartUp Effect disabled / Wrong configured. Exeting StartupEffectLoop now.");
  }
  Serial.println("STARTUP-EFFECT LOOP DONE. Returning to main program...");
}


void AllOn(){
  digitalWrite(ES, HIGH);
  delay(DebuggingDelay);
  digitalWrite(IST, HIGH);
  delay(DebuggingDelay);
  digitalWrite(WAR, HIGH);
  delay(DebuggingDelay);
  digitalWrite(JETZT, HIGH);
  delay(DebuggingDelay);
  digitalWrite(GLEICH, HIGH);
  delay(DebuggingDelay);
  digitalWrite(ZEHN_1, HIGH);
  delay(DebuggingDelay);
  digitalWrite(ZWANZIG, HIGH);
  delay(DebuggingDelay);
  digitalWrite(VIERTEL, HIGH);
  delay(DebuggingDelay);
  digitalWrite(HALB, HIGH);
  delay(DebuggingDelay);
  digitalWrite(FUENF_1, HIGH);
  delay(DebuggingDelay);
  digitalWrite(VOR, HIGH);
  delay(DebuggingDelay);
  digitalWrite(NACH, HIGH);
  delay(DebuggingDelay);
  digitalWrite(EIN, HIGH);
  delay(DebuggingDelay);
  digitalWrite(S, HIGH);
  delay(DebuggingDelay);
  digitalWrite(ZWEI, HIGH);
  delay(DebuggingDelay);
  digitalWrite(DREI, HIGH);
  delay(DebuggingDelay);
  digitalWrite(VIER, HIGH);
  delay(DebuggingDelay);
  digitalWrite(FUENF_2, HIGH);
  delay(DebuggingDelay);
  digitalWrite(SECHS, HIGH);
  delay(DebuggingDelay);
  digitalWrite(SIEBEN, HIGH);
  delay(DebuggingDelay);
  digitalWrite(ACHT, HIGH);
  delay(DebuggingDelay);
  digitalWrite(NEUN, HIGH);
  delay(DebuggingDelay);
  digitalWrite(ZEHN_2, HIGH);
  delay(DebuggingDelay);
  digitalWrite(ELF, HIGH);
  delay(DebuggingDelay);
  digitalWrite(ZWOELF, HIGH);
  delay(DebuggingDelay);
  digitalWrite(UHR, HIGH);
  delay(DebuggingDelay);
  //------------------------------------------
  digitalWrite(ES, LOW);
  delay(DebuggingDelay);
  digitalWrite(IST, LOW);
  delay(DebuggingDelay);
  digitalWrite(WAR, LOW);
  delay(DebuggingDelay);
  digitalWrite(JETZT, LOW);
  delay(DebuggingDelay);
  digitalWrite(GLEICH, LOW);
  delay(DebuggingDelay);
  digitalWrite(ZEHN_1, LOW);
  delay(DebuggingDelay);
  digitalWrite(ZWANZIG, LOW);
  delay(DebuggingDelay);
  digitalWrite(VIERTEL, LOW);
  delay(DebuggingDelay);
  digitalWrite(HALB, LOW);
  delay(DebuggingDelay);
  digitalWrite(FUENF_1, LOW);
  delay(DebuggingDelay);
  digitalWrite(VOR, LOW);
  delay(DebuggingDelay);
  digitalWrite(NACH, LOW);
  delay(DebuggingDelay);
  digitalWrite(EIN, LOW);
  delay(DebuggingDelay);
  digitalWrite(S, LOW);
  delay(DebuggingDelay);
  digitalWrite(ZWEI, LOW);
  delay(DebuggingDelay);
  digitalWrite(DREI, LOW);
  delay(DebuggingDelay);
  digitalWrite(VIER, LOW);
  delay(DebuggingDelay);
  digitalWrite(FUENF_2, LOW);
  delay(DebuggingDelay);
  digitalWrite(SECHS, LOW);
  delay(DebuggingDelay);
  digitalWrite(SIEBEN, LOW);
  delay(DebuggingDelay);
  digitalWrite(ACHT, LOW);
  delay(DebuggingDelay);
  digitalWrite(NEUN, LOW);
  delay(DebuggingDelay);
  digitalWrite(ZEHN_2, LOW);
  delay(DebuggingDelay);
  digitalWrite(ELF, LOW);
  delay(DebuggingDelay);
  digitalWrite(ZWOELF, LOW);
  delay(DebuggingDelay);
  digitalWrite(UHR, LOW);
}

void Blink() {
  
  digitalWrite(ES, HIGH);
  delay(DebuggingDelay);
  digitalWrite(IST, HIGH);
  delay(DebuggingDelay);
  digitalWrite(WAR, HIGH);
  delay(DebuggingDelay);
  digitalWrite(JETZT, HIGH);
  delay(DebuggingDelay);
  digitalWrite(GLEICH, HIGH);
  delay(DebuggingDelay);
  digitalWrite(ZEHN_1, HIGH);
  delay(DebuggingDelay);
  digitalWrite(ZWANZIG, HIGH);
  delay(DebuggingDelay);
  digitalWrite(VIERTEL, HIGH);
  delay(DebuggingDelay);
  digitalWrite(HALB, HIGH);
  delay(DebuggingDelay);
  digitalWrite(FUENF_1, HIGH);
  delay(DebuggingDelay);
  digitalWrite(VOR, HIGH);
  delay(DebuggingDelay);
  digitalWrite(NACH, HIGH);
  delay(DebuggingDelay);
  digitalWrite(EIN, HIGH);
  delay(DebuggingDelay);
  digitalWrite(S, HIGH);
  delay(DebuggingDelay);
  digitalWrite(ZWEI, HIGH);
  delay(DebuggingDelay);
  digitalWrite(DREI, HIGH);
  delay(DebuggingDelay);
  digitalWrite(ES, HIGH);
  delay(DebuggingDelay);
  digitalWrite(VIER, HIGH);
  delay(DebuggingDelay);
  digitalWrite(FUENF_2, HIGH);
  delay(DebuggingDelay);
  digitalWrite(SECHS, HIGH);
  delay(DebuggingDelay);
  digitalWrite(SIEBEN, HIGH);
  delay(DebuggingDelay);
  digitalWrite(ACHT, HIGH);
  delay(DebuggingDelay);
  digitalWrite(NEUN, HIGH);
  delay(DebuggingDelay);
  digitalWrite(ZEHN_2, HIGH);
  delay(DebuggingDelay);
  digitalWrite(ELF, HIGH);
  delay(DebuggingDelay);
  digitalWrite(ZWOELF, HIGH);
  delay(DebuggingDelay);
  digitalWrite(UHR, HIGH);
  delay(DebuggingDelay);
  digitalWrite(ES, LOW);
  delay(DebuggingDelay);
  digitalWrite(IST, LOW);
  delay(DebuggingDelay);
  digitalWrite(WAR, LOW);
  delay(DebuggingDelay);
  digitalWrite(JETZT, LOW);
  delay(DebuggingDelay);
  digitalWrite(GLEICH, LOW);
  delay(DebuggingDelay);
  digitalWrite(ZEHN_1, LOW);
  delay(DebuggingDelay);
  digitalWrite(ZWANZIG, LOW);
  delay(DebuggingDelay);
  digitalWrite(VIERTEL, LOW);
  delay(DebuggingDelay);
  digitalWrite(HALB, LOW);
  delay(DebuggingDelay);
  digitalWrite(FUENF_1, LOW);
  delay(DebuggingDelay);
  digitalWrite(VOR, LOW);
  delay(DebuggingDelay);
  digitalWrite(NACH, LOW);
  delay(DebuggingDelay);
  digitalWrite(EIN, LOW);
  delay(DebuggingDelay);
  digitalWrite(S, LOW);
  delay(DebuggingDelay);
  digitalWrite(ZWEI, LOW);
  delay(DebuggingDelay);
  digitalWrite(DREI, LOW);
  delay(DebuggingDelay);
  digitalWrite(ES, LOW);
  delay(DebuggingDelay);
  digitalWrite(VIER, LOW);
  delay(DebuggingDelay);
  digitalWrite(FUENF_2, LOW);
  delay(DebuggingDelay);
  digitalWrite(SECHS, LOW);
  delay(DebuggingDelay);
  digitalWrite(SIEBEN, LOW);
  delay(DebuggingDelay);
  digitalWrite(ACHT, LOW);
  delay(DebuggingDelay);
  digitalWrite(NEUN, LOW);
  delay(DebuggingDelay);
  digitalWrite(ZEHN_2, LOW);
  delay(DebuggingDelay);
  digitalWrite(ELF, LOW);
  delay(DebuggingDelay);
  digitalWrite(ZWOELF, LOW);
  delay(DebuggingDelay);
  digitalWrite(UHR, LOW);
  delay(DebuggingDelay);
}

void Party() {
  digitalWrite(ES, HIGH);
  delay(PartyDelay);
  digitalWrite(ES, LOW);
  digitalWrite(IST, HIGH);
  delay(PartyDelay);
  digitalWrite(IST, LOW);
  digitalWrite(WAR, HIGH);
  delay(PartyDelay);
  digitalWrite(WAR, LOW);
  digitalWrite(JETZT, HIGH);
  delay(PartyDelay);
  digitalWrite(JETZT, LOW);
  digitalWrite(GLEICH, HIGH);
  delay(PartyDelay);
  digitalWrite(GLEICH, LOW);
  digitalWrite(ZEHN_1, HIGH);
  delay(PartyDelay);
  digitalWrite(ZWANZIG, HIGH);
  digitalWrite(ZEHN_1, LOW);
  delay(PartyDelay);
  digitalWrite(ZWANZIG, LOW);
  digitalWrite(VIERTEL, HIGH);
  delay(PartyDelay);
  digitalWrite(VIERTEL, LOW);
  digitalWrite(HALB, HIGH);
  delay(PartyDelay);
  digitalWrite(HALB, LOW);
  digitalWrite(FUENF_1, HIGH);
  delay(PartyDelay);
  digitalWrite(FUENF_1, LOW);
  digitalWrite(VOR, HIGH);
  delay(PartyDelay);
  digitalWrite(VOR, LOW);
  digitalWrite(NACH, HIGH);
  delay(PartyDelay);
  digitalWrite(NACH, LOW);
  digitalWrite(EIN, HIGH);
  delay(PartyDelay);
  digitalWrite(S, HIGH);
  delay(PartyDelay);
  digitalWrite(EIN, LOW);
  digitalWrite(S, LOW);
  digitalWrite(ZWEI, HIGH);
  delay(PartyDelay);
  digitalWrite(ZWEI, LOW);
  digitalWrite(DREI, HIGH);
  delay(PartyDelay);
  digitalWrite(DREI, LOW);
  digitalWrite(VIER, HIGH);
  delay(PartyDelay);
  digitalWrite(VIER, LOW);
  digitalWrite(FUENF_2, HIGH);
  delay(PartyDelay);
  digitalWrite(FUENF_2, LOW);
  digitalWrite(SECHS, HIGH);
  delay(PartyDelay);
  digitalWrite(SECHS, LOW);
  digitalWrite(SIEBEN, HIGH);
  delay(PartyDelay);
  digitalWrite(SIEBEN, LOW);
  digitalWrite(ACHT, HIGH);
  delay(PartyDelay);
  digitalWrite(ACHT, LOW);
  digitalWrite(NEUN, HIGH);
  delay(PartyDelay);
  digitalWrite(NEUN, LOW);
  digitalWrite(ZEHN_2, HIGH);
  delay(PartyDelay);
  digitalWrite(ZEHN_2, LOW);
  digitalWrite(ELF, HIGH);
  delay(PartyDelay);
  digitalWrite(ELF, LOW);
  digitalWrite(ZWOELF, HIGH);
  delay(PartyDelay);
  digitalWrite(ZWOELF, LOW);
  digitalWrite(UHR, HIGH);
  delay(PartyDelay);
  digitalWrite(UHR, LOW);
}

void DynamicVoid() {
  digitalWrite(ES, HIGH);
  delay(PartyDelay);
  digitalWrite(ES, LOW);
  digitalWrite(IST, HIGH);
  delay(DynamicDelay);
  digitalWrite(IST, LOW);
  digitalWrite(WAR, HIGH);
  delay(DynamicDelay);
  digitalWrite(WAR, LOW);
  digitalWrite(JETZT, HIGH);
  delay(DynamicDelay);
  digitalWrite(JETZT, LOW);
  digitalWrite(GLEICH, HIGH);
  delay(DynamicDelay);
  digitalWrite(GLEICH, LOW);
  digitalWrite(ZEHN_1, HIGH);
  delay(DynamicDelay);
  digitalWrite(ZWANZIG, HIGH);
  digitalWrite(ZEHN_1, LOW);
  delay(DynamicDelay);
  digitalWrite(ZWANZIG, LOW);
  digitalWrite(VIERTEL, HIGH);
  delay(DynamicDelay);
  digitalWrite(VIERTEL, LOW);
  digitalWrite(HALB, HIGH);
  delay(DynamicDelay);
  digitalWrite(HALB, LOW);
  digitalWrite(FUENF_1, HIGH);
  delay(DynamicDelay);
  digitalWrite(FUENF_1, LOW);
  digitalWrite(VOR, HIGH);
  delay(DynamicDelay);
  digitalWrite(VOR, LOW);
  digitalWrite(NACH, HIGH);
  delay(DynamicDelay);
  digitalWrite(NACH, LOW);
  digitalWrite(EIN, HIGH);
  delay(DynamicDelay);
  digitalWrite(S, HIGH);
  delay(DynamicDelay);
  digitalWrite(EIN, LOW);
  digitalWrite(S, LOW);
  digitalWrite(ZWEI, HIGH);
  delay(DynamicDelay);
  digitalWrite(ZWEI, LOW);
  digitalWrite(DREI, HIGH);
  delay(DynamicDelay);
  digitalWrite(DREI, LOW);
  digitalWrite(VIER, HIGH);
  delay(DynamicDelay);
  digitalWrite(VIER, LOW);
  digitalWrite(FUENF_2, HIGH);
  delay(DynamicDelay);
  digitalWrite(FUENF_2, LOW);
  digitalWrite(SECHS, HIGH);
  delay(DynamicDelay);
  digitalWrite(SECHS, LOW);
  digitalWrite(SIEBEN, HIGH);
  delay(DynamicDelay);
  digitalWrite(SIEBEN, LOW);
  digitalWrite(ACHT, HIGH);
  delay(DynamicDelay);
  digitalWrite(ACHT, LOW);
  digitalWrite(NEUN, HIGH);
  delay(DynamicDelay);
  digitalWrite(NEUN, LOW);
  digitalWrite(ZEHN_2, HIGH);
  delay(DynamicDelay);
  digitalWrite(ZEHN_2, LOW);
  digitalWrite(ELF, HIGH);
  delay(DynamicDelay);
  digitalWrite(ELF, LOW);
  digitalWrite(ZWOELF, HIGH);
  delay(DynamicDelay);
  digitalWrite(ZWOELF, LOW);
  digitalWrite(UHR, HIGH);
  delay(DynamicDelay);
  digitalWrite(UHR, LOW);
}

