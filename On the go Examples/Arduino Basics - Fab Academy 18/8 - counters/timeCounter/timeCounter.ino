long prevTime = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  long currentTime = millis();
  if (currentTime - prevTime > 1000) {
    prevTime = currentTime;
    Serial.print("NOW: ");
    Serial.println(currentTime);
  }
}
