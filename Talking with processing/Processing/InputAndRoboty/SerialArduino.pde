
void setupSerialArduino() {
  println(Serial.list());
  myPort = new Serial(this, Serial.list()[9], 9600);
  myPort.bufferUntil('\n');
}

void serialEvent (Serial myPort) {
  String lineaArduino = myPort.readStringUntil('\n'); 

  if (lineaArduino != null) {
    lineaArduino = trim(lineaArduino); 

    valoresArduino = split(lineaArduino, ","); 

    valorArduinoA = float(valoresArduino[0]); 
    valorArduinoB = float(valoresArduino[1]); 
    valorArduinoC = float(valoresArduino[1]); 

    print(valorArduinoA);
    print(" - ");
    print(valorArduinoB);
    print(" - ");
    println(valorArduinoC);
    
    valorArduinoA = map(valorArduinoA, 0, 10, 0, 200);

    valorArduinoB = map(valorArduinoB, 0, 10, 0, 200);
    
    valorArduinoC = map(valorArduinoC, 0, 180, 0, 180);

  }
}

