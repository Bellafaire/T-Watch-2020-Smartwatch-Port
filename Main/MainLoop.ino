/*  everything that happens in the normal operation of the smartwatch happens here. this is kind of the user-interface part of the code.
*/
bool newNotificationData = false;
bool dontSleep = false;
int previousPage = 0;


void MainLoop()
{
  initBLE();
  while (lastTouchTime + screenOnTime > millis()) {
    if (!newNotificationData && pRemoteCharacteristic) {
      updateNotificationData();
      newNotificationData = true;
      drawHome();
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
          if (previousPage != currentPage) {
            drawHome();
          }
          break;
        case NOTIFICATIONS:
          dontSleep = false;
          if (previousPage != currentPage) {
            drawNotifications();
          }

          break;
        default:
          currentPage = HOME;
      }
      previousPage = currentPage;
    }
  }
}
