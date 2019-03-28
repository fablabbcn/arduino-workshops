void setup() {
  pinMode(7, OUTPUT);
  pinMode(3, INPUT);
}

void loop() {
  if (digitalRead(3)) {
    digitalWrite(7, HIGH);
  } else {
    digitalWrite(7, LOW);
  }
}
