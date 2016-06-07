//////////////////////////////////////////////////
// Spice machine stepper motor web control v1.0 //
//////////////////////////////////////////////////

// Justin Ashton 
// (c) J. Ashton & Company, Inc., 2016
// 
// Hardware setup: Particle Photon, Easy Driver v4.5, NEMA 17, 12v power
//
// This sketch is designed to be controlled by the file: 
// "spice machine web control v1.0.hmtl". Please make sure to 
// update your Photon keys and access token in the html file.

int steps = 0;
int dly = 1000; //default delay in uSecs for speed control
int rotateSteps(String numSteps);
int changeDelay(String newDelay);

//Declare pin mapping
int dir = D0;
int stp = D1;

void setup()
{
  pinMode(stp, OUTPUT);
  pinMode(dir, OUTPUT);
  digitalWrite(dir, LOW);
  digitalWrite(stp, LOW);
  Serial.begin(9600); //Open Serial connection for debugging
  Serial.println("Starting up the Spice Machine web control...");
  Serial.println();
  Particle.function("numsteps", rotateSteps); //cloud function to update then drive # steps
  Particle.function("uSecsDelay", changeDelay); //cloud function to update delay (rot speed)
  
}

void loop()
{
}

int rotateSteps(String numSteps) 
{
    steps = numSteps.toInt();
    Serial.print("updated steps: ");
    Serial.println(steps);
    if(steps > 0 && steps < 6401){
        for(int i=0; i < steps; i++){ 
            digitalWrite(stp, HIGH); 
            delayMicroseconds(dly); 
            digitalWrite(stp, LOW); 
            delayMicroseconds(dly); 
            } 
            return 1; 
            } else {
                Serial.println("Steps out of range 1-6400");
                return -1;
                }
}

int changeDelay(String newDelay) 
{
    int temp = newDelay.toInt();
    Serial.print("updated delay: ");
    Serial.println(temp);
    if(temp > 99 && temp < 1001){
        dly = temp;
        return 1;
    } else {
        Serial.println("Delay out of range 100-1000 microSecs");
        return -1;
        
    }
    
}
