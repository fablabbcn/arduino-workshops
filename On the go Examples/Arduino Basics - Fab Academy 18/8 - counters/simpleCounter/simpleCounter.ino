int c = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  c++;
  if(c > 100) c = 0;
  Serial.println(c);
  delay(500);
}
