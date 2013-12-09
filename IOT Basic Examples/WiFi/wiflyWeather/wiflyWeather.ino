/*
 * WiFlyHQ Example httpclient.ino
 *
 * This sketch implements a simple Web client that connects to a 
 * web server, sends a GET, and then sends the result to the 
 * Serial monitor.
 *
 * This sketch is released to the public domain.
 *
 */

#include <WiFlyHQ.h>

#include <SoftwareSerial.h>
SoftwareSerial wifiSerial(2,3);

WiFly wifly;

String currentLine = "";            // string to hold the text from server
String temp = "";                  // string to hold the temp
String rain = "";                  // string to hold the temp

boolean readingtemp = false;       // if you're currently reading the temp
boolean readingrain = false;       // if you're currently reading the temp

int steps = 0;

/* Change these to match your WiFi network */
const char mySSID[] = "IAAC-WIFI";
const char myPassword[] = "enteriaac2013";

const char site[] = "api.worldweatheronline.com";


void terminal();

void setup()
{
  char buf[32];

  Serial.begin(115200);
  Serial.println("Starting");
  Serial.print("Free memory: ");
  Serial.println(wifly.getFreeMemory(),DEC);

  wifiSerial.begin(9600);
  if (!wifly.begin(&wifiSerial, &Serial)) {
    Serial.println("Failed to start wifly");
    terminal();
  }

  /* Join wifi network if not already associated */
  if (!wifly.isAssociated()) {
    /* Setup the WiFly to connect to a wifi network */
    Serial.println("Joining network");
    wifly.setSSID(mySSID);
    wifly.setPassphrase(myPassword);
    wifly.enableDHCP();

    if (wifly.join()) {
      Serial.println("Joined wifi network");
    } 
    else {
      Serial.println("Failed to join wifi network");
      terminal();
    }

  } 
  else {
    Serial.println("Already joined network");
  }

  //terminal();

  Serial.print("MAC: ");
  Serial.println(wifly.getMAC(buf, sizeof(buf)));
  Serial.print("IP: ");
  Serial.println(wifly.getIP(buf, sizeof(buf)));
  Serial.print("Netmask: ");
  Serial.println(wifly.getNetmask(buf, sizeof(buf)));
  Serial.print("Gateway: ");
  Serial.println(wifly.getGateway(buf, sizeof(buf)));

  wifly.setDeviceID("Wifly-WebClient");
  Serial.print("DeviceID: ");
  Serial.println(wifly.getDeviceID(buf, sizeof(buf)));

  if (wifly.isConnected()) {
    Serial.println("Old connection active. Closing");
    wifly.close();
  }



  if (wifly.open(site, 80)) {
    Serial.print("Connected to ");
    Serial.println(site);

    /* Send the request */
    wifly.println("GET http://api.worldweatheronline.com/free/v1/weather.ashx?q=Barcelona&format=xml&num_of_days=1&key=wg427m45yycy7sdwnngzbxy4 HTTP/1.0");
    wifly.println();

  } 
  else {
    Serial.println("Failed to connect");
  }
}

void loop()
{
  if (wifly.available() > 0) {
    char inChar = wifly.read();

    // add incoming byte to end of line:
    currentLine += inChar; 

    // if you get a newline, clear the line:
    if (inChar == '\n') {
       Serial.println(currentLine);   
      currentLine = "";
    } 
    // if the current line ends with <localtemp>, it will
    // be followed by the temp:
    if ( currentLine.endsWith("<temp_C>")) {
      // temp is beginning. Clear the temp string:
      readingtemp= true; 
      temp = "";
    }
    
    if ( currentLine.endsWith("<precipMM>")) {
      // temp is beginning. Clear the temp string:
      readingrain= true; 
      rain = "";
    }
    // if you're currently reading the bytes of the temp,
    // add them to the temp String:
    if (readingtemp) {
      if (inChar != '<') {
        temp += inChar;
      } 
      else {
        // if you got a "<" character,
        // you've reached the end of the temp:
        steps++;
        readingtemp = false;
        Serial.println(temp);   
        // close the connection to the server:

      }
    }
    
    if (readingrain) {
      if (inChar != '<') {
        rain += inChar;
      } 
      else {
        // if you got a "<" character,
        // you've reached the end of the temp:
                steps++;

        readingrain = false;
        Serial.println(rain);   
        // close the connection to the server:
//        wifly.close(); 
      }
    }
    
    if (steps == 2){
      wifly.close(); 
    }
    
  }

  if (Serial.available() > 0) {
    wifly.write(Serial.read());
  }
}

/* Connect the WiFly serial to the serial monitor. */
void terminal()
{
  while (1) {
    if (wifly.available() > 0) {
      Serial.write(wifly.read());
    }


    if (Serial.available() > 0) {
      wifly.write(Serial.read());
    }
  }
}

