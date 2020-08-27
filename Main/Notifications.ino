int numberOfNotifications;
int selectedNotification = 0;

#define FIELD_SEPARATOR ';'
#define FIELD_SEPARATOR_STRING ";"

void updateNotificationData(){
  printDebug("Updating Notification Data"); 
  String data = sendBLE("/notifications", true);
  printDebug(data);
  for(int a = 0; a < NOTIFICATION_DATA_BUFFER_SIZE; a++){
    notificationData[a] = data[a]; 
  }
  updateTimeFromNotificationData();
}



void NotificationsTouchHandler(struct point p) {
  if (checkButtonPress(homeButton, p.xPos, p.yPos))
  {
    pressButton(homeButton);
    currentPage= HOME; 
  }
  else if (checkButtonPress(upArrowButton, p.xPos, p.yPos))
  {
    if (selectedNotification > 0)
    {
      selectedNotification--;
    }
  }
  else if (checkButtonPress(downArrowButton, p.xPos, p.yPos))
  {
    if (selectedNotification < numberOfNotifications - 2)
    {
      selectedNotification++;
    }
  }
  else if (p.xPos > 0 && p.xPos < SCREEN_WIDTH - 32 && p.yPos > 0 && p.yPos < SCREEN_HEIGHT) {
    openNotification(selectedNotification);
  }

  printDebug("notification selected index: " + String(selectedNotification));

}

void openNotification(int sel) {
  Window w = Window(0, 14, 160, 100, true);

  w.println(parseFromNotifications(sel, 0)); //app name

  //EXTRA_TITLE
  if (parseFromNotifications(sel, 1).length() > 0 && !parseFromNotifications(sel, 1).equals(FIELD_SEPARATOR_STRING)) {
    w.println("_Title_");
    w.println(parseFromNotifications(sel, 1));
  }

  //EXTRA_TEXT
  if (parseFromNotifications(sel, 2).length() > 0 && !parseFromNotifications(sel, 2).equals(FIELD_SEPARATOR_STRING)) {
    w.println("_Text_");
    w.println( parseFromNotifications(sel, 2));

  }

  //EXTRA_INFO_TEXT
  if (parseFromNotifications(sel, 3).length() > 0 && !parseFromNotifications(sel, 3).equals(FIELD_SEPARATOR_STRING)) {
    w.println("_Info_");
    w.println(parseFromNotifications(sel, 3));
  }

  //EXTRA_SUB_TEXT
  if (parseFromNotifications(sel, 4).length() > 0 && !parseFromNotifications(sel, 4).equals(FIELD_SEPARATOR_STRING)) {
    w.println("_Subtext_");
    w.println(parseFromNotifications(sel, 4));
  }

  //EXTRA_TITLE
  if (parseFromNotifications(sel, 5).length() > 0 && !parseFromNotifications(sel, 5).equals(FIELD_SEPARATOR_STRING)) {
    w.println("_extratitle_");
    w.println(parseFromNotifications(sel, 5));
  }

  //EXTRA_TITLE
  if (parseFromNotifications(sel, 6).length() > 0 && !parseFromNotifications(sel, 6).equals(FIELD_SEPARATOR_STRING)) {
    w.println("_other_");
    w.println(parseFromNotifications(sel, 6));
  }


  w.focus();
}


void switchToNotifications()
{
  printDebug("Switched to Notifications");

  numberOfNotifications = getNotificationLines();
  selectedNotification = 1;
  drawNotifications();
  currentPage = NOTIFICATIONS;
}


void drawNotifications() {
  //fill in the background
  frameBuffer -> drawRGBBitmap(0, 0, background, SCREEN_WIDTH, SCREEN_HEIGHT);

  int y_pos = 0;
  numberOfNotifications = getNotificationLines();
  if (numberOfNotifications > 0) {
    tft.setTextWrap(false);
    //for whatever reason line 1 is a blank line and the last line contains the time
    for (int a = 0; a < numberOfNotifications - 1; a++) {
      if (selectedNotification == a) {
        tft.fillRect(0, y_pos - 1, SCREEN_WIDTH, 8, INTERFACE_COLOR);
        tft.setTextColor(BACKGROUND_COLOR);
        tft.setCursor(0, y_pos);
        tft.print(parseFromNotifications(a, 0));
      } else {
        tft.setTextColor(INTERFACE_COLOR);
        tft.setCursor(0, y_pos);
        tft.print(parseFromNotifications(a, 0));
      }
      y_pos += 10;
    }
    tft.setTextWrap(true);
  } else {
    tft.setCursor(0, 0);
    tft.print("No Notifications");
  }

  //just setting this back to prevent any issues later.
  tft.setTextColor(TEXT_COLOR);

  paintButtonFull(upArrowButton);
  paintButtonFull(downArrowButton);
  paintButtonFull(homeButton);
 drawFrameBuffer();
}


int getNotificationLines() {
  int lineCount = 0;
  for (int a = 0; a < 2048; a++) {
    if (notificationData[a] == '\n') {
      lineCount++;
    }
    if (notificationData[a] == '*' &&
        notificationData[a - 1] == '*' &&
        notificationData[a - 2] == '*') {
      break;
    }
  }
  return lineCount;
}

//find the information contained in a given line and given position in a comma seperated value
String parseFromNotifications(int line, int field) {
  String lineData = getValue(String(notificationData), '\n', line);
  return getValue(lineData, FIELD_SEPARATOR, field);
}

//duplicated in settings.ino
String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++)
  {
    if (data.charAt(i) == separator || i == maxIndex)
    {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }

  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
