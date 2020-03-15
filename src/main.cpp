/**
 * 
 * Program to change brightness of a LED ring which can be controlled by using only one button.
 * 
 */

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN 9 // digitalen Pin for  WS2812 LEDs / NeoPixel ring
#define NUMPIXELS 40 // Amount of LEDs
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define TasterPin 11  // pin of button

int8_t pause = 500;   // pause at the brightest and darkest point.
uint8_t brightness = 10;  // current brightness [0-255]
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
  Serial.begin(115200);
  pixels.begin(); 
  pinMode(TasterPin, INPUT); 

  refreshLeds();
}

/**
 * If button is pressed brightness increases, makes a pause, and decreases, makes a pause, and it starts again, ...
 * If button has been pressed and was released again, it will stop changing the brightness of the LEDs
 */
void loop() {
    if (!digitalRead(TasterPin)) {
      if (direction) {
        brightness = min(brightness + 10, 255);
        if (brightness == 255) direction = false;
      } else {
        brightness = max(brightness - 10, 0);
        if (brightness == 0) direction = true;
      }
      refreshLeds();

      Serial.println(brightness);

      if (brightness == 0) { delay(pause); }
      if (brightness == 255) { delay(pause); }
    }
    
  delay(50);
}

