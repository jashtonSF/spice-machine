/////////////////////////////////////////////////////////////////////////////////
// Spice machine stepper motor with automated measurement and web control v1.0 //
/////////////////////////////////////////////////////////////////////////////////

// Justin Ashton 
// (c) J. Ashton & Company, Inc., 2016
// 
// Hardware setup: Particle Photon, Easy Driver v4.5, SparkFun HX711 load cell amp,
// NEMA 17, 12v power, load cell (strain gauge)
//
// This sketch is designed to be controlled by the file: 
// "spice machine web w load cell v1.0.html". Please make sure to 
// update your Photon keys and access token in the html file. 
//
// Important Note: This sketch assumes you have already calibrated your load cell
// and have entered the calibration value in the .set_scale() function below before 
// running.
//
// Some code from: https://github.com/juano2310/HX711ADC



// This #include statement was automatically added by the Particle IDE.
#include "application.h"
#include "HX711ADC/HX711ADC.h"

// Local variables
//int steps = 0;
int dly = 1000; //default delay in uSecs for speed control
float weight = 0; //target weight to dispense (via web input)
char user_input; //capture serial input

//Exposed cloud functions
int changeDelay(String newDelay);
int dispenseWeight(String newWeight);
int tareScale(String dummyVar);

//Declare Photon pin mapping
int dir = D0;
int stp = D1;
int sck = D2;
int dat = D3;

HX711ADC scale(dat, sck); //HX711ADC constructor(byte dout, byte pd_sck, byte gain = 128);


void setup()
{
  pinMode(stp, OUTPUT);
  pinMode(dir, OUTPUT);
  //pins sck and dat already declared by the 'HX711ADC scale(dat, sck);' constructor
  
  digitalWrite(dir, HIGH); // to reverse motor direction, change DIR either "HIGH or LOW"
  digitalWrite(stp, LOW);
  
  Serial.begin(9600); //Open Serial connection for debugging
  Serial.println("Starting up the Spice Machine...");
  Serial.println();
  
  scale.set_scale(1640.f); //to calibrate scale, change this parameter and be sure to add ".f" after
  scale.tare();	
  
  Particle.function("uSecsDelay", changeDelay); //cloud function to update delay (motor rot speed)
  Particle.function("targetWeight", dispenseWeight); //cloud function to update target weight to dispense next (grams)
  Particle.function("zeroScale", tareScale); //cloud function to zero the scale (tare)
}

void loop()
{
}

int tareScale(String dummyVar) // method to remotely tare scale
{
    if(dummyVar != NULL){
        scale.tare();	
        Serial.println("Zeroing out scale...");
        Serial.print("Weight is: \t"); 
        Serial.print(scale.get_units(5));
        Serial.println(" grams");
        return 1;
        } else {
            Serial.println("Error with tareScale!");
            return -1;
        }
        
        }

int changeDelay(String newDelay) // method to remotely update motor rotational speed
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

int dispenseWeight(String newWeight) // method to remotely dispense a spice using stepper motor to a desired target weight using load cell feedback
{
    float tempWeight = 0; //create a  variable to keep track of current weight over time
    int counter = 0;
    weight = strtof(newWeight, NULL); //convert target weight to float
    if(weight >= 0 && weight < 101){
        Serial.print("new target to dispense: \t");
        Serial.print(weight);
        Serial.println(" grams");
        while(tempWeight < weight) {
            digitalWrite(stp, HIGH); 
            delayMicroseconds(dly); 
            digitalWrite(stp, LOW); 
            delayMicroseconds(dly); 
            counter++;
            if(counter % 500 == 0){   //  counter modulo represents number of motor steps before checking weight. Checking weight often slows down program
                tempWeight = scale.get_units(5); // reads and outputs average of 5 (weight - tare) weight measurements
                Serial.print("Weight is: \t"); 
                Serial.print(tempWeight);
                Serial.println(" grams");
                }
                
                }
                return 1;
                } else {
                    Serial.println("Target weight must be between 0 and 100 grams!");
                    return -1; 
                    }
                    
                    }

