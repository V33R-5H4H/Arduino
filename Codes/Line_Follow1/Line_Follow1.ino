#include <AFMotor.h>
AF_DCMotor Motor1(1);
AF_DCMotor Motor2(2);
int LSensor = A4; //Left IR Sensor Port
int RSensor = A5; //Right IR Sensor Port
int LSensor_val=0;
int RSensor_val=0;
void setup() 
{ 
  pinMode(A5,INPUT); 
  pinMode(A0,INPUT); 
  Motor1.setSpeed(180);
  Motor2.setSpeed(180);
  Motor1.run(RELEASE);
  Motor2.run(RELEASE);
  Serial.begin(9600);
}
void loop() 
{
  LSensor_val=digitalRead(LSensor);
  RSensor_val=digitalRead(RSensor);
  Serial.println(LSensor_val);
  //delay(1000);
  Serial.println(RSensor_val);
  //delay(1000);
 
  if ((LSensor_val == 0) && (RSensor_val == 1))
  {
    Motor1.setSpeed(112.5);
    Motor2.setSpeed(25);
    Motor1.run(FORWARD);
    Motor2.run(FORWARD);
  }
  else if ((LSensor_val == 1) && (RSensor_val == 0))
  {
    Motor2.setSpeed(112.5);
    Motor1.setSpeed(25);
    Motor1.run(FORWARD);
    Motor2.run(FORWARD);
    
  }
  else if ((LSensor_val == 1) && (RSensor_val == 1))
  {
    Motor1.setSpeed(150);
    Motor2.setSpeed(150);
    Motor1.run(FORWARD);
    Motor2.run(FORWARD);
  
  }

  else if ((LSensor_val == 0) && (RSensor_val == 0))
  {
    Motor1.setSpeed(150);
    Motor2.setSpeed(150);
    Motor1.run(FORWARD);
    Motor2.run(FORWARD);
  }
}
