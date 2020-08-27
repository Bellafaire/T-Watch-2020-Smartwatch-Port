/*  everything that happens in the normal operation of the smartwatch happens here. this is kind of the user-interface part of the code.
*/
bool newNotificationData = false;
bool dontSleep = false;
bool redrawHome = true;

void MainLoop()
{
  initBLE();
  while (lastTouchTime + screenOnTime > millis()) {
    if (!newNotificationData && pRemoteCharacteristic) {
      updateNotificationData();
      newNotificationData = true;
      redrawHome = true;
    }
    if (touchDetected) {
      //handleTouch() operates in a similar manner to the MainLoop()
      //and simply switches to the correct touch handler
      handleTouch();
    } else {
      switch (currentPage)
      {
        case HOME:
          dontSleep = false;
          if (redrawHome) {
            drawHome();
            redrawHome = false;
          }
          break;
        default:
          currentPage = HOME;
      }
    }
  }
  digitalWrite(LCD_LED, LOW);
}
