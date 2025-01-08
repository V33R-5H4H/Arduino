#include <AFMotor.h>
#include <NewPing.h>
#include <Servo.h>
#define Dis_Thres 15  // Threshold Distance For Ultrasonic Sensor
#define Servo_Pin 10  // Defining Servo Pin
#define Trig_Pin A2   // Defining Trig Pin
#define Echo_Pin A3   // Definig Echo Pin
#define Max_Dis 500   // Maximum Distance For Ultrasonic
NewPing sonar(Trig_Pin,Echo_Pin,Max_Dis);
AF_DCMotor Motor1(1); // Motor 1
AF_DCMotor Motor2(2); // Motor 2
int LSensor_val=0;  
int RSensor_val=0;
int LSensor = A4; //Left IR Sensor Port
int RSensor = A5; //Right IR Sensor Port
int Dist = 250;
Servo servo;
void setup() 
{ 
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);  
  Motor1.setSpeed(180);
  Motor2.setSpeed(180);
  Motor1.run(RELEASE);
  Motor2.run(RELEASE);
  Serial.begin(9600);
  Dist=sonar.ping_cm();
  servo.attach(Servo_Pin);
  servo.write(0);
}
void loop() 
{
  Dist=sonar.ping_cm();
  if (Dist==0)
  {
    Dist=250;
  }
  Serial.println(Dist);
  if (Dist > Dis_Thres) 
  {
    LSensor_val=digitalRead(LSensor);
    RSensor_val=digitalRead(RSensor);
    //Serial.println(LSensor_val);
    //Serial.println(RSensor_val);
    if ((LSensor_val == 0) && (RSensor_val == 1))
    {
      Motor1.setSpeed(137.5);
      Motor2.setSpeed(25);
      Motor1.run(FORWARD);
      Motor2.run(FORWARD);
    }
    else if ((LSensor_val == 1) && (RSensor_val == 0))
    {
      Motor2.setSpeed(137.5);
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
  else if (Dist <= Dis_Thres) 
  {
    Motor1.setSpeed(20);
    Motor2.setSpeed(20);
    Motor1.run(FORWARD);
    Motor2.run(FORWARD);
    delay(3000);
    if (Dist <= Dis_Thres);
    {
      servo.write(180);
      delay(6000);
      servo.write(0);
      Motor1.setSpeed(100);
      Motor2.setSpeed(100);
      delay(1000);
      Motor1.run(FORWARD);
      Motor2.run(FORWARD);
    }
  }
}