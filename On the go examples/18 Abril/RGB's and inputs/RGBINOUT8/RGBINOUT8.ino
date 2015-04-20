int ledRPin = 9;
int ledGPin = 10;
int ledBPin = 11;

int buttonPin = 12;
int sensorPin = A0;

int bright = 0;

int maxValue = 1023;

int position1 = (maxValue / 3) * 0; // int position1 = 0;
int position2 = (maxValue / 3) * 1; // int position2 = 345;
int position3 = (maxValue / 3) * 2; // int position3 = 690;
int position4 = (maxValue / 3) * 3; // int position4 = 1023;

void setup() {
  Serial.begin(9600);
  pinMode(ledRPin, OUTPUT);
  pinMode(ledGPin, OUTPUT);
  pinMode(ledBPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  int buttonState = digitalRead(buttonPin);

  Serial.print(sensorValue);
  Serial.print(" ");
  Serial.println(buttonState);

  if (buttonState == 0) {
    if (sensorValue < position2) {         // 345 | 1/3 del potenciometro
      bright = map(sensorValue, position1, position2, 0, 255);
      makeRGB(bright, 0, 0);
    } else  if (sensorValue < position3) { // 2/3 del potenciometro
      bright = map(sensorValue, position2, position3, 0, 255);
      makeRGB(0, bright, 0);
    } else {
      bright = map(sensorValue, position3, position4, 0, 255);  // 3/3 del potenciometro
      makeRGB(0, 0, bright);
    }
  } else {
    makeRGB(0,0,0);
  }


}

void makeRGB(int r, int g, int b) {
  r = 255 - r;
  g = 255 - g;
  b = 255 - b;
  analogWrite(ledRPin, r);
  analogWrite(ledGPin, g);
  analogWrite(ledBPin, b);
}
