/* Test code for my parent's Christmas gift. there will be 7 bulbs each controlled by separate pins
on arduino uno. RF transmitter button presses will increment 0-7 then reset to move lights down the
board.
*/

// constants below

const int buttonPin = 2;  //transmitter fob button press input
const int led1Pin = 3;    //LED for rows 1-7 pins
const int led2Pin = 4;
const int led3Pin = 5;
const int led4Pin = 6;
const int led5Pin = 7;
const int led6Pin = 8;
const int led7Pin = 9;

//variables below

int buttonState = 0;         // variable for reading the RF transmitter button status
int count_value =0;
int prestate =0;

void setup() {
  // initialize the LED pins as outputs:
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(led4Pin, OUTPUT);
  pinMode(led5Pin, OUTPUT);
  pinMode(led6Pin, OUTPUT);
  pinMode(led7Pin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, then the buttonState is HIGH:
  if (buttonState == HIGH && prestate == 0) {
    count_value++;
    
    prestate = 1;
  } else if(buttonState == LOW) {
    prestate = 0;
  }
  
  switch (count_value) {
  
  case 1:
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
    digitalWrite(led4Pin, LOW);
    digitalWrite(led5Pin, LOW);
    digitalWrite(led6Pin, LOW);
    digitalWrite(led7Pin, LOW);
    break;
    
  case 2:
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, HIGH);
    digitalWrite(led3Pin, LOW);
    digitalWrite(led4Pin, LOW);
    digitalWrite(led5Pin, LOW);
    digitalWrite(led6Pin, LOW);
    digitalWrite(led7Pin, LOW);   
    break;
    
  case 3:
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, HIGH);
    digitalWrite(led4Pin, LOW);
    digitalWrite(led5Pin, LOW);
    digitalWrite(led6Pin, LOW);
    digitalWrite(led7Pin, LOW);
    break;
    
  case 4:
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
    digitalWrite(led4Pin, HIGH);
    digitalWrite(led5Pin, LOW);
    digitalWrite(led6Pin, LOW);
    digitalWrite(led7Pin, LOW);
    break;
    
  case 5:
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
    digitalWrite(led4Pin, LOW);
    digitalWrite(led5Pin, HIGH);
    digitalWrite(led6Pin, LOW);
    digitalWrite(led7Pin, LOW);
    break; 
    
  case 6:
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
    digitalWrite(led4Pin, LOW);
    digitalWrite(led5Pin, LOW);
    digitalWrite(led6Pin, HIGH);
    digitalWrite(led7Pin, LOW);
    break;
    
  case 7:
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
    digitalWrite(led4Pin, LOW);
    digitalWrite(led5Pin, LOW);
    digitalWrite(led6Pin, LOW);
    digitalWrite(led7Pin, HIGH);
    break;
  
  default:
    count_value = 0;
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
    digitalWrite(led4Pin, LOW);
    digitalWrite(led5Pin, LOW);
    digitalWrite(led6Pin, LOW);
    digitalWrite(led7Pin, LOW);
    break;
  
}
}
