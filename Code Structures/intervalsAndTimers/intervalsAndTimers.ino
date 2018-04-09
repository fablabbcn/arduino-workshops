#include <Servo.h> 

Servo myservo;  // create servo object to control a servo 



int led = 11;           // the pin that the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 1;    // how many points to fade the LED by

int degrees = 0;             
long previousMillis = 0;       
long interval = 1500;    


// the setup routine runs once when you press reset:
void setup()  { 
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 

} 

// the loop routine runs over and over again forever:
void loop()  { 
  
  /* LED Fade */

  // set the brightness of pin 9:
  analogWrite(led, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade: 
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ; 
  }     
  // wait for 30 milliseconds to see the dimming effect    
  delay(30); 
 
 
  /* Servo Interval */


  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis > interval) {

    previousMillis = currentMillis;   

    if (degrees == 0) {
      myservo.write(180);                  // sets the servo position according to the scaled value 
      degrees = 180;
    } 
    else {
      myservo.write(0);                  // sets the servo position according to the scaled value 
      degrees = 0;
    }
  }

}






