# folder for spice machine software files

###"spice machine web w load cell v1.0.html"
This html file is designed to control a stepper motor and load cell scale connected to a Particle Photon through the sketch "web-stepper-load-cell.ino" in the firmware folder.

Simply load the html file in any browser, select the desired target weight of spice to dispense, and click the button "dispense" to begin. The stepper motor will rotate until the load cell senses that the target weight is reached. The scale can be zeroed out at any time using a tare function. Simply click the "tare scale" button. There is a serial port opened for monitoring.

**Note:** Before using, please update the html file with your unique Photon ID and token access. It is designed for local browser use, so hosting this html file on a website with your Photon keys will make them available to anyone. 

###"spice machine web control v1.0"
This html file is designed to control a stepper motor connected to a Particle Photon through the sketch "web-stepper.ino" in the firmware folder.

Simply load the html file in any browser, adjust the number of steps and/or the delay (which controls motor rotational speed), and click the button "dispense" to begin rotating the stepper motor as specified. There is a serial port opened for monitoring.

**Note:** Before using, please update the html file with your unique Photon ID and token access. It is designed for local browser use, so hosting this html file on a website with your Photon keys will make them available to anyone. 
