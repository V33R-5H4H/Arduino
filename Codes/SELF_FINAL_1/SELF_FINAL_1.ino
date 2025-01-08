#include <AFMotor.h>
AF_DCMotor Motor1(1);
AF_DCMotor Motor2(2);
int LSensor =A0;
int RSensor = A5;
int LSensor_val=0;
int RSensor_val=0;
int Thres = 75;

void setup() 
{ 
  pinMode(A0,INPUT);
  pinMode(A5,INPUT);  
  Motor1.setSpeed(100);
  Motor2.setSpeed(100);
  Serial.begin(9600);

}

void loop() 
{
  LSensor_val=analogRead(LSensor);
  RSensor_val=analogRead(RSensor);
  Serial.println(LSensor_val);
  //delay(1000);
  Serial.println(RSensor_val);
  //delay(1000);
  if (LSensor_val > Thres && RSensor_val > Thres)
  {
    Motor1.run(RELEASE);
    Motor2.run(RELEASE);
    
  }
  else if (LSensor_val < Thres && RSensor_val < Thres)
  {
    Motor1.run(FORWARD);
    Motor2.run(FORWARD);
  }
  else if (LSensor_val < Thres && RSensor_val > Thres)
  {
    Motor1.run(BACKWARD);
    Motor2.run(FORWARD);
  }
  else if (LSensor_val > Thres && RSensor_val < Thres)
  {
    Motor1.run(FORWARD);
    Motor2.run(BACKWARD);
  }


}
