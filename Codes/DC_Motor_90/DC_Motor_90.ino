// delay(288) = 90 deg@255
#include <AFMotor.h>
AF_DCMotor Motor1(1);
AF_DCMotor Motor2(3);
void setup() 
{
}
void loop() 
{
  Motor1.setSpeed(255);
  Motor2.setSpeed(255);
    
  Motor1.run(FORWARD);
  Motor2.run(FORWARD);
  delay(1000);

  Motor1.run(RELEASE);
  Motor2.run(RELEASE);
  delay(1000); 

  Motor1.run(FORWARD);
  Motor2.run(BACKWARD);
  delay(288);

  Motor1.run(RELEASE);
  Motor2.run(RELEASE);
  delay(1000);

  Motor1.run(FORWARD);
  Motor2.run(FORWARD);
  delay(1000);

  Motor1.run(RELEASE);
  Motor2.run(RELEASE);
  delay(1000); 

  Motor1.run(FORWARD);
  Motor2.run(BACKWARD);
  delay(288);

  Motor1.run(RELEASE);
  Motor2.run(RELEASE);
  delay(1000);
  
  Motor1.run(FORWARD);
  Motor2.run(FORWARD);
  delay(1000);

  Motor1.run(RELEASE);
  Motor2.run(RELEASE);
  delay(1000); 

  Motor1.run(BACKWARD);
  Motor2.run(FORWARD);
  delay(288);

  Motor1.run(RELEASE);
  Motor2.run(RELEASE);
  delay(1000);   
  
  Motor1.run(FORWARD);
  Motor2.run(FORWARD);
  delay(1000);

  Motor1.run(RELEASE);
  Motor2.run(RELEASE);
  delay(1000); 

  Motor1.run(BACKWARD);
  Motor2.run(FORWARD);
  delay(288);

  Motor1.run(RELEASE);
  Motor2.run(RELEASE);
  delay(1000);   

}
