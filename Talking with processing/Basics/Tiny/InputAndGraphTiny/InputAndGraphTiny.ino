#include <SoftwareSerial.h>

SoftwareSerial tinySerial(0, 1); // RX, TX

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  tinySerial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue1 = analogRead(2);
  int sensorValue2 = analogRead(3);

  // print out the value you read:
  tinySerial.print(sensorValue1);
  tinySerial.print(",");
  tinySerial.println(sensorValue2);
  
  delay(10);        // delay in between reads for stability
}


