/**
 * Simple Read
 * 
 * Read data from the serial port and change the color of a rectangle
 * when a switch connected to a Wiring or Arduino board is pressed and released.
 * This example works with Arduino program that follows below or SimpleArduinoWrite.ino
 *
 */

import processing.serial.*;

Serial myPort;  // Create object from Serial class
int val;      // Data received from the serial port

void setup() 
{
  size(200, 200);
  // I know that the first port in the serial list on my mac
  // is always my  FTDI adaptor, so I open Serial.list()[5].
  // On Windows machines, this generally opens COM1.
  // Open whatever port is the one you're using.
  String[] portsAvailable = Serial.list();           // Get a List of all the serial ports available
  for (int i=0; i <  portsAvailable.length; i++) {   // Iterate over the list and print them on console for selection
    print("[" + i + "]\t");    
    println(portsAvailable[i]);                       
  }
  String portName = portsAvailable[5];               // "5" is our selection            
  myPort = new Serial(this, portName, 9600);         // Connect to the specified port
}

void draw()
{
  background(255);                  // Set background to white
  
  if ( myPort.available() > 0) {    // If data is available,
    val = myPort.read();            // Read it and store it in val
    println(val);                   // Print on console what we receive on the serial port
  }  
  if (val == 'R') {              
    fill(255, 0, 0);
  } 
  else if (val == 'G') {              
    fill(0, 255, 0);
  } 
  else if (val == 'B') {              
    fill(0, 0, 255);
  }

  rect(50, 50, 100, 100);
}

/*

// Arduino Code Example

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




*/
