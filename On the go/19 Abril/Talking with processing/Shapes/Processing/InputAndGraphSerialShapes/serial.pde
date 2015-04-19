import java.awt.event.KeyEvent; // D
import javax.swing.JOptionPane; // D

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

