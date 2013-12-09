import processing.serial.*;

Serial myPort;        // The serial port

String valoresArduino[];



float valorArduinoA = 0.0; 
float valorArduinoB = 0.0; 

void setup () {
  size(800, 800);        
  setupSerialArduino();
  background(255);
}

void draw () {
  background(255);
  if (valorArduinoA > 200) {
    fill(255, 0, 0);
  } 
  else {
    fill(0, 255, 0);
  }
  noStroke();
  ellipse(valorArduinoA, valorArduinoB, 10, 10);
}



