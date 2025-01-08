#include <AFMotor.h>
AF_DCMotor Motor1(1);
AF_DCMotor Motor2(3);
void setup() 
{

}

void loop() 
{
  delay(1000);

  Motor1.setSpeed(255);
  Motor2.setSpeed(0);
    
  Motor1.run(FORWARD);
  Motor2.run(FORWARD);
  delay(440);

  Motor1.run(RELEASE);
  Motor2.run(RELEASE);
  delay(1000); 
}
