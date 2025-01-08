#include <AFMotor.h>
AF_DCMotor Motor1(1);
AF_DCMotor Motor2(3);

void setup() 
{
  // 300 delay = 90 deg
}

void loop() 
{
  Motor1.setSpeed(255);
  Motor2.setSpeed(255);

  Motor1.run(FORWARD);
  Motor2.run(FORWARD);
  delay(2000);

  Motor1.run(RELEASE);
  Motor2.run(RELEASE);
  delay(1000); 
  
  Motor1.run(BACKWARD);
  Motor2.run(BACKWARD);
  delay(300);

  Motor1.run(RELEASE);
  Motor2.run(RELEASE);
  delay(1000); 
/*
  Motor1.run(FORWARD);
  Motor2.run(FORWARD);
  delay(2000);

  Motor1.run(RELEASE);
  Motor2.run(RELEASE);
  delay(1000); 

  Motor1.run(BACKWARD);
  Motor2.run(BACKWARD);
  delay(2000);

  Motor1.run(RELEASE);
  Motor2.run(RELEASE);
  delay(1000); 

  Motor1.run(FORWARD);
  Motor2.run(BACKWARD);
  delay(250);

  Motor1.run(RELEASE);
  Motor2.run(RELEASE);
  delay(1000); 

  Motor1.run(BACKWARD);
  Motor2.run(FORWARD);
  delay(250);
 
  Motor1.run(RELEASE);
  Motor2.run(RELEASE);
  delay(1000); 

*/
}
