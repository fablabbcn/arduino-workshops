// NeoPixel Ring simple sketch (c) 2013 Shae Erisson - released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

const byte neopixelPin    = 6;
const byte numberOfPixels = 11;

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numberOfPixels, neopixelPin, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  pixels.setPixelColor(2, pixels.Color(0, 0, 0));
  pixels.setPixelColor(0, pixels.Color(255, 0, 0));
  pixels.show();
  delay(1000);
  pixels.setPixelColor(0, pixels.Color(0, 0, 0));
  pixels.setPixelColor(1, pixels.Color(0, 255, 0));
  pixels.show();
  delay(1000);
  pixels.setPixelColor(1, pixels.Color(0, 0, 0));
  pixels.setPixelColor(2, pixels.Color(0, 0, 255));
  pixels.show();
  delay(1000);
}
