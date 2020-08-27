void initLCD() {
    ttgo->openBL(); // Turn on the backlight
    }

//attach IRQ interrupt
void initTouch()
{
  //dummy read the touch controller, bits 2 and 3 determine the power down state, 00 enables touch IRQ and puts the device into power down
  struct point p;

  attachInterrupt(TOUCH_IRQ, TOUCH_ISR, FALLING);
}

int rapidTouchCount = 0;

void IRAM_ATTR TOUCH_ISR()
{
  printDebug("Touch detected from interrupt");

  if (millis() - lastTouchTime < 200) {
    rapidTouchCount++;
    printDebug("rapidTouchCount: " + String(rapidTouchCount));

    if (rapidTouchCount > 50) {
#ifdef DEBUG
      Serial.println("**** Rapid Touch shutdown registered ****");
      Serial.flush();
#endif
      deviceSleep();
    }
  } else {
    rapidTouchCount = 0;
  }
  lastTouchTime = millis();
  touchDetected = true;
  // handleTouch();
}

//reads touch from the touch controller and enables the Touch interrupt pin
struct point readTouch()
{
  struct point p;
  if (!digitalRead(TOUCH_IRQ))
  {
    p.xPos = -1;
    p.yPos = -1;
  }
  else
  {
    p.xPos = -1;
    p.yPos = -1;
  }
  return p;
}

//All touch handling for individual pages are switched here
void handleTouch()
{
  if (touchDetected)
  {
    switch (currentPage)
    {
      case HOME:
        HomeTouchHandler(readTouch());
        break;
      case SETTINGS:
        //        SettingsTouchHandler(readTouch());
        break;
      case NOTIFICATIONS:
        //        NotificationsTouchHandler(readTouch());
        break;
      case CALCULATOR:
        //        calculatorTouchHandler(readTouch());
        break;
      default:
        break;
    }
    touchDetected = false;
  }
}

int getBatteryPercentage() {
return ttgo->power->getBattPercentage();
}

void drawFrameBuffer() {
  //  for (int x = 0; x < SCREEN_WIDTH; x++) {
  //    for (int y = 0; y < SCREEN_HEIGHT; y++) {
  //      ttgo->tft->drawPixel(x, y, ttgo->tft->getPixel(x, y));
  //    }
  //  }
//  ttgo->tft->drawRGBBitmap (0, 0, frameBuffer -> getBuffer (), SCREEN_WIDTH, SCREEN_HEIGHT);
}
