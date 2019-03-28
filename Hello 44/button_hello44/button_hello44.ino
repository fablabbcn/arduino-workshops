#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1); // RX, TX

void setup() {
  pinMode(7, OUTPUT);
  pinMode(3, INPUT);
  mySerial.begin(9600);
}

void loop() {
  if (digitalRead(3)) {
    digitalWrite(7, LOW);
    mySerial.println("Button unpressed!");
  } else {
    digitalWrite(7, HIGH);
    mySerial.println("Button pressed!");
  }
}
