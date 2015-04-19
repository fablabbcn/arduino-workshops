int ledRPin = 9;
int ledGPin = 10;
int ledBPin = 11;

void setup() {
  Serial.begin(9600);
  pinMode(ledRPin, OUTPUT);
  pinMode(ledGPin, OUTPUT);
  pinMode(ledBPin, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(A0);

  Serial.println(sensorValue);

  int bright = 0;
  
  int position1 = (1023/3)*0;
  int position2 = (1023/3)*1;
  int position3 = (1023/3)*2;
  int position4 = (1023/3)*3;

  if (sensorValue < position2) {         // 1/3 del potenciometro 
    bright = map(sensorValue, 0, position2, 0, 255);
    makeRGB(bright, 0, 0);
  } else  if (sensorValue < position3) { // 2/3 del potenciometro
    bright = map(sensorValue, position1, position3, 0, 255);
    makeRGB(0, bright, 0);
  } else {
    bright = map(sensorValue, position3, position4, 0, 255);
    // 3/3 del potenciometro
    makeRGB(0, 0, bright);
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
