/*  everything that happens in the normal operation of the smartwatch happens here. this is kind of the user-interface part of the code.
*/
bool newNotificationData = false;
bool dontSleep = false;
int drawInterval = 1000;
unsigned long lastDraw = 0;

void MainLoop()
{
  initBLE();
  while (lastTouchTime + screenOnTime > millis()) {
    if (!newNotificationData && pRemoteCharacteristic) {
      updateNotificationData();
      newNotificationData = true;
    }
    if (touchDetected) {
      //handleTouch() operates in a similar manner to the MainLoop()
      //and simply switches to the correct touch handler
      handleTouch();
    } else {
      if (lastDraw + drawInterval < millis()) {
        switch (currentPage)
        {
          case HOME:
            dontSleep = false;
            drawHome();
            break;
          default:
            currentPage = HOME;
        }
        lastDraw = millis();
      }
    }
  }
}
