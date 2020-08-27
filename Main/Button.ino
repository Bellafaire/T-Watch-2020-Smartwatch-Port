//buttons used generally in the UI
PROGMEM iconButton homeButton = {SCREEN_WIDTH - 32, 96, 32, 32, INTERFACE_COLOR, BACKGROUND_COLOR, {(0b00000000 << 8) | 0b00000000, (0b00000000 << 8) | 0b00000000, (0b00000001 << 8) | 0b10000000, (0b00000011 << 8) | 0b11000000, (0b00000111 << 8) | 0b11100000, (0b00001111 << 8) | 0b11110000, (0b00111111 << 8) | 0b11111100, (0b01111111 << 8) | 0b11111110, (0b11111111 << 8) | 0b11111111, (0b00111111 << 8) | 0b11111100, (0b00111110 << 8) | 0b00111100, (0b00111110 << 8) | 0b00111100, (0b00111110 << 8) | 0b00111100, (0b00111110 << 8) | 0b00111100, (0b00111110 << 8) | 0b00111100, (0b00000000 << 8) | 0b00000000}};
PROGMEM iconButton homeNotificationsButton = {SCREEN_WIDTH - 32, SCREEN_HEIGHT - 32 * 3, 32, 32, INTERFACE_COLOR, BACKGROUND_COLOR, {(0b00100001 << 8) | 0b10000100, (0b01000111 << 8) | 0b11100010, (0b10001100 << 8) | 0b00110001, (0b10011000 << 8) | 0b00011001, (0b10010000 << 8) | 0b00001001, (0b00110000 << 8) | 0b00001100, (0b00110000 << 8) | 0b00001100, (0b00110000 << 8) | 0b00001100, (0b00110000 << 8) | 0b00001100, (0b00110000 << 8) | 0b00001100, (0b00100000 << 8) | 0b00000100, (0b01100000 << 8) | 0b00000110, (0b11000000 << 8) | 0b00000011, (0b11000000 << 8) | 0b00000011, (0b11111111 << 8) | 0b11111111, (0b00000011 << 8) | 0b11000000}};
PROGMEM iconButton homeSettingsButton = {SCREEN_WIDTH - 32, SCREEN_HEIGHT - 32 * 2, 32, 32, INTERFACE_COLOR, BACKGROUND_COLOR, {(0b00000000 << 8) | 0b00001110, (0b00000000 << 8) | 0b00011111, (0b11111111 << 8) | 0b11011111, (0b11111111 << 8) | 0b11011111, (0b00000000 << 8) | 0b00001110, (0b00001100 << 8) | 0b00000000, (0b11011111 << 8) | 0b01111111, (0b11011111 << 8) | 0b01111111, (0b00011111 << 8) | 0b00000000, (0b00001110 << 8) | 0b00001110, (0b00000000 << 8) | 0b00011111, (0b11111111 << 8) | 0b11011111, (0b11111111 << 8) | 0b11011111, (0b00000000 << 8) | 0b00001110, (0b00000000 << 8) | 0b00000000, (0b00000000 << 8) | 0b00000000}};
PROGMEM iconButton homeAppsButton = {SCREEN_WIDTH - 32, SCREEN_HEIGHT - 32, 32, 32, INTERFACE_COLOR, BACKGROUND_COLOR, {    (0b00000000 << 8) | 0b00000000,    (0b01111011 << 8) | 0b11011110,    (0b01111011 << 8) | 0b11011110,    (0b01111011 << 8) | 0b11011110,    (0b01111011 << 8) | 0b11011110,    (0b00000000 << 8) | 0b00000000,    (0b01111011 << 8) | 0b11011110,    (0b01111011 << 8) | 0b11011110,    (0b01111011 << 8) | 0b11011110,    (0b01111011 << 8) | 0b11011110,    (0b00000000 << 8) | 0b00000000,    (0b01111011 << 8) | 0b11011110,    (0b01111011 << 8) | 0b11011110,    (0b01111011 << 8) | 0b11011110,    (0b01111011 << 8) | 0b11011110,    (0b00000000 << 8) | 0b00000000,  }};
PROGMEM iconButton upArrowButton = {SCREEN_WIDTH - 32, 0, 32, 48, INTERFACE_COLOR, BACKGROUND_COLOR, {(0b00000001 << 8) | 0b10000000, (0b00000011 << 8) | 0b11000000, (0b00000111 << 8) | 0b11100000, (0b00001111 << 8) | 0b11110000, (0b00011111 << 8) | 0b11111000, (0b00111111 << 8) | 0b11111100, (0b01111111 << 8) | 0b11111110, (0b11111111 << 8) | 0b11111111, (0b00001111 << 8) | 0b11110000, (0b00001111 << 8) | 0b11110000, (0b00001111 << 8) | 0b11110000, (0b00001111 << 8) | 0b11110000, (0b00001111 << 8) | 0b11110000, (0b00001111 << 8) | 0b11110000, (0b00001111 << 8) | 0b11110000, (0b00001111 << 8) | 0b11110000}};
PROGMEM iconButton downArrowButton = {SCREEN_WIDTH - 32, 48, 32, 48, INTERFACE_COLOR, BACKGROUND_COLOR, {(0b00001111 << 8) | 0b11110000, (0b00001111 << 8) | 0b11110000, (0b00001111 << 8) | 0b11110000, (0b00001111 << 8) | 0b11110000, (0b00001111 << 8) | 0b11110000, (0b00001111 << 8) | 0b11110000, (0b00001111 << 8) | 0b11110000, (0b00001111 << 8) | 0b11110000, (0b11111111 << 8) | 0b11111111, (0b01111111 << 8) | 0b11111110, (0b00111111 << 8) | 0b11111100, (0b00011111 << 8) | 0b11111000, (0b00001111 << 8) | 0b11110000, (0b00000111 << 8) | 0b11100000, (0b00000011 << 8) | 0b11000000, (0b00000001 << 8) | 0b10000000}};
iconButton playButton = {128, 48, 32, 48, INTERFACE_COLOR, BACKGROUND_COLOR, {    (0b00000000 << 8) | 0b00000000,    (0b01100000 << 8) | 0b00000000,    (0b01111000 << 8) | 0b00000000,    (0b01111110 << 8) | 0b00000000,    (0b01111111 << 8) | 0b10000000,    (0b01111111 << 8) | 0b11100000,    (0b01111111 << 8) | 0b11111000,    (0b01111111 << 8) | 0b11111110,    (0b01111111 << 8) | 0b11111110,    (0b01111111 << 8) | 0b11111000,    (0b01111111 << 8) | 0b11100000,    (0b01111111 << 8) | 0b10000000,    (0b01111110 << 8) | 0b00000000,    (0b01111000 << 8) | 0b00000000,    (0b01100000 << 8) | 0b00000000,    (0b00000000 << 8) | 0b00000000  }};
iconButton pauseButton = {128, 48, 32, 48, INTERFACE_COLOR, BACKGROUND_COLOR, {    (0b00000000 << 8) | 0b00000000,    (0b01111110 << 8) | 0b01111110,    (0b01111110 << 8) | 0b01111110,    (0b01111110 << 8) | 0b01111110,    (0b01111110 << 8) | 0b01111110,    (0b01111110 << 8) | 0b01111110,    (0b01111110 << 8) | 0b01111110,    (0b01111110 << 8) | 0b01111110,    (0b01111110 << 8) | 0b01111110,    (0b01111110 << 8) | 0b01111110,    (0b01111110 << 8) | 0b01111110,    (0b01111110 << 8) | 0b01111110,    (0b01111110 << 8) | 0b01111110,    (0b01111110 << 8) | 0b01111110,    (0b01111110 << 8) | 0b01111110,    (0b00000000 << 8) | 0b00000000  }};
iconButton nextSongButton = {128, 48, 32, 48, INTERFACE_COLOR, BACKGROUND_COLOR, {    (0b00000000 << 8) | 0b00000000,    (0b01000000 << 8) | 0b01000000,    (0b01100000 << 8) | 0b01100000,    (0b01110000 << 8) | 0b01110000,    (0b01111000 << 8) | 0b01111000,    (0b01111100 << 8) | 0b01111100,    (0b01111110 << 8) | 0b01111110,    (0b01111111 << 8) | 0b01111111,    (0b01111111 << 8) | 0b01111111,    (0b01111110 << 8) | 0b01111110,    (0b01111100 << 8) | 0b01111100,    (0b01111000 << 8) | 0b01111000,    (0b01110000 << 8) | 0b01110000,    (0b01100000 << 8) | 0b01100000,    (0b01000000 << 8) | 0b01000000,    (0b00000000 << 8) | 0b00000000  }};
iconButton lastSongButton = {128, 48, 32, 48, INTERFACE_COLOR, BACKGROUND_COLOR, {    (0b00000000 << 8) | 0b00000000,    (0b00000010 << 8) | 0b00000010,    (0b00000110 << 8) | 0b00000110,    (0b00001110 << 8) | 0b00001110,    (0b00011110 << 8) | 0b00011110,    (0b00111110 << 8) | 0b00111110,    (0b01111110 << 8) | 0b01111110,    (0b11111110 << 8) | 0b11111110,    (0b11111110 << 8) | 0b11111110,    (0b01111110 << 8) | 0b01111110,    (0b00111110 << 8) | 0b00111110,    (0b00011110 << 8) | 0b00011110,    (0b00001110 << 8) | 0b00001110,    (0b00000110 << 8) | 0b00000110,    (0b00000010 << 8) | 0b00000010,    (0b00000000 << 8) | 0b00000000  }};

//determines width of text displayed on LCD screen, default text has width of 5 pixels + 1 space pixel
int TextWidth(button b) {
  return b._text.length() * 6;
}

void paintButton(button b) {
  ttgo->tft->drawRect(b._x, b._y, b._width, b._height, b._color);
  ttgo->tft->setTextColor(b._color);
  ttgo->tft->setCursor(b._x + (int)(b._width - TextWidth(b)) / 2, b._y + (int)b._height / 2 - 5);
  ttgo->tft->println(b._text);
}

void paintButton(iconButton b) {
  ttgo->tft->drawRect(b._x, b._y, b._width, b._height, b._color);
  for (int row = 0; row < 16; row++) {
    for (int column = 0; column < 16; column++) {
      ttgo->tft->drawPixel(
        b._x + b._width / 2 - 8 + column,
        b._y + b._height / 2 - 8 + row,
        (b.icon[row] & (1 << (15 - column))) ? b._color : b._backgroundColor
      );
    }
  }
}



void paintButtonNoBuffer(button b) {
  ttgo->tft->fillRect(b._x, b._y, b._width, b._height, b._backgroundColor);
  ttgo->tft->drawRect(b._x, b._y, b._width, b._height, b._color);
  ttgo->tft->setTextColor(b._color);
  ttgo->tft->setCursor(b._x + (int)(b._width - TextWidth(b)) / 2, b._y + (int)b._height / 2 - 5);
  ttgo->tft->println(b._text);
}


void paintButtonNoBuffer(iconButton b) {
  ttgo->tft->fillRect(b._x, b._y, b._width, b._height, b._backgroundColor);
  ttgo->tft->drawRect(b._x, b._y, b._width, b._height, b._color);
  for (int row = 0; row < 16; row++) {
    for (int column = 0; column < 16; column++) {
      ttgo->tft->drawPixel(
        b._x + b._width / 2 - 8 + column,
        b._y + b._height / 2 - 8 + row,
        (b.icon[row] & (1 << (15 - column))) ? b._color : b._backgroundColor
      );
    }
  }
}



void paintButtonFull(button b) {
  ttgo->tft->fillRect(b._x, b._y, b._width, b._height, b._backgroundColor);
  ttgo->tft->drawRect(b._x, b._y, b._width, b._height, b._color);
  ttgo->tft->setTextColor(b._color);
  ttgo->tft->setCursor(b._x + (int)(b._width - TextWidth(b)) / 2, b._y + (int)b._height / 2 - 5);
  ttgo->tft->println(b._text);
}


void paintButtonFull(iconButton b) {
  ttgo->tft->fillRect(b._x, b._y, b._width, b._height, b._backgroundColor);
  ttgo->tft->drawRect(b._x, b._y, b._width, b._height, b._color);
  for (int row = 0; row < 16; row++) {
    for (int column = 0; column < 16; column++) {
      ttgo->tft->drawPixel(
        b._x + b._width / 2 - 8 + column,
        b._y + b._height / 2 - 8 + row,
        (b.icon[row] & (1 << (15 - column))) ? b._color : b._backgroundColor
      );
    }
  }
}

void pressButton(iconButton b) {
  ttgo->tft->fillRect(b._x, b._y, b._width, b._height, b._color);
}

void pressButton(button b) {
  ttgo->tft->fillRect(b._x, b._y, b._width, b._height, b._color);
}

bool checkButtonPress(button b) {
  struct point p = readTouch();
  return checkButtonPress(b, p.xPos, p.yPos);
}

bool checkButtonPress(iconButton b) {
  struct point p = readTouch();
  return checkButtonPress(b, p.xPos, p.yPos);
}

bool checkButtonPress(iconButton b, int x, int y) {
  if (x > b._x && x < b._x + b._width && y > b._y && y < b._y + b._height) {
    return true;
  } else {
    return false;
  }
}

bool checkButtonPress(button b, int x, int y) {
  if (x > b._x && x < b._x + b._width && y > b._y && y < b._y + b._height) {
    return true;
  } else {
    return false;
  }
}
