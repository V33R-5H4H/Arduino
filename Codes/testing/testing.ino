#include <NewPing.h>
#include <AFMotor.h>
#include <Servo.h>
#define Max_Speed 200
#define Max_Offset 20
#define Servo_Pin 10
#define Trig_Pin A4
#define Echo_Pin A5
#define Max_Dis 500
#define Dis_Thres 30
NewPing sonar(Trig_Pin,Echo_Pin,Max_Dis);
AF_DCMotor Motor1(1);
AF_DCMotor Motor2(3);
int startAngle=90;
int Speed = 0;
int Dist = 250;
int pos = 90 ;
Servo servo;
void setup() 
{
  Serial.begin(9600);  
  servo.attach(10);
  Dist=sonar.ping_cm();
  Serial.println(Dist);
}

void loop() 
{  
  for (pos=90; pos>=0;pos=pos-5)
  {
    servo.write(pos);
    Dist=sonar.ping_cm();
    Serial.println(Dist);
    delay(300);
    
    if (Dist<= Dis_Thres)
    {
      bool obstacledetected= false;
      Serial.println("bool if dis < dis thres");
      Serial.println(Dist);
      obstacledetected=true;
      break;
    }
  }
  for (pos=90; pos<=180;pos=pos+5)
  {
    servo.write(pos);
    Dist=sonar.ping_cm();
    Serial.println(Dist);
    delay(300);
    if (Dist<= Dis_Thres)
    {
      bool obstacledetected= false;
      Serial.println("bool if dis < dis thres");
      Serial.println(Dist);
      obstacledetected=true;
      break;
    }
  }  
}
 