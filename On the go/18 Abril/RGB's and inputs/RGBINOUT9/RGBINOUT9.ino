int rgb_colors[3]; 

int redLedPin = 9;
int greenLedPin = 10;
int blueLedPin = 11;

void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
}

void loop() {
  // read the pot
  int rawValue = analogRead(A0);
  // escale the input
  int hue = map(rawValue, 0, 1023, 0, 255);
  // from HSB (Hue/Saturation/Brightness) to RGB (Red/Green/blue)
  getRGB(hue,255,255,rgb_colors);  
  // analogWrite each color LED  
  makeColor(rgb_colors[0], rgb_colors[1], rgb_colors[2]);
}

void makeColor(int red, int green, int blue) {
  // For common anode RGB Led's we invert the signal 
  // max light = 0 | min light = 255
  analogWrite(redLedPin, red);
  analogWrite(greenLedPin, green);
  analogWrite(blueLedPin, blue);
}





