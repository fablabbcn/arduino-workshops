import processing.serial.*;

Serial myPort;        // The serial port
int xPos = 1;         // horizontal position of the graph

String valoresArduino[];

void setup () {
  size(800, 800);  
  selectSerialPort();  
  background(255);
}

void draw () {
}

void serialEvent (Serial myPort) {
  String lineaArduino = myPort.readStringUntil('\n'); 

  if (lineaArduino != null) {
    lineaArduino = trim(lineaArduino); 

    valoresArduino = split(lineaArduino, ","); 

    float valorArduinoA = float(valoresArduino[0]); 

    println(valorArduinoA);

    float diameter = map(valorArduinoA, 0, 1023, 5, height);

    float colorFill = map(valorArduinoA, 0, 1023, 0, 255);

    float rectPosition = map(valorArduinoA, 0, 1023, 0, width);

    colorMode(HSB);
    background(255);
    fill(colorFill, 255, 255);
    noStroke();
    ellipse(width/2, height/2, diameter, diameter);
    fill(100, 255, 255);
    rect(rectPosition, height/2, 100, 100);
  }
}

