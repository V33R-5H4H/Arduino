#include <NewPing.h>
#include <AFMotor.h>
#include <Servo.h>
#define Max_Speed 200
#define Max_Offset 20
#define Servo_Pin 10
#define Trig_Pin A4
#define Echo_Pin A5
#define Max_Dis 500
#define Dis_Thres 20
NewPing sonar(Trig_Pin,Echo_Pin,Max_Dis);
AF_DCMotor Motor1(1);
AF_DCMotor Motor2(3);
int startAngle=90;
int Speed = 0;
int Dist = 250;
int angle;
int pos = 90;
Servo servo;

void setup() 
{
  Dist=sonar.ping_cm();
  servo.attach(Servo_Pin);
  servo.write(pos);       
  Serial.begin(9600);  
  Serial.println("start");   
  
}

void loop() 
{
  bool checkF = CheckobstacleF();
  bool checkR = CheckobstacleR();
  bool checkL = CheckobstacleL();
  Serial.println(Dist);
  if (checkF)
  {
    if (checkR && checkL) 
    {
      Serial.println("Check R&L");
      Serial.println(Dist);
      delay(500);
      stop();
    }
    else if (checkR) 
    {
      Serial.println("Check R");
      Serial.println(Dist);
      delay(500);
      left();
    }
    else if (checkL)
    {
      Serial.println("Check L");
      Serial.println(Dist);
      delay(500);
      right();
    }
  }
  else
  {
    Serial.println("Forward");
    Serial.println(Dist);
    delay(500);
    forward();
  }
}

bool CheckobstacleF()
{
  bool obstacledetected= false;
  for (angle=90; angle=90; angle=angle+0) 
  {
    servo.write(angle);
    Dist=sonar.ping_cm();
    Serial.println(Dist);
    delay(300);
    if (Dist==0)
    {
      Dist=250;
      Serial.println("Bool if 0=250");
      Serial.println(Dist);
      break;
    }
    
    if (Dist<= Dis_Thres)
    {
      Serial.println("bool if dis < dis thres");
      Serial.println(Dist);
      obstacledetected=true;
      break;
    }
    Serial.println("in for loop");
    break;
  }
  servo.write(pos);
  return obstacledetected;
  Serial.println("bool end");
  Serial.println(Dist);
}


bool CheckobstacleR()
{
  bool obstacledetectedR= false;
  for (angle=90; angle>=0; angle=angle-5) 
  {
    servo.write(angle);
    Dist=sonar.ping_cm();
    Serial.println(Dist);
    delay(300);
    if (Dist==0)
    {
      Dist=250;
      Serial.println("Bool if 0=250");
      Serial.println(Dist);
      break;
    }
    
    if (Dist<= Dis_Thres)
    {
      Serial.println("bool if dis < dis thres");
      Serial.println(Dist);
      obstacledetectedR=true;
      break;
    }
    Serial.println("in for loop");
    break;
  }
  servo.write(pos);
  return obstacledetectedR;
  Serial.println("bool end");
  Serial.println(Dist);
}

bool CheckobstacleL()
{
  bool obstacledetectedL= false;
  for (angle=90; angle<=180; angle=angle+5) 
  {
    servo.write(angle);
    Dist=sonar.ping_cm();
    Serial.println(Dist);
    delay(300);
    if (Dist==0)
    {
      Dist=250;
      Serial.println("Bool if 0=250");
      Serial.println(Dist);
      break;
    }
    
    if (Dist<= Dis_Thres)
    {
      Serial.println("bool if dis < dis thres");
      Serial.println(Dist);
      obstacledetectedL=true;
      break;
    }
    Serial.println("in for loop");
    break;
  }
  servo.write(pos);
  return obstacledetectedL;
  Serial.println("bool end");
  Serial.println(Dist);
}

void forward()
{
  for (int Speed=0;Speed<=Max_Speed;Speed++)
  {
  Motor1.setSpeed(Speed);
  Motor2.setSpeed(Speed);
  Motor1.run(FORWARD);
  Motor2.run(FORWARD);  
  }
}

void stop()
{
  Motor1.setSpeed(0);
  Motor2.setSpeed(0);
  Motor1.run(RELEASE);
  Motor2.run(RELEASE);
}  

void right()
{
  Motor1.setSpeed(0);
  Motor2.setSpeed(255);
  Motor1.run(RELEASE);
  Motor2.run(FORWARD);
  delay(220);
}  

void left()
{
  Motor1.setSpeed(255);
  Motor2.setSpeed(0);
  Motor1.run(FORWARD);
  Motor2.run(RELEASE);
  delay(220);
}  
