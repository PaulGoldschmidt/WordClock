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

void setLED(int localStunde, int localMin)
{
  if (localMin == 0)
  {
    OFF();
    digitalWrite(IST, HIGH);
    digitalWrite(JETZT, HIGH);
    digitalWrite(UHR, HIGH);
  }
  else if ((localMin > 0) && (localMin <= 3))
  {
    OFF();
    digitalWrite(WAR, HIGH);
    digitalWrite(UHR, HIGH);
  }
  else if ((localMin > 3) && (localMin < 5))
  {
    OFF();
    digitalWrite(IST, HIGH);
    digitalWrite(GLEICH, HIGH);
    digitalWrite(FUENF_1, HIGH);
  }
  else if (localMin == 5)
  {
    OFF();
    digitalWrite(IST, HIGH);
    digitalWrite(JETZT, HIGH);
    digitalWrite(FUENF_1, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if ((localMin > 5) && (localMin <= 7))
  {
    OFF();
    digitalWrite(WAR, HIGH);
    digitalWrite(FUENF_1, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if ((localMin > 7) && (localMin < 10))
  {
    OFF();
    digitalWrite(IST, HIGH);
    digitalWrite(GLEICH, HIGH);
    digitalWrite(ZEHN_2, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if (localMin == 10)
  {
    OFF();
    digitalWrite(IST, HIGH);
    digitalWrite(JETZT, HIGH);
    digitalWrite(ZEHN_1, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if ((localMin > 10) && (localMin <= 12))
  {
    OFF();
    digitalWrite(WAR, HIGH);
    digitalWrite(ZEHN_1, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if ((localMin > 12) && (localMin < 15))
  {
    OFF();
    digitalWrite(IST, HIGH);
    digitalWrite(GLEICH, HIGH);
    digitalWrite(VIERTEL, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if (localMin == 15)
  {
    OFF();
    digitalWrite(IST, HIGH);
    digitalWrite(JETZT, HIGH);
    digitalWrite(VIERTEL, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if ((localMin > 15) && (localMin <= 17))
  {
    OFF();
    digitalWrite(WAR, HIGH);
    digitalWrite(VIERTEL, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if ((localMin > 17) && (localMin < 20))
  {
    OFF();
    digitalWrite(IST, HIGH);
    digitalWrite(GLEICH, HIGH);
    digitalWrite(ZWANZIG, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if (localMin == 20)
  {
    OFF();
    digitalWrite(IST, HIGH);
    digitalWrite(JETZT, HIGH);
    digitalWrite(ZWANZIG, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if ((localMin > 20) && (localMin < 25))
  {
    OFF();
    digitalWrite(WAR, HIGH);
    digitalWrite(ZWANZIG, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if ((localMin >= 25) && (localMin < 30))
  {
    OFF();
    digitalWrite(IST, HIGH);
    digitalWrite(GLEICH, HIGH);
    digitalWrite(HALB, HIGH);
  }
  else if (localMin == 30)
  {
    OFF();
    digitalWrite(IST, HIGH);
    digitalWrite(JETZT, HIGH);
    digitalWrite(HALB, HIGH);
  }
  else if ((localMin > 30) && (localMin <= 34))
  {
    OFF();
    digitalWrite(WAR, HIGH);
    digitalWrite(HALB, HIGH);
  }
  else if ((localMin >= 35) && (localMin < 40))
  {
    OFF();
    digitalWrite(IST, HIGH);
    digitalWrite(GLEICH, HIGH);
    digitalWrite(ZWANZIG, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if (localMin == 40)
  {
    OFF();
    digitalWrite(IST, HIGH);
    digitalWrite(JETZT, HIGH);
    digitalWrite(ZWANZIG, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if ((localMin > 40) && (localMin <= 42))
  {
    OFF();
    digitalWrite(WAR, HIGH);
    digitalWrite(ZWANZIG, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if ((localMin > 42) && (localMin < 45))
  {
    OFF();
    digitalWrite(IST, HIGH);
    digitalWrite(GLEICH, HIGH);
    digitalWrite(VIERTEL, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if (localMin == 45)
  {
    OFF();
    digitalWrite(IST, HIGH);
    digitalWrite(JETZT, HIGH);
    digitalWrite(VIERTEL, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if ((localMin > 45) && (localMin < 47))
  {
    OFF();
    digitalWrite(WAR, HIGH);
    digitalWrite(VIERTEL, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if ((localMin >= 47) && (localMin < 50))
  {
    OFF();
    digitalWrite(IST, HIGH);
    digitalWrite(GLEICH, HIGH);
    digitalWrite(ZEHN_1, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if (localMin == 50)
  {
    OFF();
    digitalWrite(IST, HIGH);
    digitalWrite(JETZT, HIGH);
    digitalWrite(ZEHN_1, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if ((localMin > 50) && (localMin < 52))
  {
    OFF();
    digitalWrite(WAR, HIGH);
    digitalWrite(ZEHN_1, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if ((localMin >= 52) && (localMin < 55))
  {
    OFF();
    digitalWrite(IST, HIGH);
    digitalWrite(GLEICH, HIGH);
    digitalWrite(FUENF_1, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if (localMin == 55)
  {
    OFF();
    digitalWrite(IST, HIGH);
    digitalWrite(JETZT, HIGH);
    digitalWrite(FUENF_1, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if ((localMin > 55) && (localMin < 57))
  {
    OFF();
    digitalWrite(WAR, HIGH);
    digitalWrite(FUENF_1, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if ((localMin >= 57) && (localMin < 59))
  {
    OFF();
    digitalWrite(IST, HIGH);
    digitalWrite(GLEICH, HIGH);
    digitalWrite(UHR, HIGH);
  }
  //
  //----------------------------------------------------------------------------------------------
  //
  if ((localStunde == 1) || (localStunde == 13))
  {
    digitalWrite(EIN, HIGH);
  }
  else if ((localStunde == 2) || (localStunde == 14))
  {
    digitalWrite(ZWEI, HIGH);
  }
  else if ((localStunde == 3) || (localStunde == 15))
  {
    digitalWrite(DREI, HIGH);
  }
  else if ((localStunde == 4) || (localStunde == 16))
  {
    digitalWrite(VIER, HIGH);
  }
  else if ((localStunde == 5) || (localStunde == 17))
  {
    digitalWrite(FUENF_2, HIGH);
  }
  else if ((localStunde == 6) || (localStunde == 18))
  {
    digitalWrite(SECHS, HIGH);
  }
  else if ((localStunde == 7) || (localStunde == 19))
  {
    digitalWrite(SIEBEN, HIGH);
  }
  else if ((localStunde == 8) || (localStunde == 20))
  {
    digitalWrite(ACHT, HIGH);
  }
  else if ((localStunde == 9) || (localStunde == 21))
  {
    digitalWrite(NEUN, HIGH);
  }
  else if ((localStunde == 10) || (localStunde == 22))
  {
    digitalWrite(ZEHN_2, HIGH);
  }
  else if ((localStunde == 11) || (localStunde == 23))
  {
    digitalWrite(ELF, HIGH);
  }
  else if ((localStunde == 12) || (localStunde == 0))
  {
    digitalWrite(ZWOELF, HIGH);
  }
}

