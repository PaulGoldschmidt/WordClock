void initLED() {
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
  analogWrite(MOSFET, MOSFET_Max);
  for (int i = 22; i < 48; i++)
  {
    Serial.println(i);
    digitalWrite(i, HIGH);
    delay(500);
    digitalWrite(i, LOW);
  }
}
// Nachtabschaltung, MOSFET Komplett Aus
void NACHT() {
  analogWrite(MOSFET, NightBrightniss);
}
void AUS() {
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
}

void setLED(int localStunde, int localMin)
{
  if (localMin == 0)
  {
    AUS();
    digitalWrite(IST, HIGH);
    digitalWrite(JETZT, HIGH);
    digitalWrite(UHR, HIGH);
  }
  else if ((localMin > 0) && (localMin <= 3))
  {
    AUS();
    digitalWrite(WAR, HIGH);
    digitalWrite(UHR, HIGH);
  }
  else if ((localMin > 3) && (localMin < 5))
  {
    AUS();
    digitalWrite(IST, HIGH);
    digitalWrite(GLEICH, HIGH);
    digitalWrite(FUENF_1, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if (localMin == 5)
  {
    AUS();
    digitalWrite(IST, HIGH);
    digitalWrite(JETZT, HIGH);
    digitalWrite(FUENF_1, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if ((localMin > 5) && (localMin <= 7))
  {
    AUS();
    digitalWrite(WAR, HIGH);
    digitalWrite(FUENF_1, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if ((localMin > 7) && (localMin < 10))
  {
    AUS();
    digitalWrite(IST, HIGH);
    digitalWrite(GLEICH, HIGH);
    digitalWrite(ZEHN_1, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if (localMin == 10)
  {
    AUS();
    digitalWrite(IST, HIGH);
    digitalWrite(JETZT, HIGH);
    digitalWrite(ZEHN_1, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if ((localMin > 10) && (localMin <= 12))
  {
    AUS();
    digitalWrite(WAR, HIGH);
    digitalWrite(ZEHN_1, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if ((localMin > 12) && (localMin < 15))
  {
    AUS();
    digitalWrite(IST, HIGH);
    digitalWrite(GLEICH, HIGH);
    digitalWrite(VIERTEL, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if (localMin == 15)
  {
    AUS();
    digitalWrite(IST, HIGH);
    digitalWrite(JETZT, HIGH);
    digitalWrite(VIERTEL, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if ((localMin > 15) && (localMin <= 17))
  {
    AUS();
    digitalWrite(WAR, HIGH);
    digitalWrite(VIERTEL, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if ((localMin > 17) && (localMin < 20))
  {
    AUS();
    digitalWrite(IST, HIGH);
    digitalWrite(GLEICH, HIGH);
    digitalWrite(ZWANZIG, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if (localMin == 20)
  {
    AUS();
    digitalWrite(IST, HIGH);
    digitalWrite(JETZT, HIGH);
    digitalWrite(ZWANZIG, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if ((localMin > 20) && (localMin < 25))
  {
    AUS();
    digitalWrite(WAR, HIGH);
    digitalWrite(ZWANZIG, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if ((localMin >= 25) && (localMin < 30))
  {
    AUS();
    digitalWrite(IST, HIGH);
    digitalWrite(GLEICH, HIGH);
    digitalWrite(HALB, HIGH);
  }
  else if (localMin == 30)
  {
    AUS();
    digitalWrite(IST, HIGH);
    digitalWrite(JETZT, HIGH);
    digitalWrite(HALB, HIGH);
  }
  else if ((localMin > 30) && (localMin <= 34))
  {
    AUS();
    digitalWrite(WAR, HIGH);
    digitalWrite(HALB, HIGH);
  }
  else if ((localMin >= 35) && (localMin < 40))
  {
    AUS();
    digitalWrite(IST, HIGH);
    digitalWrite(GLEICH, HIGH);
    digitalWrite(ZWANZIG, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if (localMin == 40)
  {
    AUS();
    digitalWrite(IST, HIGH);
    digitalWrite(JETZT, HIGH);
    digitalWrite(ZWANZIG, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if ((localMin > 40) && (localMin <= 42))
  {
    AUS();
    digitalWrite(WAR, HIGH);
    digitalWrite(ZWANZIG, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if ((localMin > 42) && (localMin < 45))
  {
    AUS();
    digitalWrite(IST, HIGH);
    digitalWrite(GLEICH, HIGH);
    digitalWrite(VIERTEL, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if (localMin == 45)
  {
    AUS();
    digitalWrite(IST, HIGH);
    digitalWrite(JETZT, HIGH);
    digitalWrite(VIERTEL, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if ((localMin > 45) && (localMin < 47))
  {
    AUS();
    digitalWrite(WAR, HIGH);
    digitalWrite(VIERTEL, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if ((localMin >= 47) && (localMin < 50))
  {
    AUS();
    digitalWrite(IST, HIGH);
    digitalWrite(GLEICH, HIGH);
    digitalWrite(ZEHN_1, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if (localMin == 50)
  {
    AUS();
    digitalWrite(IST, HIGH);
    digitalWrite(JETZT, HIGH);
    digitalWrite(ZEHN_1, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if ((localMin > 50) && (localMin < 52))
  {
    AUS();
    digitalWrite(WAR, HIGH);
    digitalWrite(ZEHN_1, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if ((localMin >= 52) && (localMin < 55))
  {
    AUS();
    digitalWrite(IST, HIGH);
    digitalWrite(GLEICH, HIGH);
    digitalWrite(FUENF_1, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if (localMin == 55)
  {
    AUS();
    digitalWrite(IST, HIGH);
    digitalWrite(JETZT, HIGH);
    digitalWrite(FUENF_1, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if ((localMin > 55) && (localMin < 57))
  {
    AUS();
    digitalWrite(WAR, HIGH);
    digitalWrite(FUENF_1, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if ((localMin >= 57) && (localMin < 59))
  {
    AUS();
    digitalWrite(IST, HIGH);
    digitalWrite(GLEICH, HIGH);
    digitalWrite(UHR, HIGH);
  }
  //
  //----------------------------------------------------------------------------------------------
  //
  if ((localStunde == 1) || (localStunde == 13))
  {
    if (localMin >= 25)
    {
      digitalWrite(ZWEI, HIGH);
    }
    else
    {
      digitalWrite(EIN, HIGH);
    }
  }
  else if ((localStunde == 2) || (localStunde == 14))
  {
    if (localMin >= 25)
    {
      digitalWrite(DREI, HIGH);
    }
    else
    {
      digitalWrite(ZWEI, HIGH);
    }
  }
  else if ((localStunde == 3) || (localStunde == 15))
  {
    if (localMin >= 25)
    {
      digitalWrite(VIER, HIGH);
    }
    else
    {
      digitalWrite(DREI, HIGH);
    }
  }
  else if ((localStunde == 4) || (localStunde == 16))
  {
    if (localMin >= 25)
    {
      digitalWrite(FUENF_2, HIGH);
    }
    else
    {
      digitalWrite(VIER, HIGH);
    }
  }
  else if ((localStunde == 5) || (localStunde == 17))
  {
    if (localMin >= 25)
    {
      digitalWrite(SECHS, HIGH);
    }
    else
    {
      digitalWrite(FUENF_2, HIGH);
    }
  }
  else if ((localStunde == 6) || (localStunde == 18))
  {
    if (localMin >= 25)
    {
      digitalWrite(SIEBEN, HIGH);
    }
    else
    {
      digitalWrite(SECHS, HIGH);
    }
  }
  else if ((localStunde == 7) || (localStunde == 19))
  {
    if (localMin >= 25)
    {
      digitalWrite(ACHT, HIGH);
    }
    else
    {
      digitalWrite(SIEBEN, HIGH);
    }
  }
  else if ((localStunde == 8) || (localStunde == 20))
  {
    if (localMin >= 25)
    {
      digitalWrite(NEUN, HIGH);
    }
    else
    {
      digitalWrite(ACHT, HIGH);
    }
  }
  else if ((localStunde == 9) || (localStunde == 21))
  {
    if (localMin >= 25)
    {
      digitalWrite(ZEHN_2, HIGH);
    }
    else
    {
      digitalWrite(NEUN, HIGH);
    }
  }
  else if ((localStunde == 10) || (localStunde == 22))
  {
    if (localMin >= 25)
    {
      digitalWrite(ELF, HIGH);
    }
    else
    {
      digitalWrite(ZEHN_2, HIGH);
    }
  }
  else if ((localStunde == 11) || (localStunde == 23))
  {
    if (localMin >= 25)
    {
      digitalWrite(ZWOELF, HIGH);
    }
    else
    {
      digitalWrite(ELF, HIGH);
    }
  }
  else if ((localStunde == 12) || (localStunde == 0))
  {
    if (localMin >= 25)
    {
      digitalWrite(EIN, HIGH);
    }
    else
    {
      digitalWrite(ZWOELF, HIGH);
    }
  }
}

