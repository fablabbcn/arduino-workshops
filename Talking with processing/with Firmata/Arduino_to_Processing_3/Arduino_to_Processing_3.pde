// Particles, by Daniel Shiffman.

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

ParticleSystem ps;
PImage sprite;  

void setup() {
  
  for (int i = 0; i < Arduino.list().length; i++) {
    println("[" + i + "] " + Arduino.list()[i]);
  }

  arduino = new Arduino(this, Arduino.list()[13], 57600); // 13 is the current port number! Check the list!
  arduino.pinMode(13, Arduino.OUTPUT);
  
  size(1024, 768, P2D);
  orientation(LANDSCAPE);
  sprite = loadImage("sprite.png");
  ps = new ParticleSystem(10000);

  // Writing to the depth buffer is disabled to avoid rendering
  // artifacts due to the fact that the particles are semi-transparent
  // but not z-sorted.
  hint(DISABLE_DEPTH_MASK);
} 

void draw () {
  background(0);
  ps.update();
  ps.display();
  
 int rawValue = arduino.analogRead(0);

 float yPosition = map(rawValue, 400, 800, 0, height);
 
 println(rawValue);
 
  ps.setEmitter(width/2,yPosition);
  
  fill(255);
  textSize(16);
  text("Frame rate: " + int(frameRate), 10, 20);
  
}