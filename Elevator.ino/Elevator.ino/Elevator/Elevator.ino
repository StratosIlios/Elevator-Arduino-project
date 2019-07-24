/*The code activates the Elvator and moves the cabine into 0,1 and 2 floors.
The distances between the floors are fixed. Green Light indicates that the motor is disabled
and the Red Light indicates that the motor is enabled*/

#include <Stepper.h>

const int number_of_steps=200;// change this to fit the number of steps per revolution
Stepper motor(number_of_steps,2, 3, 4, 5);// initialize the stepper library on pins 2 through 5
boolean onetime=true;
int CurrentFloor;
int Diff_Flrs;
int x=21;// The value when the difference between Current and Destination Flor is not +-2
int y=43;// The value when the difference between Current and Destination Floor is +-2
int d=x;

/*Function that compares the Current with Destination floor, moves the Cabine to proper direction and also activates the Green and Red lights*/
void CompareFloor(int DestinationFloor){
    if(onetime==true){
       CurrentFloor=0;
       onetime=false;
    }     
    
/* Define the distance of the floors */    
    Diff_Flrs=CurrentFloor-DestinationFloor;
    if(Diff_Flrs==2||Diff_Flrs==-2){d=y;}  
    else{d=x;}       
    
/* If Destination Floor is LARGER than Current Floor then go UP*/
    if(DestinationFloor>CurrentFloor){     
       for(int i=0;i<=d;i++){
           digitalWrite(6,HIGH);// Sets the red light on  
           digitalWrite(7,LOW);// Sets the green light off  
           motor.step(number_of_steps);          
       }  
       CurrentFloor=DestinationFloor;
    }    
    
/* If Destination Floor is SMALLER than Current Floor then go DOWN*/    
    if (DestinationFloor<CurrentFloor){
       for(int i=0;i<=d;i++)
       {
          digitalWrite(6,HIGH);// Sets the red light on 
          digitalWrite(7,LOW);// Sets the green light off
          motor.step(-number_of_steps);  
       }   
       CurrentFloor=DestinationFloor;
    }  
    if (DestinationFloor==0){Serial.println("You arrived in Ground Floor. Please enter your Destination Floor.");}
    else{
         Serial.print("You arrived in Floor ");
         Serial.print(DestinationFloor);
         Serial.println(". Please enter your Destination Floor.");
    }
    digitalWrite(6,LOW);// Sets the red light off
    digitalWrite(7,HIGH);// Sets the green light on
    delay(1500);// Sets the delay in case that the user inserts the input continuously
}

void setup(){
  Serial.begin(9600); 
  while(!Serial);   
  Serial.println("You are in Ground Floor. Please enter your Destination Floor.");
  motor.setSpeed(120);
  pinMode(6,OUTPUT);
  pinMode(7, OUTPUT);
}

void loop(){
   if(Serial.available()>0)
   {      
     digitalWrite(7,HIGH);// Sets the green light on
     int button=Serial.parseInt();// Takes the value from keyboard from Serial Monitor
     if(button==0||button==1||button==2)
     {        
        CompareFloor(button);// Sets the input value to the Destination function      
        Serial.setTimeout(10000000);      
     }
     else{Serial.println("Worng input. Please enter the correct floor number");}
   } 
} 
