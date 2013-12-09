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

void serialEvent (Serial myPort) {
  String lineaArduino = myPort.readStringUntil('\n'); 

  if (lineaArduino != null) {
    lineaArduino = trim(lineaArduino); 

    valoresArduino = split(lineaArduino, ","); 

    float valorArduinoA = float(valoresArduino[0]); 
    float valorArduinoB = float(valoresArduino[1]); 

    print(valorArduinoA);
    print(" - ");
    println(valorArduinoB);

    valorArduinoA = map(valorArduinoA, 0, 300, 5, height);
    
    valorArduinoB = map(valorArduinoB, 0, 300, 5, height);

    stroke(0, 0, 255, 160);
    line(xPos, height, xPos, height - valorArduinoA);

    stroke(0, 255, 0, 160);
    line(xPos, height, xPos, height - valorArduinoB);

    if (xPos >= width) {
      xPos = 0;
      background(255);
    } 
    else {
      xPos++;
    }
  }
}

