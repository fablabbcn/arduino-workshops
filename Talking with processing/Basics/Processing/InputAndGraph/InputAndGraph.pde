import processing.serial.*;

Serial myPort;        // The serial port
int xPos = 1;         // horizontal position of the graph

String valoresArduino[];

void setup () {
  size(800, 300);        
  // I know that the first port in the serial list on my mac
  // is always my  FTDI adaptor, so I open Serial.list()[5].
  // On Windows machines, this generally opens COM1.
  // Open whatever port is the one you're using.
  String[] portsAvailable = Serial.list();           // Get a List of all the serial ports available
  for (int i=0; i <  portsAvailable.length; i++) {   // Iterate over the list and print them on console for selection
    print("[" + i + "]\t");    
    println(portsAvailable[i]);
  }
  String portName = portsAvailable[5];               // "5" is our selection            
  myPort = new Serial(this, portName, 9600);         // Connect to the specified port
  myPort.bufferUntil('\n');
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

