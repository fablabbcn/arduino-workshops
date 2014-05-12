int switchPin = 4;                        // Switch connected to pin 4
int switchPin2 = 5;                       // Switch connected to pin 5

void setup() {
  pinMode(switchPin, INPUT);             // Set pin 4 as an input
  pinMode(switchPin2, INPUT);             // Set pin 5 as an input

  Serial.begin(9600);                    // Start serial communication at 9600 bps
}

void loop() {
  if (digitalRead(switchPin) == HIGH) {  // If switch is ON,
    Serial.print('R');               // send 1 to Processing
  } 
  else if (digitalRead(switchPin2) == HIGH) {  // If switch is ON,
    Serial.print('G');               // send 1 to Processing
  } 
  else {                               // If the switch is not ON,
    Serial.print('B');               // send 0 to Processing
  }
  delay(100);                            // Wait 100 milliseconds
}


