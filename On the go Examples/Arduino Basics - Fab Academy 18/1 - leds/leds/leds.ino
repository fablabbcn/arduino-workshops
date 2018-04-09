int ledPinA = 9;
int ledPinB = 10;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(ledPinA, OUTPUT);
  pinMode(ledPinB, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  blinkBasicPattern();
//  blinkBasicAnotherPattern();
}

void blinkBasicPattern() {
  digitalWrite(ledPinA, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(ledPinA, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);    // wait for a second
  digitalWrite(ledPinB, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(ledPinB, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);    // wait for a second
}

void blinkBasicAnotherPattern() {
  digitalWrite(ledPinA, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(ledPinB, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
  digitalWrite(ledPinB, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(ledPinA, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);    // wait for a second
}


