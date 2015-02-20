

void setup() {
  selectSerialPort();
}

void draw() {
  sendCMD('X', 100);
  sendCMD('Y', 100);
  sendCMD('C', 0);
  delay(500);
  sendCMD('D', 0);
  delay(500);
  checkForArduinoMessages();
}

