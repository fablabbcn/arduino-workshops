/*
  Web Server
 
 A simple web server that shows the value of the analog input pins.
 using an Arduino Wiznet Ethernet shield. 
 
 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13
 * Analog inputs attached to pins A0 through A5 (optional)
 
 created 18 Dec 2009
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe
 
 */

#include <SPI.h>
#include <Ethernet.h>


// which analog pin to connect
#define THERMISTORPIN A2         
// resistance at 25 degrees C
#define THERMISTORNOMINAL 3300      
// temp. for nominal resistance (almost always 25 C)
#define TEMPERATURENOMINAL 21   
// how many samples to take and average, more takes longer
// but is more 'smooth'
#define NUMSAMPLES 5
// The beta coefficient of the thermistor (usually 3000-4000)
#define BCOEFFICIENT 3950
// the value of the 'other' resistor
#define SERIESRESISTOR 1000    

int samples[NUMSAMPLES];

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = { 
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,2,200);

// Initialize the Ethernet server library
// with the IP address and port you want to use 
// (port 80 is default for HTTP):
EthernetServer server(80);

boolean isOn = false;


void setup() {
 // Open serial communications and wait for port to open:
  Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }


  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
  pinMode(9, OUTPUT);
}


void loop() {
  
  
  float temp = readTemperature();
  
  if (temp > 22.0) {
    isOn = true;
    digitalWrite(9, HIGH);
  } else {
    isOn = false;
    digitalWrite(9, LOW);
  }


  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
	  client.println("Refresh: 5");  // refresh the page automatically every 5 sec
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          client.println("<body style='background-color: #EFEFEF;'>");


          


          client.println("<h1 style='color: #00FF88; font-size: 220px; font-family: Helvetica, Arial; font-weight: bold;'>");
          client.println(temp);
          
    

          client.println(" &#176;C </h1>");


          if (isOn == true) {
            client.println("<p style='color: #37E6FA; font-size: 120px; font-family: Helvetica, Arial; font-weight: bold;'> on </p>");
          } else {
            client.println("<p style='color: #FA3737; font-size: 120px; font-family: Helvetica, Arial; font-weight: bold;'> off </p>");
          }
          client.println("</body>");

          client.println("</html>");
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } 
        else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("client disonnected");
  }
}

