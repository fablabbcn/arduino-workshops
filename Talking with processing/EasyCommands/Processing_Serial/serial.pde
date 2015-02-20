import java.awt.event.KeyEvent; // D
import javax.swing.JOptionPane; // D
import processing.serial.*;

Serial myPort;

String inputString;
boolean transmissionComplete = false;

String portname = null;


void openSerialPort()
{
  if (portname == null) return;
  if (myPort != null) myPort.stop();
  
  myPort = new Serial(this, portname, 9600);
  
  myPort.bufferUntil('\n');
}

void selectSerialPort()
{
  String result = (String) JOptionPane.showInputDialog(this,
    "Select the serial port that corresponds to your Arduino board.",
    "Select serial port",
    JOptionPane.PLAIN_MESSAGE,
    null,
    Serial.list(),
    0);
    
  if (result != null) {
    portname = result;
    openSerialPort();
  }
}


public void sendCMD(char cmd, int value) { 

  print("SENDING CMD: ");
  print(cmd);
  print(" VALUE: ");
  print(value);
  print(" >> ");
  print(cmd);     
  println(str(value));

  myPort.write(cmd);     
  myPort.write(str(value));
  myPort.write('\n');
}



void checkForArduinoMessages() {
  while (myPort.available () > 0) {
    inputString = myPort.readStringUntil('\n');
    if (inputString != null) {
      print("RECEIVED CMD: ");
      print(inputString);
    }
  }
}

