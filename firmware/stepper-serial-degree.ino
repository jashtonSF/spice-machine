
//////////////////////////////////////////////
// Spice machine stepper motor control v1.0 //
//////////////////////////////////////////////

// Justin Ashton 
// (c) J. Ashton & Company, Inc., 2016
// 
// some code modified from Dan Thompson http://danthompsonsblog.blogspot.com/ &
// from http://www.schmalzhaus.com/EasyDriver 
//
// Hardware setup: Particle Photon, Easy Driver v4.5, NEMA 17, 12v power
//
// This sketch requires a serial connection to keyboard for input
// of numbers to control motor revolutions. For Mac, I used the
// program 'screen' on terminal. You can use terminal commmand
// 'ls /dev/tty.*' to identify the usb serial connection, then use 
// command 'screen /dev/tty.YOURDEVICE 9600' to connect... you will 
// replace 'YOURDEVICE' with your usb serial connection identified above.
//
// Enter '1' for full revolution
// Enter '2' for half revolution
// Enter '3' for quarter revolution
// Enter '4' for eigth revolution



//Declare pin mapping
int dir = D0;
int stp = D1;


char user_input;


void setup() {
  pinMode(stp, OUTPUT);
  pinMode(dir, OUTPUT);
  digitalWrite(dir, LOW);
  digitalWrite(stp, LOW);
  Serial.begin(9600); //Open Serial connection for keyboard control
  Serial.println("Begin motor control");
  Serial.println();
}

void loop() {
  
  while(Serial.available()){
      user_input = Serial.read(); //Read user input and trigger appropriate action
      switch (user_input){
          case '1':
          Serial.println("1. Full revolution.");
          rotateDeg(360, .1);
          delay(500);
          break;
          
          case '2':
          Serial.println("2. 1/2 revolution.");
          rotateDeg(180, .1); 
          delay(500);
          break;
          
          case '3':
          Serial.println("3. 1/4 revolution.");
          rotateDeg(90, .1); 
          delay(500);
          break;
          
          case '4':
          Serial.println("4. 1/8 revolution.");
          rotateDeg(45, .1); 
          delay(500);
          break;
          
          default:
          Serial.println("Invalid option entered.");
          //Print function list for user selection
          Serial.println("Enter number for motor control");
          Serial.println("1. Full revolution.");
          Serial.println("2. 1/2 revolution.");
          Serial.println("3. 1/4 revolution.");
          Serial.println("4. 1/8 revolution.");
          Serial.println();
      }
      
      }
  }

void rotateDeg(float deg, float speed){ 
  //rotate a specific number of degrees
  //speed is any number from .01 -> 1 with 1 being fastest - Slower is stronger
  
  digitalWrite(dir,LOW); // rotates motor clockwise; change to HIGH for reverse

  int steps = abs(deg)*(1/0.225);  // designed for Easy Driver default: 1/8 step
  float usDelay = (1/speed) * 70;

  for(int i=0; i < steps; i++){ 
    digitalWrite(stp, HIGH); 
    delayMicroseconds(usDelay); 
    digitalWrite(stp, LOW); 
    delayMicroseconds(usDelay); 
  } 
}
