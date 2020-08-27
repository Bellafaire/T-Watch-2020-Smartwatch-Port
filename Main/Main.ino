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
  frameBuffer = new GFXcanvas16 (SCREEN_WIDTH, SCREEN_HEIGHT);
  tft.drawRGBBitmap(0, 0, background, SCREEN_WIDTH, SCREEN_HEIGHT);

  MainLoop();

  deviceSleep();
}

void loop() {
  // put your main code here, to run repeatedly:

}
