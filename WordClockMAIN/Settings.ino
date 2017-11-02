//settings.ino
int SecondsTillTimeout = 0;

void DCF77Process() {
  if (DCFAvailable == 1) {
    delay(50);
    DCF77Init();
    delay(50);
    getSignal();
    delay(50);
  }
  else {
   delay(50);
  }
}


