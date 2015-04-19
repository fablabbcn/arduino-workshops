int ledPinRed   = 10;
int ledPinGreen = 11;

void setup() {
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinRed, OUTPUT);
}

void loop() {
  baliza(500, 500);
  baliza(1000, 2000);
  baliza(500, 1000);
}

void baliza(int TiempoRojo, int tiempoVerde) {
  digitalWrite(ledPinRed, HIGH);
  digitalWrite(ledPinGreen, LOW);
  delay(tiempoRojo);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinGreen, HIGH);
  delay(tiempoVerde);
}


