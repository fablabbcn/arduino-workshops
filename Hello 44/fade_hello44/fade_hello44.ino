int brightness = 0;    

void setup() {
  pinMode(7, OUTPUT);
  pinMode(3, INPUT);
}

void loop() {

  if (!digitalRead(3)) {
    if(brightness >= 255) {
      brightness = 0;
    }
    brightness++;
  } 
  
  analogWrite(7, brightness);
}
