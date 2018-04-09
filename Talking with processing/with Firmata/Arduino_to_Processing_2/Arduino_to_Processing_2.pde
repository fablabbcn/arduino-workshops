/* 
 
 Connecting Arduino to Processing | THE EASY WAY
 
 Example using the Firmata library on Arduino 
 and the Arduino library on Processing.
 
 1. On Arduino go to "Examples > Firmata" 
 and load the StandardFirmware to your Arduino board.
 
 2. Download the Arduino library for Processing 
 and copy it to your libraries folder on the sketch Folder.
 http://www.arduino.cc/playground/Interfacing/Processing
 
 3. Conect any analog input (potentiometer, etc...) 
 to the Arduino analog pin 0.
 
 4. Run the sketch.
 
 
 FABLABBCN | Guillem Camprodon
 
 */

import processing.serial.*;

import cc.arduino.*;

Arduino arduino;

void setup() {
  size(300, 300);
  smooth();
  noStroke();

  for (int i = 0; i < Arduino.list().length; i++) {
    println("[" + i + "] " + Arduino.list()[i]);
  }

  arduino = new Arduino(this, Arduino.list()[13], 57600); // 13 is the current port number! Check the list!
  arduino.pinMode(13, Arduino.OUTPUT);
}

void draw() {
}

void keyPressed() {
  if (key == 'A' || key == 'a') {
    arduino.digitalWrite(13, Arduino.HIGH);
    background(255, 0, 0);
  }
} 

void keyReleased() {
  if (key == 'A' || key == 'a') {
     background(255);
    arduino.digitalWrite(13, Arduino.LOW);
  }
}