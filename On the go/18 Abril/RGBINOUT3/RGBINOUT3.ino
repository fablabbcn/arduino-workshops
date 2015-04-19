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



  if (sensorValue < (1023/3)*1) {         // 1/3 del potenciometro 
    makeRGB(255, 0, 0);
  } else  if (sensorValue < (1023/3)*2) { // 2/3 del potenciometro
    makeRGB(0, 255, 0);
  } else {                                // 3/3 del potenciometro
    makeRGB(0, 0, 255);
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
