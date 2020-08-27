#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>
#include "BLEDevice.h"

//LCD pins
#define LCD_CS 5
#define LCD_LED 12
#define LCD_SCK 18
#define LCD_DC 27 //LCD_A0
#define LCD_RST -1
#define LCD_MOSI 19
Adafruit_ST7789 tft = Adafruit_ST7789(LCD_CS, LCD_DC, LCD_MOSI, LCD_SCK, LCD_RST);

//screen resolution (don't need any magic numbers)
#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 240

#define BACKGROUND_COLOR ST77XX_BLACK
#define TEXT_COLOR ST77XX_WHITE
#define INTERFACE_COLOR ST77XX_WHITE
#define GRAYED 0xBDF7
int ERROR_COLOR = ST77XX_BLUE;

//frame buffer for drawing more elaborate UI elements
GFXcanvas16* frameBuffer = new GFXcanvas16 (SCREEN_WIDTH, SCREEN_HEIGHT);
