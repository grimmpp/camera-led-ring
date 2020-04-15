/**
 * 
 * Program to change brightness of a LED ring which can be controlled by using only one button.
 * 
 */

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN A5 //9 // digitalen Pin for  WS2812 LEDs / NeoPixel ring
#define NUMPIXELS 40 // Amount of LEDs
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define TasterPin 0 //11  // pin of button

int8_t pause = 500;   // pause at the brightest and darkest point.
uint8_t brightness = 10;  // current brightness [0-b_max]
uint8_t b_max = 100;
bool direction = true;  //true = counts up, false = counts down

/**
 * set white color and set current brightness
 */
void refreshLeds() {
  pixels.fill(pixels.Color(brightness, brightness, brightness));
  pixels.show(); 
}

/**
 * Init. ...
 */
void setup() {
  pixels.begin(); 
  pinMode(TasterPin, INPUT_PULLUP); 

  refreshLeds();
}

/**
 * If button is pressed brightness increases, after b_max is reached it decreases, and it starts again, ...
 * If button has been pressed and was released again, it will stop changing the brightness of the LEDs
 */
void loop() {

  if (!digitalRead(TasterPin)) {
    if (direction) {
      brightness = min(brightness + 10, b_max);
    } else {
      brightness = max(brightness - 10, 0);
    }
    refreshLeds();

    if (brightness < 10) { direction = true;   }
    if (brightness >= b_max) { direction = false;  }
  } 
    
  delay(50);
}

