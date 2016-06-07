# folder for spice machine firmware files

###Hardware setup for all firmware sketches in this folder:
![alt tage](https://github.com/jashtonSF/spice-machine/blob/master/firmware/Spice-stepper-serial-degree%20v1.0.jpg)

###"web-stepper.ino"
This sketch uses the html file "spice machine web control v1.0.html" located in this repo's software folder, to provide browser control of the spice machine prototype stepper motor. This sketch exposes two cloud functions: "numsteps" to change the number of steps the motor should drive and "uSecsDelay" to change the delay (for motor rotational speed control). The motor direction is hard coded, so to reverse motor direction, change the DIR pin from "LOW" to "HIGH" in the sketch.

###"stepper-serial-degree.ino"
This sketch requires a serial connection to keyboard for input of numbers to control motor revolutions. For Mac, I used the program 'screen' on terminal. You can use terminal commmand 'ls /dev/tty.*' to identify the usb serial connection, then use command 'screen /dev/tty.YOURDEVICE 9600' to connect... you will replace 'YOURDEVICE' with your usb serial connection identified above.

####Serial Inputs for "stepper-serial-degree.ino":
1. Enter '1' for full revolution
2. Enter '2' for half revolution
3. Enter '3' for quarter revolution
4. Enter '4' for eigth revolution

