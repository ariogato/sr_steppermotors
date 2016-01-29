/*
  Author: Ario
  Date: 29.01.16

  Comment:  Ich benutze nicht mehrere source-files weil die arduino-IDE, 
            die ich mehr oder weniger gezwungen nutze, 
            nicht für diesen zweck optimiert wurde.
*/

//speed for the stepper motors
#define SPEED 10

//steps per revolution
#define STEPS 48


//library for the motor-shield (obviously)
#include <AFMotor.h>

class Stepper
{
  private:
    
    //if I won't use interrupts... this will probably come in handy anyway
    bool is_driving;
    
    //one stepper motor  ...  these are just some random values. Replace them!!!
    //(steps per revolution, motor port)
    
    AF_Stepper* motor_left = new AF_Stepper(STEPS, 2);
    AF_Stepper* motor_right = new AF_Stepper(STEPS, 1);
    
  public:
  
    //just a basic constructor ... the robot won't be driving at first
    Stepper() : is_driving(false) 
    {
      //setting the speed of each stepper motor ... obviously
      motor_left->setSpeed(SPEED);
      motor_right->setSpeed(SPEED);
    }
    
    //member-function to move the robot forwards
    //distance in cm
    void forward(int distance)
    {
      //set the state to "driving"
      this->is_driving = 1;
      
      int steps_done = 0;
      
      //add code to make the two stepper motors drive
      while (is_driving && steps_done <= distance)
      {
        //move the motors a certain ammount of steps ... values have to be tweaked (in cm)
        //also there are multiple options for the third parameter (SINGLE, DOUBLE, INTERLEAVE, MICROSTEP)
        motor_left->step(1, FORWARD, DOUBLE);
        motor_right->step(1, FORWARD, DOUBLE);
        
        steps_done++;
        
      }
    }
    
    //member-function to move the robot backwards
    //distance in cm
    void backward(int distance)
    {
      //set the state to "driving"
      this->is_driving = 1;
      
      int steps_done = 0;
      
      //add code to make the two stepper motors drive
      while (is_driving && steps_done <= distance)
      {
        //move the motors a certain ammount of steps ... values have to be tweaked (in cm)
        //also there are multiple options for the third parameter (SINGLE, DOUBLE, INTERLEAVE, MICROSTEP)
        //probably this won't work properly, because it's making one step at a time
        motor_left->step(0.1, BACKWARD, DOUBLE);
        motor_right->step(0.11, BACKWARD, DOUBLE);
        
        steps_done++;
        
      }
    }
    
    //turing the robot 
    /*void turn(int degree)
    {
      while 
    }*/
    
};


void setup() 
{
  //set the necessary bits in the register for uart 
  //at baud 9600
  //probably 8N1  ... but I have no idea
  Serial.begin(9600);
  
  
}

void loop() {

}
