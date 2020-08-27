/* Home Page of the watch, this is where most of the 
 *  important information is displayed to the user.  
 */

bool firstHomeSwitch = true;

double songNameScrollPosition = 0;

long lastSongCheck = 0;
#define SONG_CHECK_INTERVAL 500 //how many miliseconds between checking the current song

void writeNotifications() {
  ttgo->tft->setCursor(0,60);
  ttgo->tft->setTextSize(2);
  ttgo->tft->setTextWrap(false);

  int lines = getNotificationLines();
  ttgo->tft->println("Notifications");

  if (lines > 1) {
    for (int a = 0; a < lines - 1; a++) {
      ttgo->tft->println(parseFromNotifications(a, 0));
    }
  } else {
    ttgo->tft->println("No Notifications");
  }
  ttgo->tft->setTextWrap(true);

#ifdef SHOW_LAST_NOTIFICATION_TIME
  ttgo->tft->setTextColor(GRAYED);
  ttgo->tft->setCursor(2, SCREEN_HEIGHT - 20);
  ttgo->tft->println(parseFromNotifications(lines - 1, 0));
  ttgo->tft->setTextColor(INTERFACE_COLOR);
#endif
  ttgo->tft->setTextSize(1);
}

int circlePosition = 0;

void drawHome()
{

   ttgo->tft->fillScreen(TFT_BLACK);

  //check if we've got a song playing on spotify at the moment, but only once every SONG_CHECK_INTERVAL miliseconds
  if (lastSongCheck + SONG_CHECK_INTERVAL < millis()) {
    isPlaying = sendBLE("/isPlaying", true).substring(0, 4).equals("true");
    if (isPlaying) {
      String song = sendBLE("/currentSong", true);
      for (int a = 0; a < SONG_NAME_BUFFER_SIZE; a++) {
        if (song[a] == '*') {
          songName[a] = ' ';
        } else {
          songName[a] = song[a];
        }
      }
    }
    lastSongCheck = millis();
  }

  //it's here if you want it
  //    drawCircularAnimation1(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 2 + 30);
  //  drawArc(80, 60, 50, 10, circlePosition++, 30,  0x0011);

  ttgo->tft->drawFastHLine(0, 5, ttgo->tft->width(), INTERFACE_COLOR);
  drawTime(60, 15, 3);
  ttgo->tft->drawLine(0, 50, 10, 50, INTERFACE_COLOR);
  ttgo->tft->drawLine(SCREEN_WIDTH, 50, SCREEN_WIDTH - 10, 50, INTERFACE_COLOR);
  drawDateCentered(50, 1);
  ttgo->tft->setTextSize(1);
  ttgo->tft->setCursor(0, 40);

  if (connected) {
    ttgo->tft-> fillRect(SCREEN_WIDTH - 3, 0, 3, 3, 0b00111111 << 5); //if connected draw a green square in the corner
  } else if (myDevice) {
    ttgo->tft-> fillRect(SCREEN_WIDTH - 3, 0, 3, 3, 0b00011111 << 11); //Show a blue square if we found the device
  } else {
    ttgo->tft-> fillRect(SCREEN_WIDTH - 3, 0, 3, 3, 0b00011111 ); //else draw red square
  }

  writeNotifications() ;

  if (isPlaying) {
    ttgo->tft->setCursor(0, SCREEN_HEIGHT - 10);
    if (songNameScrollPosition + 24 < String(songName).length()) {
      songNameScrollPosition += 0.1;
    } else {
      songNameScrollPosition = 0;
    }

    ttgo->tft->setTextWrap(false);
    ttgo->tft->println(String(songName).substring(round(songNameScrollPosition)));
    ttgo->tft->setTextWrap(true);
    int buttonWidth = (SCREEN_WIDTH - 32) / 4;

    lastSongButton._x = 0 * buttonWidth;
    lastSongButton._y = SCREEN_HEIGHT - 42;
    lastSongButton._width = buttonWidth;
    lastSongButton._height = 32;

    pauseButton._x = 1 * buttonWidth;
    pauseButton._y = SCREEN_HEIGHT - 42;
    pauseButton._width = buttonWidth;
    pauseButton._height = 32;

    playButton._x = 2 * buttonWidth;
    playButton._y = SCREEN_HEIGHT - 42;
    playButton._width = buttonWidth;
    playButton._height = 32;

    nextSongButton._x = 3 * buttonWidth;
    nextSongButton._y = SCREEN_HEIGHT - 42;
    nextSongButton._width = buttonWidth;
    nextSongButton._height = 32;

    paintButtonFull(lastSongButton);
    paintButtonFull(pauseButton);
    paintButtonFull(playButton);
    paintButtonFull(nextSongButton);

  } else {
    ttgo->tft->setCursor(0, SCREEN_HEIGHT - 10);
    ttgo->tft->print("Battery ");
    ttgo->tft->print(String(getBatteryPercentage()));
    ttgo->tft->print("%");
  }

  paintButtonFull(homeNotificationsButton);
  paintButtonFull(homeAppsButton);
//  paintButtonFull(homeSettingsButton);

  drawFrameBuffer();
}

void HomeTouchHandler(struct point p)
{
  if (checkButtonPress(homeNotificationsButton, p.xPos, p.yPos))
  {
    pressButton(homeNotificationsButton);
    currentPage = NOTIFICATIONS;
  }
  else if (checkButtonPress(homeAppsButton, p.xPos, p.yPos)) {
    //    openApps();
  }
//  else if (checkButtonPress(homeSettingsButton, p.xPos, p.yPos))
//  {
//    pressButton(homeSettingsButton);
//    currentPage = SETTINGS;
//  }
  else if (checkButtonPress(lastSongButton, p.xPos, p.yPos)) {
    sendBLE("/lastSong", false);
    printDebug("Last Song Button Pressed");
  }
  else if (checkButtonPress(nextSongButton, p.xPos, p.yPos)) {
    sendBLE("/nextSong", false);
    printDebug("Next Song Button Pressed");
  }
  else if (checkButtonPress(playButton, p.xPos, p.yPos)) {
    sendBLE("/play", false);
    printDebug("Play Button Pressed");
  }
  else if (checkButtonPress(pauseButton, p.xPos, p.yPos)) {
    sendBLE("/pause", false);
    printDebug("Pause Button Pressed");
  }
}
