import java.awt.event.KeyEvent; // D
import javax.swing.JOptionPane; // D

String portname = null;


void openSerialPort()
{

  if (portname == null) return;
  if (myPort != null) myPort.stop();

  myPort = new Serial(this, portname, 9600);

  myPort.bufferUntil('\n');

  myPort.clear();
}

void selectSerialPort()
{
  String result = (String) JOptionPane.showInputDialog(frame, 
    "Select the serial port that corresponds to your Arduino board.", 
    "Select serial port", 
    JOptionPane.PLAIN_MESSAGE, 
    null, 
    reverse(Serial.list()), 
    0);

  if (result != null) {
    portname = result;
    openSerialPort();
  }
}

void serialEvent (Serial myPort) {
      
  try {

    String arduinoLine = myPort.readStringUntil('\n'); 

    if (arduinoLine != null) {

      arduinoLine = trim(arduinoLine);

      dataArduino = split(arduinoLine, ","); 

      if (dataArduino.length > totalSeries) {
        println("You are sending too many inputs...");
        println("Update the number of series!");
      }

      for (int i = 0; i < totalSeries; i++) {
        valuesArduino[i] = float(dataArduino[i]);
      }

      for (int i = 0; i < totalSeries; i++) {
        print(valuesArduino[i]);
        if (i < valuesArduino.length-1) {
          print(" - ");
        } else {
          print('\n');
        }
      }
    }
  } 
  catch (Exception e) {
    println(e);
    println("Serial error... ");
  }
}