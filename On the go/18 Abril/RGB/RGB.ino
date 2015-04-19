int ledRPin = 11;
int ledGPin = 10;
int ledBPin = 9;

void setup() {
  pinMode(ledRPin, OUTPUT);
  pinMode(ledGPin, OUTPUT);
  pinMode(ledBPin, OUTPUT);
}

void loop() {
  makeRGB(197, 250, 5);
}

void makeRGB(int r, int g, int b) {
  r = 255 - r;
  g = 255 - g;
  b = 255 - b;
  analogWrite(ledRPin, r);
  analogWrite(ledGPin, g);
  analogWrite(ledBPin, b);
  delay(500);
}
