#include <Servo.h>

/* 
 
 Adafruit - Thermistor Code
 
 
 */



// which analog pin to connect
#define THERMISTORPIN A0         
// resistance at 25 degrees C
#define THERMISTORNOMINAL 3300      
// temp. for nominal resistance (almost always 25 C)
#define TEMPERATURENOMINAL 21   
// how many samples to take and average, more takes longer
// but is more 'smooth'
#define NUMSAMPLES 30
// The beta coefficient of the thermistor (usually 3000-4000)
#define BCOEFFICIENT 3950
// the value of the 'other' resistor
#define SERIESRESISTOR 1000    

int samples[NUMSAMPLES];

int rgb_colors[3]; 

int hue;
int saturation;
int brightness;

Servo termoServo;  


void setup() {
  Serial.begin(9600);
  termoServo.attach(9); 
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {

  float temp = readTemperature();
  
  float movePoint = map(temp, 19, 26, 0, 180);
    
  termoServo.write(movePoint);

}

void makeRGBFab(int red, int green, int blue){
  analogWrite(9,red);    
  analogWrite(10, green);    
  analogWrite(11, blue);    
}

void makeRGBGreen(int red, int green, int blue){
  analogWrite(9,255-red);    
  analogWrite(10, 255-green);    
  analogWrite(11, 255-blue);    
}

float readTemperature() {
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

  return steinhart;
}



