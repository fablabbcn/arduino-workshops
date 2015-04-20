/* 
 
 Thermistor Code
 
 Based on Adafruit Thermistor Code
 
*/

// which analog pin to connect
int const THERMISTORPIN = A0;         
// resistance at 25 degrees C
int const THERMISTORNOMINAL = 50000; // For Seeedstudio Kit thermistor   
// temp. for nominal resistance (almost always 25 C)
int const TEMPERATURENOMINAL = 25;   
// how many samples to take and average, more takes longer
// but is more 'smooth'
int const NUMSAMPLES = 5;
// The beta coefficient of the thermistor (usually 3000-4000)
int const BCOEFFICIENT = 3975; // For Seeedstudio Kit thermistor
// the value of the 'other' resistor
int const SERIESRESISTOR = 10000; // We use a 10KOhm Resistor    
 
int samples[NUMSAMPLES];
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
  uint8_t i;
  float average;
 
  // take N samples in a row, with a slight delay
  for (i=0; i< NUMSAMPLES; i++) {
   samples[i] = analogRead(THERMISTORPIN);
   delay(10);
  }
 
  // average all the samples out
  average = 0;
  for (i=0; i< NUMSAMPLES; i++) {
     average += samples[i];
  }
  average /= NUMSAMPLES;
 
  Serial.print("Average analog reading "); 
  Serial.println(average);
 
  // convert the value to resistance
  average = 1023 / average - 1;
  average = SERIESRESISTOR / average;
  Serial.print("Thermistor resistance "); 
  Serial.println(average);
 
  float steinhart;
  steinhart = average / THERMISTORNOMINAL;     // (R/Ro)
  steinhart = log(steinhart);                  // ln(R/Ro)
  steinhart /= BCOEFFICIENT;                   // 1/B * ln(R/Ro)
  steinhart += 1.0 / (TEMPERATURENOMINAL + 273.15); // + (1/To)
  steinhart = 1.0 / steinhart;                 // Invert
  steinhart -= 273.15;                         // convert to C
 
  Serial.print("Temperature "); 
  Serial.print(steinhart);
  Serial.println(" *C");
 
  delay(1000);
}
