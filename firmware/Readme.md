# folder for spice machine firmware files

###Hardware setup for all firmware sketches in this folder:
![alt tage](https://github.com/jashtonSF/spice-machine/blob/master/firmware/Spice-stepper-serial-degree%20v1.0.jpg)

###"web-stepper.ino"
This sketch uses the associated html file "spice machine web control v1.0.html" to provide browser control of the spice machine prototype stepper motor. Simply load the html file in any browser, adjust the number of steps and delay (which controls motor rotational speed), and click the button "dispense" to begin rotating the stepper motor as specified. There is a serial port opened for monitoring.

**Note:** Before using, please update the html file with your unique Photon ID and token access. It is designed for local browser use, so hosting this html file on a website with your Photon keys will make them available to anyone. 

###"stepper-serial-degree.ino"
This sketch requires a serial connection to keyboard for input of numbers to control motor revolutions. For Mac, I used the program 'screen' on terminal. You can use terminal commmand 'ls /dev/tty.*' to identify the usb serial connection, then use command 'screen /dev/tty.YOURDEVICE 9600' to connect... you will replace 'YOURDEVICE' with your usb serial connection identified above.

####Serial Inputs for "stepper-serial-degree.ino":
1. Enter '1' for full revolution
2. Enter '2' for half revolution
3. Enter '3' for quarter revolution
4. Enter '4' for eigth revolution

