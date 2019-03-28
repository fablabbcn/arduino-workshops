#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1); // RX, TX

void setup() {
  pinMode(7, OUTPUT);
  mySerial.begin(9600);
}

void loop() {
  // see if there's incoming serial data:
  if (mySerial.available() > 0) {
    int incomingByte = mySerial.read();
    if (incomingByte == '1') {
      digitalWrite(7, HIGH);
    }
    if (incomingByte == '0') {
      digitalWrite(7, LOW);
    }
  }
}
