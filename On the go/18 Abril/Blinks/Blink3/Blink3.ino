int ledPin = 13;
int timeArduinoLedIsON  = 2000;
int timeArduinoLedIsOFF = timeArduinoLedIsON / 2;


void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);   
  delay(timeArduinoLedIsON);       
  digitalWrite(ledPin, LOW);  
  delay(timeArduinoLedIsOFF);     
}


