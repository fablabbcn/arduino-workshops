import processing.serial.*;

Serial myPort;        // The serial port
int xPos = 1;         // horizontal position of the graph

String valoresArduino[];

void setup () {
  size(800, 300);  
  selectSerialPort();  
  background(255);
}

void draw () {
}


