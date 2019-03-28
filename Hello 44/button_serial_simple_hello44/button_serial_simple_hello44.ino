#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1); // RX, TX

void setup() {
  pinMode(3, INPUT);
  mySerial.begin(9600);
}

void loop() {
  if (digitalRead(3)) {
    mySerial.println(0);
  } else {
    mySerial.println(1);
  }
}
