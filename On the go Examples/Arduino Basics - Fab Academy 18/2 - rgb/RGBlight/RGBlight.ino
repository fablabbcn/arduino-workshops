const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to

long prevTime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // read the analog in value:
  int sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  int outputValue = map(sensorValue, 200, 600, 0, 255);
  outputValue = constrain(outputValue, 0, 255);

  // print the results to the serial monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.print(outputValue);

  if (outputValue < 200) {
    rgb(255 - outputValue, (255 - outputValue) / 2, (255 - outputValue) / 2); //red, green, blue
  } else {
    rgb(255 - outputValue, 255 - outputValue, 255 - outputValue); //red, green, blue
  }

  

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(20);
}

void rgb(int red, int green, int blue) {
  analogWrite(redPin, 255 - red);
  analogWrite(greenPin, 255 - green);
  analogWrite(bluePin, 255 - blue);
  Serial.print("\t color = ");
  Serial.print(red);
  Serial.print("\t");
  Serial.print(green);
  Serial.print("\t");
  Serial.println(blue);
}
