# folder for spice machine firmware files

"stepper-serial-degree.ino"
This sketch requires a serial connection to keyboard for input of numbers to control motor revolutions. For Mac, I used the program 'screen' on terminal. You can use terminal commmand 'ls /dev/tty.*' to identify the usb serial connection, then use command 'screen /dev/tty.YOURDEVICE 9600' to connect... you will replace 'YOURDEVICE' with your usb serial connection identified above.

Enter '1' for full revolution
Enter '2' for half revolution
Enter '3' for quarter revolution
Enter '4' for eigth revolution

Hardware setup for "stepper-serial-degree.ino":
![alt tage](https://github.com/jashtonSF/spice-machine/blob/master/firmware/Spice-stepper-serial-degree%20v1.0.jpg)
