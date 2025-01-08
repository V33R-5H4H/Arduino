#include <AFMotor.h>

AF_DCMotor motor(3);

void setup() 
{
  motor.setSpeed(100);
  motor.run(RELEASE);
}

void loop() 
{
  uint8_t i;
  
  //Motor spinning clockwise
  motor.run(FORWARD);
  //Speed up
  for (i=0; i<255; i++) 
  {
    motor.setSpeed(i);  
    delay(10);
  }
  
  // Speed down
  for (i=255; i!=0; i--) 
  {
    motor.setSpeed(i);  
    delay(10);
  }

  //Motor spinning anti-clockwise
  motor.run(BACKWARD);
  
  // Speed up
  for (i=0; i<255; i++) 
  {
    motor.setSpeed(i);  
    delay(10);
  }

  // Speed down
  for (i=255; i!=0; i--) 
  {
    motor.setSpeed(i);  
    delay(10);
  }

  // Now turn off motor
  motor.run(RELEASE);
  delay(1000);
}
