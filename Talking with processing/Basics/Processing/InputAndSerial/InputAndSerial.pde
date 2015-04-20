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
  selectSerialPort();
}

void draw () {
}

void serialDraw() {
  float sensor1 = valuesArduino[0];
  ellipse(sensor1, sensor1, 100, 100);
}

