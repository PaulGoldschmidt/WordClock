
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
  delay(50);
}

void OFF() {
  delay(500);
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

void NightShutdown() {
  Serial.println("Night mode activated: set LED to night brighness!");
  digitalWrite(MOSFET, NightBrightness);
}

void setLED(int localStunde, int localMin)
{
  if (localMin == 0)
  {
    OFF();
    Serial.println("IST JETZT UHR");
    digitalWrite(IST, HIGH);
    digitalWrite(JETZT, HIGH);
    digitalWrite(UHR, HIGH);
  }
  else if ((localMin > 0) && (localMin <= 3))
  {
    OFF();
    Serial.println("WAR UHR");
    digitalWrite(WAR, HIGH);
    digitalWrite(UHR, HIGH);
  }
  else if ((localMin > 3) && (localMin < 5))
  {
    OFF();
    Serial.println("IST GLEICH FÜNF NACH");
    digitalWrite(IST, HIGH);
    digitalWrite(GLEICH, HIGH);
    digitalWrite(FUENF_1, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if (localMin == 5)
  {
    OFF();
    Serial.println("IST JETZT FÜNF NACH");
    digitalWrite(IST, HIGH);
    digitalWrite(JETZT, HIGH);
    digitalWrite(FUENF_1, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if ((localMin > 5) && (localMin <= 7))
  {
    OFF();
    Serial.println("WAR FÜNF NACH");
    digitalWrite(WAR, HIGH);
    digitalWrite(FUENF_1, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if ((localMin > 7) && (localMin < 10))
  {
    OFF();
    Serial.println("IST GLEICH ZEHN NACH");
    digitalWrite(IST, HIGH);
    digitalWrite(GLEICH, HIGH);
    digitalWrite(ZEHN_1, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if (localMin == 10)
  {
    OFF();
    Serial.println("IST JETZT ZEHN NACH");
    digitalWrite(IST, HIGH);
    digitalWrite(JETZT, HIGH);
    digitalWrite(ZEHN_1, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if ((localMin > 10) && (localMin <= 12))
  {
    OFF();
    Serial.println("WAR ZEHN NACH");
    digitalWrite(WAR, HIGH);
    digitalWrite(ZEHN_1, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if ((localMin > 12) && (localMin < 15))
  {
    OFF();
    Serial.println("IST GLEICH VIERTEL NACH");
    digitalWrite(IST, HIGH);
    digitalWrite(GLEICH, HIGH);
    digitalWrite(VIERTEL, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if (localMin == 15)
  {
    OFF();
    Serial.println("IST JETZT VIERTEL NACH");
    digitalWrite(IST, HIGH);
    digitalWrite(JETZT, HIGH);
    digitalWrite(VIERTEL, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if ((localMin > 15) && (localMin <= 17))
  {
    OFF();
    Serial.println("WAR VIERTEL NACH");
    digitalWrite(WAR, HIGH);
    digitalWrite(VIERTEL, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if ((localMin > 17) && (localMin < 20))
  {
    OFF();
    Serial.println("IST GLEICH ZWANZIG NACH");
    digitalWrite(IST, HIGH);
    digitalWrite(GLEICH, HIGH);
    digitalWrite(ZWANZIG, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if (localMin == 20)
  {
    OFF();
    Serial.println("IST JETZT ZWANZIG NACH");
    digitalWrite(IST, HIGH);
    digitalWrite(JETZT, HIGH);
    digitalWrite(ZWANZIG, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if ((localMin > 20) && (localMin < 25))
  {
    OFF();
    Serial.println("WAR ZWANZIG NACH");
    digitalWrite(WAR, HIGH);
    digitalWrite(ZWANZIG, HIGH);
    digitalWrite(NACH, HIGH);
  }
  else if ((localMin >= 25) && (localMin < 30))
  {
    OFF();
    Serial.println("IST GLEICH HALB");
    digitalWrite(IST, HIGH);
    digitalWrite(GLEICH, HIGH);
    digitalWrite(HALB, HIGH);
  }
  else if (localMin == 30)
  {
    OFF();
    Serial.println("IST JETZT HALB");
    digitalWrite(IST, HIGH);
    digitalWrite(JETZT, HIGH);
    digitalWrite(HALB, HIGH);
  }
  else if ((localMin > 30) && (localMin <= 34))
  {
    OFF();
    Serial.println("WAR HALB");
    digitalWrite(WAR, HIGH);
    digitalWrite(HALB, HIGH);
  }
  else if ((localMin >= 35) && (localMin < 40))
  {
    OFF();
    Serial.println("IST GLEICH ZWANZIG VOR");
    digitalWrite(IST, HIGH);
    digitalWrite(GLEICH, HIGH);
    digitalWrite(ZWANZIG, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if (localMin == 40)
  {
    OFF();
    Serial.println("IST JETZT ZWANZIG VOR");
    digitalWrite(IST, HIGH);
    digitalWrite(JETZT, HIGH);
    digitalWrite(ZWANZIG, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if ((localMin > 40) && (localMin <= 42))
  {
    OFF();
    Serial.println("WAR ZWANZIG VOR");
    digitalWrite(WAR, HIGH);
    digitalWrite(ZWANZIG, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if ((localMin > 42) && (localMin < 45))
  {
    OFF();
    Serial.println("IST GLEICH VIERTEL VOR");
    digitalWrite(IST, HIGH);
    digitalWrite(GLEICH, HIGH);
    digitalWrite(VIERTEL, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if (localMin == 45)
  {
    OFF();
    Serial.println("IST JETZT VIERTEL VOR");
    digitalWrite(IST, HIGH);
    digitalWrite(JETZT, HIGH);
    digitalWrite(VIERTEL, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if ((localMin > 45) && (localMin < 47))
  {
    OFF();
    Serial.println("WAR VIERTEL VOR");
    digitalWrite(WAR, HIGH);
    digitalWrite(VIERTEL, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if ((localMin >= 47) && (localMin < 50))
  {
    OFF();
    Serial.println("IST GLEICH ZEHN VOR");
    digitalWrite(IST, HIGH);
    digitalWrite(GLEICH, HIGH);
    digitalWrite(ZEHN_1, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if (localMin == 50)
  {
    OFF();
    Serial.println("IST JETZT ZEHN VOR");
    digitalWrite(IST, HIGH);
    digitalWrite(JETZT, HIGH);
    digitalWrite(ZEHN_1, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if ((localMin > 50) && (localMin < 55))
  {
    OFF();
    Serial.println("WAR ZEHN VOR");
    digitalWrite(WAR, HIGH);
    digitalWrite(ZEHN_1, HIGH);
    digitalWrite(VOR, HIGH);
  }
  else if ((localMin >= 55) && (localMin < 59))
  {
    OFF();
    Serial.println("IST GLEICH");
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
