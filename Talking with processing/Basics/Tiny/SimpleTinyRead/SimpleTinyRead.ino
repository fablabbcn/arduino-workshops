#include <SoftwareSerial.h>

SoftwareSerial tinySerial(0, 1); // RX, TX

char val; // Data received from the serial port
int ledPin = 13; // Set the pin to digital I/O 4

void setup() {
  pinMode(ledPin, OUTPUT); // Set pin as OUTPUT
  tinySerial.begin(9600); // Start serial communication at 9600 bps
}

void loop() {
  if (tinySerial.available()) { // If data is available to read,
    val = tinySerial.read(); // read it and store it in val
  }
  if (val == 'H') { // If H was received
    digitalWrite(ledPin, HIGH); // turn the LED on
  } 
  else {
    digitalWrite(ledPin, LOW); // Otherwise turn it OFF
  }
  delay(100); // Wait 100 milliseconds for next reading
}


