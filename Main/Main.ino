#include "Declarations.h"

//puts device to sleep and configures wakeup sources
void deviceSleep() {
  //re-enable touch wakeup
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_38, 0); //1 = High, 0 = Low
  esp_deep_sleep_start();
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Started Watch");
  initLCD();
  frameBuffer->fillScreen(BACKGROUND_COLOR);
  tft.drawRGBBitmap (0, 0, frameBuffer -> getBuffer (), SCREEN_WIDTH, SCREEN_HEIGHT);
  Serial.println("Done drawing");
  delay(5000);
  deviceSleep();
}

void loop() {
  // put your main code here, to run repeatedly:

}
