/**
 * Simple Write. 
 * 
 * Check if the mouse is over a rectangle and writes the status to the serial port. 
 * This example works with the Arduino program that follows below or SimpleArduinoRead.ino.
 */


import processing.serial.*;

Serial myPort;  // Create object from Serial class
int val;        // Data received from the serial port

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

void draw() {
  background(255);
  if (mouseOverRect() == true) {  // If mouse is over square,
    fill(255, 0, 0); 
    println("H");
    myPort.write('H');            // send an H to indicate mouse is over square
  } 
  else {                         // If mouse is not over square,
    fill(0);  
    println("L");
    // change color and
    myPort.write('L');              // send an L otherwise
  }
  rect(50, 50, 100, 100);         // Draw a square
  delay(100);                     // This delay is really important to avoid Arduino serial overflows.
                                  // In case you need to override it use a workaround to just send the values when they change or increase the serial speed
}

boolean mouseOverRect() { // Test if mouse is over square
  return ((mouseX >= 50) && (mouseX <= 150) && (mouseY >= 50) && (mouseY <= 150));
}

/*

 // Arduino Code Example
 
 char val; // Data received from the serial port
int ledPin = 13; // Set the pin to digital I/O 4

void setup() {
  pinMode(ledPin, OUTPUT); // Set pin as OUTPUT
  Serial.begin(9600); // Start serial communication at 9600 bps
}

void loop() {
  if (Serial.available()) { // If data is available to read,
    val = Serial.read(); // read it and store it in val
  }
  if (val == 'H') { // If H was received
    digitalWrite(ledPin, HIGH); // turn the LED on
  } 
  else {
    digitalWrite(ledPin, LOW); // Otherwise turn it OFF
  }
  delay(100); // Wait 100 milliseconds for next reading
}


 
 
 */
