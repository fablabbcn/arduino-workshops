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
 */

import processing.serial.*;

import cc.arduino.*;

Arduino arduino;

void setup() {
  size(300, 300);
  smooth();
  noStroke();
  colorMode(HSB);
  
  arduino = new Arduino(this, Arduino.list()[0], 57600);
  arduino.pinMode(13, Arduino.OUTPUT);
}

void draw() {
  background(255);
  int rawValue = arduino.analogRead(0);
  float mappedDiameter = map(rawValue, 0, 1023, 0, height-20);
  float mappedColor = map(rawValue, 0, 1023, 0, 255);
  fill(mappedColor, 255, 255);
  ellipse(width/2, height/2, mappedDiameter, mappedDiameter);
}

