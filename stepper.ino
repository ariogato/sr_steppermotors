/*
  Author: Ario
  Date: 29.01.16

  Comment:  Ich benutze nicht mehrere source-files weil die arduino-IDE, 
            die ich mehr oder weniger gezwungen nutze, 
            nicht für diesen zweck optimiert wurde.
*/

//speed for the stepper motors
#define SPEED 1000

//steps per revolution
#define STEPS 200


//library for the motor-shield (obviously)
#include <AFMotor.h>

#include <SoftwareSerial.h>

SoftwareSerial myserial();

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
      
      String help = "1";
      
      int steps_done = 0;
      
      //add code to make the two stepper motors drive
      while (is_driving && steps_done <= distance)
      {
        /*
          move the motors a certain ammount of steps ... values have to be tweaked (in cm)
          also there are multiple options for the third parameter (SINGLE, DOUBLE, INTERLEAVE, MICROSTEP)
        */
        
        motor_left->step(1, FORWARD, DOUBLE);
        motor_right->step(1, FORWARD, DOUBLE);
        
        steps_done++;
        
        //if there is some data in the registry, then take it
        while(Serial.available())
        {
          //store the received data in a string
          help += (char)Serial.read();
        }
        
        //This is actually working.... I think it would best if I'd just kill myself... 
        is_driving = imitate_cast(help);
        
        
      }
    }
    
    //if you just want to break out and crush all the chains #burr #freedom
    void forward_infinitely()
    {
      //set the state to "driving"
      this->is_driving = 1;
      
      String help = "1";
      
      int steps_done = 0;
      
      //just an emergency stop
      while (is_driving && steps_done <= 10)
      {
        /*
          move the motors a certain ammount of steps ... values have to be tweaked (in cm)
          also there are multiple options for the third parameter (SINGLE, DOUBLE, INTERLEAVE, MICROSTEP)
        */
        
        motor_left->step(1, FORWARD, DOUBLE);
        motor_right->step(1, FORWARD, DOUBLE);
        
        steps_done++;
        
        //if there is some data in the registry, then take it
        while(Serial.available())
        {
          //store the received data in a string
          help += (char)Serial.read();
        }
        
        //This is actually working.... I think it would best if I'd just kill myself... 
        is_driving = imitate_cast(help);
        
      }
    }
    
    //member-function to move the robot backwards
    //distance in cm
    void backward(int distance)
    {
      //set the state to "driving"
      this->is_driving = 1;
      
      String help = "1";
      
      int steps_done = 0;
      
      //add code to make the two stepper motors drive
      while (is_driving && steps_done <= distance)
      {
        /*
          move the motors a certain ammount of steps ... values have to be tweaked (in cm)
          also there are multiple options for the third parameter (SINGLE, DOUBLE, INTERLEAVE, MICROSTEP)
          maybe this won't work properly, because it's making one step at a time
        */
        
        motor_left->step(1, BACKWARD, DOUBLE);
        motor_right->step(1, BACKWARD, DOUBLE);
        
        
        steps_done++;
        
        //if there is some data in the registry, go take it
        while(Serial.available())
        {
          //store the received data in a string
          help += (char)Serial.read();
        }
        
        //This is actually working.... I think it would best if I'd just kill myself... 
        is_driving = imitate_cast(help);
        
      }
    }
    
    
    //if you just want to break out and crush all the chains #burr #freedom
    void backward_infinitely()
    {
      //set the state to "driving"
      this->is_driving = 1;
      
      String help = "1";
      
      int steps_done = 0;
      
      //just an emergency stop
      while (is_driving && steps_done <= 10000)
      {
        /*
          move the motors a certain ammount of steps ... values have to be tweaked (in cm)
          also there are multiple options for the third parameter (SINGLE, DOUBLE, INTERLEAVE, MICROSTEP)
        */
        
        motor_left->step(1, BACKWARD, DOUBLE);
        motor_right->step(1, BACKWARD, DOUBLE);
        
        steps_done++;
        
        //if there is some data in the registry, then take it
        while(Serial.available())
        {
          //store the received data in a string
          help += (char)Serial.read();
        }
        
        //This is actually working.... I think it would best if I'd just kill myself... 
        is_driving = imitate_cast(help);
        
      }
    }
    
    
    //turing the robot to the left 
    void turn_left(int degree)
    {
      //set the state to "driving"
      this->is_driving = 1;
      
      String help = "1";
      
      int steps_done = 0;
      
      //add code to make the two stepper motors drive
      while (is_driving && steps_done <= degree)
      {
        /*
          move the motors a certain ammount of steps ... values have to be tweaked (in cm)
          also there are multiple options for the third parameter (SINGLE, DOUBLE, INTERLEAVE, MICROSTEP)
          maybe this won't work properly, because it's making one step at a time
        */
        
        motor_left->step(1, BACKWARD, DOUBLE);
        motor_right->step(1, FORWARD, DOUBLE);
        
        
        steps_done++;
        
        //if there is some data in the registry, then take it
        while(Serial.available())
        {
          //store the received data in a string
          help += (char)Serial.read();
        }
        
        //This is actually working.... I think it would best if I'd just kill myself... 
        is_driving = imitate_cast(help);
        
      }
    }
    
    //turning the robot to the right
    void turn_right(int degree)
    {
      //set the state to "driving"
      this->is_driving = 1;
      
      String help = "1";
      
      int steps_done = 0;
      
      //add code to make the two stepper motors drive
      while (is_driving && steps_done <= degree)
      {
        /*
          move the motors a certain ammount of steps ... values have to be tweaked (in cm)
          also there are multiple options for the third parameter (SINGLE, DOUBLE, INTERLEAVE, MICROSTEP)
          maybe this won't work properly, because it's making one step at a time
        */
        
        motor_left->step(1, FORWARD, DOUBLE);
        motor_right->step(1, BACKWARD, DOUBLE);
        
        
        steps_done++;
        
        //if there is some data in the registry, then take it
        while(Serial.available())
        {
          //store the received data in a string
          help += (char)Serial.read();
        }
        
        //This is actually working.... I think it would best if I'd just kill myself... 
        is_driving = imitate_cast(help);
        
      }
    }
    
};


//to cast a string into a boolean .. will be enough for this project 
bool imitate_cast(String&);


void setup() 
{
  //set the necessary bits in the register for uart 
  //at baud 9600
  //probably 8N1  ... but I have no idea
  Serial.begin(9600);
  
  
}



//beginning of the program
void loop() 
{
  
  Stepper* s = new Stepper();
  
  //variable to store user input
  String input = "";
  
  //variable to store the ammount of steps the user wants to make default = 100;
  int steps = 1000;
  
  
  //wait until there's something in the serial buffer
  while(Serial.available() == 0);
  
  //storing the input
  while((Serial.available()))
  {
    char inChar = (char)Serial.read();
    
    input += inChar;
    
    Serial.println("reached buffer-clearing");
    
    //waiting for the buffer to get filled with data again
    delay(1);
    
    
  }
  
  
  
  //decison making about the input
  if(input == "a")                                  //forwards
  {
    s->forward(steps);
  }
  else if(input == "b")                             //backwards
  {
    s->backward(steps);
  }
  else if(input == "c")                             //turn_left
  {
    s->turn_left(steps);
  }
  else if(input == "d")                             //turn_right
  {
    s->turn_right(steps);
  }
  
  
  
  /*
      the member functions "running_infinitely", etc. will be add later (if needed)
  */
  
  
  
  delete s;
  
  Serial.println("reached end");
  
}


//this is so retarded
bool imitate_cast(String& s)
{
  return s == "true" || s == "1";
}



