
/* 
 
 The TWEET MACHINE | Publish tweets with your Arduino with no computers and no screens | BASIC VERSION |
 
 ABOUT:
 
 - The Arduino connects with the internet with the Ethernet Shield http://arduino.cc/en/Main/ArduinoEthernetShield 
    or an Arduino Ethernet http://arduino.cc/en/Main/ArduinoBoardEthernet
    
 - The Ethernet communications are done by the Arduino Ethernet library that comes built-in,
     this allows the Arduino to connect to remote servers and to do things. We use API's, 
     a standard way for computers to talk with services on other computers, like the Facebook API, 
     the Twitter API or the Pachube/Cosm API. We can also make the Shield work as a server and access 
     it by tiping its IP on a local network, similar of what we do with our home internet Gateway/Router.
 
 - To publish a Tweet, Arduino needs to authenticate as Twitter App so it can publish for the required user through the Twitter API. 
   This is simplified by using the Arduino Twitter Library, this library handles the twitter API in a more Arduino Friendly 
   using its own server as an intermediate server. http://arduino-tweet.appspot.com/
 
 _ The RC servo is controlled with the built-in Arduino Servo library. The knob and the button are a simple potentiometer and a button. 
   A resistor is also used on the button to make a pull-up resistor, this can be made also using Arduino internal pull-up resistors. 
   http://www.cmiyc.com/tutorials/arduino-pull-ups/
   
 HOWTO:
 
  - Arduino + Ethernet Shield + Regular RC Servo + Potentiometer (ex: 10K) + Button (+ Resistor).
  - Download the Arduino Tweet library and get and API key here  http://arduino-tweet.appspot.com/
 
 
 FABLABBCN | Guillem Camprodon
 
*/
 
#include <SPI.h> // Allows the Arduino to talk with the Ethernet Shield
#include <Ethernet.h> // Allows the Arduino to talk with the Internet
#include <Twitter.h> // Allows the Arduino to easy authorize and publish to Twitter. Download it here http://arduino-tweet.appspot.com/
#include <Servo.h>  // Allows the Arduino to easily control Servos

const int buttonPin = 3;
const int knobPin = 0;
const int servoPin = 4;


Servo servoA;  // create servo object to control a servo 

Twitter twitter("178494505-nh00PbLJDEdNPW6M2M09aYzP4cnismGb2LJZJ7MJ"); // Your Token to Tweet > get it from http://arduino-tweet.appspot.com/

byte mac[] = { 0x90, 0xA2, 0xDA, 0x00, 0x4A, 0x02 }; // It should be on the back of your Ether Shield / Arduino Ethernet

char messageContainer[140]; // It contains the message you'll be tweeting as an array of characters.

void setup()
{
  updateMessage("No messages");
  servoA.attach(servoPin);  // attaches the servo on pin 9 to the servo object 
  servoA.write(0);       
  delay(1000);
  pinMode(buttonPin, INPUT);     
  Ethernet.begin(mac);
  Serial.begin(9600);
  Serial.println("connecting ...");
}

void loop()
{
  int buttonState = digitalRead(buttonPin); // Reads the button
  int sensorValue = analogRead(knobPin); // Reads the knob
  int option = map(sensorValue, 73, 1023, 1, 4); // Maps the knob value into just 4 different numbers
  int degreesServo = map(sensorValue, 73, 1023, 20, 170); // Maps the knob value into degrees for the servo
  
  servoA.write(degreesServo); // Writes the know posiion on the servo.     
  
  Serial.print("Servo at: "); // Prints the Servo position for debugging.
  Serial.print(degreesServo);
  Serial.println(" deg.");
  
  if (buttonState == HIGH) {  // If the button is pressed then...
    switch (option) {  // Chooses a sentence to tweets depending on the knob filtered position. 
    case 1:
      Serial.println("Message: A");
      updateMessage("ARDUBOT is really HAPPY!");
      break;
    case 2:
      Serial.println("Message: B");
      updateMessage("ARDUBOT is BORED!");
      break;
    case 3:
      Serial.println("Message: C");
      updateMessage("ARDUBOT is not HAPPY!");
      break;
    case 4:
      Serial.println("Message: D");
      updateMessage("ARDUBOT is getting CRAZY!");
      break;
    default:
      break;
    }

    if (twitter.post(messageContainer)) {  // Publishes to twitter
      int status = twitter.wait(&Serial);
      if (status == 200) {
        Serial.println("OK"); // Print the twitter response for debugging
        servoA.write(0);  // Brings the servo to 0 for one second to show the tweet has been post.
        delay(1000);     
      } 
      else {
        Serial.print("failed: code"); // Print the twitter response for debugging
        Serial.println(status);
      }
    } 
    else {
      Serial.println("connection failed"); // Print the twitter response for debugging
    }
  } 
}


void updateMessage (String message) { // Converts the strings containing the messages in to char array for being pulished to twitter, 
  message += " >> weekend ARDUINO workshop"; // It also adds some more info on the twwet,
  message.toCharArray(messageContainer, 140);
}












