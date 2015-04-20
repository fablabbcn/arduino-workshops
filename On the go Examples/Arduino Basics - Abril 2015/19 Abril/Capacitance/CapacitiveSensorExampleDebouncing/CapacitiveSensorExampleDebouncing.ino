#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */


CapacitiveSensor sensorCapacitance = CapacitiveSensor(4, 2);       // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired

long capacitanceLastValue = 0;
long lastTimeTouched = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
 if(isTouch(1000, 300, 10)){
   Serial.println("TOUCHED!");
 }
}

boolean isTouch(int timeBetweenTouches, int touchTriggerDifference, int totalReadings) {
  long capacitanceValue =  sensorCapacitance.capacitiveSensor(totalReadings);
  boolean touched = false;

  if (millis() - lastTimeTouched > timeBetweenTouches && abs(capacitanceValue - capacitanceLastValue) > touchTriggerDifference) {
    lastTimeTouched = millis();
    touched = true;
  } 
  
  capacitanceLastValue = capacitanceValue;
  return touched;
}
