/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

 This example code is in the public domain.
 */

int sensorMax;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  sensorMax = analogRead(A0);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  
  int light = map(sensorValue, 190, sensorMax, 0, 100); // 0 - 1023 // 190 - 900
  
  light = constrain(light, 0, 100);
  
  // print out the value you read:
  Serial.println(light);
  
  delay(1);        // delay in between reads for stability
}
