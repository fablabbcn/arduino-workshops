
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

    print(valorArduinoA);
    print(" - ");
    println(valorArduinoB);

    valorArduinoA = map(valorArduinoA, 0, 1023, 0, width);

    valorArduinoB = map(valorArduinoB, 0, 1023, 0, height);
  }
}

