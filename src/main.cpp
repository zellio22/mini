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


// For the Adafruit shield, these are the default.
//#define TFT_DC 9
//#define TFT_CS 7
//#define TFT_MOSI 11
//#define TFT_MISO 4
//#define TFT_RST 5
//#define TFT_CLK 12

// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
//Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
// If using the breakout, change pins as desired
//Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);

TFT_eSPI tft = TFT_eSPI(); 
unsigned long debut =0;

void setup() {
  Serial.begin(9600);
  Serial.println("ILI9341 Test!"); 
  
  tft.begin();
  tft.init();
  tft.setTextSize(3);


  tft.fillScreen(tft.color565(255,0,0));

  
}

int i =0;
void loop(void) {
   debut = millis();
   i++;
   tft.setCursor(100,100);
   tft.print(i);

  uint16_t x = 0, y = 0; // To store the touch coordinates

  // Pressed will be set true is there is a valid touch on the screen
  bool pressed = tft.getTouch(&x, &y);
    if (pressed) {
      tft.fillCircle(x, y, 2, TFT_WHITE);
      Serial.print("detection en "+String(x,y));
      
   Serial.println((millis()-debut));
  }

}

