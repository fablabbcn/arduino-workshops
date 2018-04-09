// NeoPixel Ring simple sketch (c) 2013 Shae Erisson - released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

const byte neopixelPin    = 6;
const byte numberOfPixels = 7;

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numberOfPixels, neopixelPin, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
  Serial.begin(9600);
  pixels.setBrightness(255); //
}


void loop() {

  int sensorValue = analogRead(A5);

  int pixelIDselected = map(sensorValue, 0, 1023, 0, numberOfPixels - 1);

  Serial.println(sensorValue);

  for (int pixelID = 0; pixelID < numberOfPixels;  pixelID++) {
    if (pixelID < pixelIDselected) {
      pixels.setPixelColor(pixelID, pixels.Color(0, 255, 0));
      if (pixelID > numberOfPixels / 2)  pixels.setPixelColor(pixelID, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(pixelID, pixels.Color(0, 0, 0));
    }
  }

  pixels.show();
}
