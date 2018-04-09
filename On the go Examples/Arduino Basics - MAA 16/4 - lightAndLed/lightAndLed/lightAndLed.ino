int ledPin = 11;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // set the led into output mode
  pinMode(ledPin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  // escale the arduino ADC (analogRead) range of 1024 steps (0-1023) to the arduino PWM (analogWrite) of 256 steps (0-255) 
  int brightness = map(sensorValue, 0, 1023, 0, 255);
  // set the pin to the appropiate brightness from 0 to 255
  analogWrite(ledPin, brightness);
  
  delay(1);        // delay in between reads for stability
}
