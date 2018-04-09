/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/


#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

const int NPin = 6;
const int NPix = 7;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NPix, NPin, NEO_GRB + NEO_KHZ800);


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pixels.begin();
}

// the loop routine runs over and over again forever:
void loop() {

  int sensorValueA0 = analogRead(A0);
  int sensorValueA1 = analogRead(A1);
  int pot = map(sensorValueA0,0,1023,0,255);
  int luz = map(sensorValueA1,0,1023,0,255);

  Serial.print(sensorValueA0);
  Serial.print(",");
  Serial.println(sensorValueA1);


int pixelIDselected = map(sensorValueA0, 0, 1023, 0, NPix - 1);

for (int pixelID = 0; pixelID < NPix;  pixelID++) {
    if (pixelID < pixelIDselected) {
      pixels.setPixelColor(pixelID, pixels.Color(0, 255, 0));
      if (pixelID > NPix / 2)  pixels.setPixelColor(pixelID, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(pixelID, pixels.Color(0, 0, 0));
    }
  }
  delay(10);        // delay in between reads for stability
}



