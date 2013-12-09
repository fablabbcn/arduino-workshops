import processing.serial.*;

Serial myPort;        // The serial port

String valoresArduino[];



float valorArduinoA = 0.0; 
float valorArduinoB = 0.0; 
float valorArduinoC = 0.0; 

void setup () {
  size(600, 600);        
  setupSerialArduino();
  background(255);
}

void draw () {
  background(255);


  noStroke();
  rectMode(CORNER);
  fill(255, 0, 0);
  rect(40, 40, 20, valorArduinoA);

  noStroke();
  rectMode(CORNER);
  fill(255, 0, 0);
  rect(80, 40, 20, valorArduinoB);

  noStroke();
  fill(0, 0, 255); 
  translate(width/2, height/2); 
  rotate(radians(valorArduinoC));
  rectMode(CENTER);
  rect(0, 0, 50, 200);
  
}


