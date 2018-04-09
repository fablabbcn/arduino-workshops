
// Example:

int x = 0;
int y = 0;

// End example.




void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{
  checkCommands();


  // Example:

  if (x > 40 && y < 30) {
    analogWrite(9, 40);
  } 
  else {
    analogWrite(9, 0);
  }

  // End example.

}

void runCommand(char commands, int value){
  switch (commands) {
  case 'X':   
    x = value;
    break;
  case 'Y':
    y = value;
    break;
  case 'C':   
    digitalWrite(13, HIGH);
    break;
  case 'D':   
    digitalWrite(13, LOW);
    break;
  }
}




