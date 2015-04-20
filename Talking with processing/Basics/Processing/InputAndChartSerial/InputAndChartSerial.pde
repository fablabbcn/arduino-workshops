import processing.serial.*;

int totalSeries = 1;

Serial myPort;        // The serial port
int xPos = 1;         // horizontal position of the graph
long lastSerialReception = 0;

String dataArduino[];
float[] valuesArduino = new float[totalSeries];


void setup () {
  size(800, 300);  
  colorMode(HSB);
  selectSerialPort();  
  background(255);
}

void draw () {
}

void serialDraw() {
  drawAllLines();
}

void drawAllLines() {
  for (int i = 0; i < valuesArduino.length; i++) {
    drawLine(valuesArduino[i], 1023, 255);
  }
  nextCycle();
}

float getSeriesHue(int seriesID, int totalSeries) {
  float hue =  map(seriesID, 0, totalSeries, 0, 255);
  return hue;
}

void drawLine(float inputValue, float max, float seriesColor) {
  float mappedValue = map(inputValue, 0, max, 5, height);
  stroke(seriesColor, 255, 255, 160);
  line(xPos, height, xPos, height - mappedValue);
}

void nextCycle() {
  if (xPos >= width) {
    xPos = 0;
    background(255);
  } 
  else {
    xPos++;
  }
}

