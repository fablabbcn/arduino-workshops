int ledPinRed   = 10;
int ledPinGreen = 11;
int timeArduinoLedIsON  = 2000;
int timeArduinoLedIsOFF = timeArduinoLedIsON / 2;
void setup() {
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinRed, OUTPUT);
}
void loop() {
  digitalWrite(ledPinRed, HIGH);
  digitalWrite(ledPinGreen, LOW);
  delay(1000);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinGreen, HIGH);
  delay(1000);
}


