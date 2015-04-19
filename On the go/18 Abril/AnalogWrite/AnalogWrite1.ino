void setup() {
  pinMode(11, OUTPUT);
}

void loop() {
  analogWrite(11, 100);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  analogWrite(11, 255);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}
