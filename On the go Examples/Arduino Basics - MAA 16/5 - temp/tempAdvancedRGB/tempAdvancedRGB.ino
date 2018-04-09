int rgb_colors[3]; 

int redLedPin = 9;
int greenLedPin = 10;
int blueLedPin = 11;

void setup(void) {
  Serial.begin(9600);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);}

void loop(void) {
  float temp = getTemp();
  // escale the input from 10 ªC to 25ªC cover show the whole range
  int hue = map(temp, 10, 25, 0, 255); 
  // from HSB (Hue/Saturation/Brightness) to RGB (Red/Green/blue)
  getRGB(hue,255,255,rgb_colors);  
  // analogWrite each color LED  
  makeColor(rgb_colors[0], rgb_colors[1], rgb_colors[2]);
}

void makeColor(int red, int green, int blue) {
  // For common anode RGB Led's we invert the signal 
  // max light = 0 | min light = 255
  analogWrite(redLedPin, 255-red);
  analogWrite(greenLedPin, 255-green);
  analogWrite(blueLedPin, 255-blue);
}



