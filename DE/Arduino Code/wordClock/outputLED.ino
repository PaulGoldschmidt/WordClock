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

void setLED(int stunde, int minute)
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

