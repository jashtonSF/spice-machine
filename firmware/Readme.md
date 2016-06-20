# folder for spice machine firmware files

###Hardware setup for the stepper firmware sketches in this folder:
![alt tage](https://github.com/jashtonSF/spice-machine/blob/master/firmware/Spice-stepper-serial-degree%20v1.0.jpg)

###"web-stepper-load-cell.ino"
This sketch uses the html file "spice machine web w load cell v1.0.html" located in this repo's software folder, to provide browser control of the spice machine prototype stepper motor, the load cell, and additional functionality. This sketch exposes three cloud functions: "targetWeight" to select a desired target weight of spices to dispense, "uSecsDelay" to change the delay (for motor rotational speed control), and "zeroScale" to tare the load cell scale. The motor direction is hard coded, so to reverse motor direction, change the DIR pin from "LOW" to "HIGH" (or vice versa) in the sketch.

###"web-stepper.ino"
This sketch uses the html file "spice machine web control v1.0.html" located in this repo's software folder, to provide browser control of the spice machine prototype stepper motor. This sketch exposes two cloud functions: "numsteps" to change the number of steps the motor should drive and "uSecsDelay" to change the delay (for motor rotational speed control). The motor direction is hard coded, so to reverse motor direction, change the DIR pin from "LOW" to "HIGH" in the sketch.

###"stepper-serial-degree.ino"
This sketch requires a serial connection to keyboard for input of numbers to control motor revolutions. For Mac, I used the program 'screen' on terminal. You can use terminal commmand 'ls /dev/tty.*' to identify the usb serial connection, then use command 'screen /dev/tty.YOURDEVICE 9600' to connect... you will replace 'YOURDEVICE' with your usb serial connection identified above.

####Serial Inputs for "stepper-serial-degree.ino":
1. Enter '1' for full revolution
2. Enter '2' for half revolution
3. Enter '3' for quarter revolution
4. Enter '4' for eigth revolution

###"load-cell-calibration.ino"
 This sketch is designed to help you calibrate your Particle Photon-connected load cell. Run this sketch and open a serial port for input/output. The first time you run this sketch, enter the number "1" to reset any existing calibration. Then type "2" to zero out the scale (tare). Place a known weight on the scale, then type "3" to measure and output the weight on the scale. The calibration parameter needed in .set_scale() is equal to the value output in step #3 divided by the mass of the known weight. Enter it inside the parentheses of the scale.set_scale() function under void setup().
 
####Serial Inputs for "load-cell-calibration.ino"
1. Enter '1' to reset scale calibration.
2. Enter '2' to zero out scale (tare).
3. Enter '3' to weigh and output weight value.
4. Enter 'm' to list menu
