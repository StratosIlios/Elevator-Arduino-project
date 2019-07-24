# Elevator-Arduino-project
The two-floors elevator contains ground, 1st and 2nd floor.
The size of the elevator is H: 34cm, L: 10cm and W: 9cm. The size of the elevator cabin is H:8.5cm, L:8cm and W:7.5. The number of the destination floor is inserted by using the keyboard of PC via Arduino Serial Monitor. The red led is on when the motor is enabled and the green is on when the motor is disabled. 

A function calculates the difference between the current and destination floors and moves up or down according to the result. The elevator contains no sensors and therefore the distance between the floors is standard.   

The components that have being used are the following:
1. 1X Arduino Uno R3 Controller Board 
2. 1X Stepper Motor 
3. 1X ULN2003 Stepper Motor Driver Board 
4. 6X Female-to-male Dupont wires 
5. 3X 65Jumper Wires
6. 1X 830 Tie-Points Breadboard
7. 2X Resistors of 220Ohm
8. 1X Red Led 
9. 1X Green Led

Connection of the Elevator
Pins connected to the ULN2003 Stepper Motor Driver Board: 2,3,4,5
1. 1N1->2 
2. 1N2->4 
3. 1N3->3 
4. 1M4->5 
5. (+)->5V
6. (-)->GND.




