int hum;
int temp;
int irLight;
int visibleLight;
int fullLight;
int luxLight;

void setup() {
  Serial.begin(9600);
  Serial.println("--------- SENSORS SETUP STARTS -----");
  setupHTU21DF();   // setup temp and hum sensor
  setupTSL25911();  // setup light sensor
  Serial.println("--------- SENSORS SETUP DONE! ------");
  delay(1000);
  Serial.println();
  Serial.println();
  printSensorNames();
}


void loop() {
  readHTU21DF();
  readTSL2591();
  printSensorValues();
  delay(500);
}


void printSensorValues() {
  
  Serial.print(hum);
  Serial.print("\t");

  Serial.print(temp);
  Serial.print("\t");

  Serial.print(irLight);
  Serial.print("\t");

  Serial.print(visibleLight);
  Serial.print("\t");

  Serial.print(fullLight);
  Serial.print("\t");

  Serial.print(luxLight);
  Serial.print("\t");

  Serial.print("\r\n");

}



void printSensorNames() {
  
  Serial.print("HUM");
  Serial.print("\t");

  Serial.print("TEMP");
  Serial.print("\t");

  Serial.print("IR_L");
  Serial.print("\t");

  Serial.print("VIS_L");
  Serial.print("\t");

  Serial.print("FULL_L");
  Serial.print("\t");

  Serial.print("LUX");
  Serial.print("\t");

  Serial.print("\r\n");

}

