//////////////////////////////////////////
// Particle Photon load cell scale v1.0 //
//////////////////////////////////////////

// Justin Ashton 
// (c) J. Ashton & Company, Inc., 2016
// 
// Borrowed code from: https://github.com/juano2310/HX711ADC
//
// Hardware setup: Particle Photon, HX711 load cell amp from SparkFun, load cell strain gauge
//
// This sketch is designed to help you calibrate your load cell scale.
// Run this sketch and open a serial port for input/output. The first time you run this
// sketch, enter the number "1" to reset any existing calibration. Then type "2" to
// zero out the scale (tare). Place a known weight on the scale, then type "3" to measure 
// and output the weight on the scale. The calibration parameter needed in .set_scale() is 
// equal to the value output in step #3 divided by the mass of the known weight. Enter it 
// inside the parentheses of the scale.set_scale() function under void setup().

// This #include statement was automatically added by the Particle IDE.
#include "application.h"
#include "HX711ADC/HX711ADC.h"

char user_input;

//HX711ADC(byte dout, byte pd_sck, byte gain = 128);
HX711ADC scale(D3, D2); //D3 to DAT and D2 to CLK pin on SparkFun load cell amp board


void setup() {
  Serial.begin(9600);
  scale.set_scale(1610.f); // to calibrate scale, change this parameter and be sure to add ".f" after
  Serial.println("HX711ADC Calibration Sketch");
  Serial.println("Menu: Enter number");
  Serial.println("m. List menu.");
  Serial.println("1. Reset scale calibration.");
  Serial.println("2. Zero out scale.");
  Serial.println("3. Weigh scale.");
  Serial.println();

}

void loop() {
  
  while(Serial.available()){
      user_input = Serial.read(); //Read user input and trigger appropriate action
      switch (user_input){
          case '1':
          Serial.println("1. Reset scale calibration."); //uses function .set_scale to reset the calibration value
          scale.set_scale();
          Serial.println("Initialized");
          delay(250);
          break;
          
          case '2':
          Serial.println("2.Zero out scale."); //use function .tare to zero out scale
          scale.tare(); 
          Serial.println("Zeroed.");
          delay(250);
          break;
          
          case '3':
          Serial.println("3. Weigh scale."); // reads and outputs an average value of weight.
          Serial.println(scale.get_units(10));
          delay(250);
          break;
          
          case 'm':
          Serial.println("Menu: Enter number");
          Serial.println("m. List menu.");
          Serial.println("1. Reset scale calibration.");
          Serial.println("2. Zero out scale.");
          Serial.println("3. Weigh scale.");
          Serial.println();
          delay(250);
          break;
          
          default:
          Serial.println("Invalid option entered.");
          }
          
          }
}


