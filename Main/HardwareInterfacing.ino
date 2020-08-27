void initLCD() {
  tft.init(SCREEN_WIDTH, SCREEN_HEIGHT);
  pinMode(LCD_LED, OUTPUT);
  digitalWrite(LCD_LED, HIGH);
}
