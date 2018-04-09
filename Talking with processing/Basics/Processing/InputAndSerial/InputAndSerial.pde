import processing.serial.*;

int totalSeries = 1; 

Serial myPort;        // The serial port
int xPos = 1;         // horizontal position of the graph
long lastSerialReception = 0;

String dataArduino[];
float[] valuesArduino = new float[totalSeries];


void setup () {
  size(800, 800);  
  background(255);
  noStroke();
  selectSerialPort();
}

void draw () {
  background(0);
  float sensor1 = valuesArduino[0];
  fill(255, 0, 0);
  ellipse(width/2, height/2, sensor1, sensor1);
}