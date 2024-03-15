/***************************************************
  This is our GFX example for the Adafruit ILI9341 Breakout and Shield
  ----> http://www.adafruit.com/products/1651

  Check out the links above for our tutorials and wiring diagrams
  These displays use SPI to communicate, 4 or 5 pins are required to
  interface (RST is optional)
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 ****************************************************/

#include <TFT_eSPI.h> 
#include "SPI.h"


/*
#define TFT_MISO 4  // (leave TFT SDO disconnected if other SPI devices share MISO)
#define TFT_MOSI 11
#define TFT_SCLK 12
#define TFT_CS    7  // Chip select control pin
#define TFT_DC    9  // Data Command control pin
#define TFT_RST   5  // Reset pin (could connect to RST pin)

// Optional touch screen chip select
#define TOUCH_CS 3 // Chip select pin (T_CS) of touch screen
*/
TFT_eSPI tft = TFT_eSPI(); 
unsigned long debut =0;

void setup() {
  Serial.begin(9600);
  Serial.println("ILI9341 Test!"); 
  
  tft.begin();
  tft.init();
  tft.setTextSize(3);
  tft.setRotation(1);

  tft.fillScreen(tft.color565(255,0,0));
  pinMode(15,OUTPUT);
  digitalWrite(15,HIGH);
  
}

int i =0;
void loop(void) {
   debut = millis();
   i++;
   tft.setCursor(100,50);
   tft.print(i);

  uint16_t x = 0, y = 0; // To store the touch coordinates

  // Pressed will be set true is there is a valid touch on the screen
  bool pressed = tft.getTouch(&x, &y);
  
    if (pressed==true) {
      Serial.println("detection en x= "+String(x)+" y= "+String(y));
      tft.fillCircle(abs(x-320), y, 2, TFT_WHITE);
      
  }

  Serial.println((millis()-debut));

}

