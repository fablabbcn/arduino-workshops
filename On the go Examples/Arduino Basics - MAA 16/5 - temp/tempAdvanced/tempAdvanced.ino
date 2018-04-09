int ledPin = 13;

void setup(void) {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop(void) {

  float temp = getTemp();
  
  if (temp > 24) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  
}



