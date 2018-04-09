int redLedPin = 9;
int greenLedPin = 10;
int blueLedPin = 11;

void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
}

void loop() {
  makeColor(255,0,255);
}

void makeColor(int red, int green, int blue) {
  // For common anode RGB Led's we invert the signal 
  // max light = 0 | min light = 255
  analogWrite(redLedPin, 255-red);
  analogWrite(greenLedPin, 255-green);
  analogWrite(blueLedPin, 255-blue);
}

