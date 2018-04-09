import processing.serial.*;

// Importante añadir un delay mínimo de 10 millis >> delay(10)

int totalSeries = 1; // Ajustar a la cantidad de valores. 

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
  drawAllLines();
}

void drawAllLines() {
  for (int i = 0; i < valuesArduino.length; i++) {
    float lineColor = getSeriesHue(i, valuesArduino.length);
    drawLine(valuesArduino[i], 1023, lineColor);
  }
  nextCycle();
}

float getSeriesHue(int seriesID, int totalSeries) {
  float hue =  map(seriesID, 0, totalSeries-1, 0, 255);
  return hue;
}

void drawLine(float inputValue, float max, float seriesHue) {
  float mappedValue = map(inputValue, 0, max, 5, height);
  stroke(seriesHue, 255, 255, 160);
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