int c = 0;
int inc = 1;
void setup() {
  Serial.begin(9600);
}

void loop() {
  c = c + inc;
  if(c == 100 || c == 0) inc = -inc;
  Serial.println(c);
  delay(100);
}
