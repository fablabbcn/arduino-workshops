#include <Servo.h> 

int servoPin = 9;

Servo myservo;  // create servo object to control a servo 

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // attaches the servo on pin 9 to the servo object 
  myservo.attach(servoPin);  

}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  // escale the arduino ADC (analogRead) range of 1024 steps (0-1023) to the servo of 180 degrees range 
  int position = map(sensorValue, 0, 1023, 0, 179);
  // set the pin to the servi to the 0-179
  myservo.write(position); 

  delay(1);        // delay in between reads for stability
}

