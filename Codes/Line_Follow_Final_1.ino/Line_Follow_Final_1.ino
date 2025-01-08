#include <AFMotor.h>
#define radius 3.1845
#define PI 3.14
AF_DCMotor Motor1(1);
AF_DCMotor Motor2(2);
int LSensor = A4; //Left IR Sensor Port
int RSensor = A5; //Right IR Sensor Port
int LSensor_val=0;
int RSensor_val=0;
float t=0,c=0;
void setup(){ 
    pinMode(LSensor,INPUT); 
    pinMode(RSensor,INPUT); 
    Motor1.setSpeed(180);
    Motor1.run(RELEASE);
    Motor2.setSpeed(180);
    Motor2.run(RELEASE);
    c=2*PI*radius;
}
void loop(){
        LSensor_val=digitalRead(LSensor);
        Serial.println(LSensor_val);
        RSensor_val=digitalRead(RSensor);
        Serial.println(RSensor_val);
        if ((LSensor_val == 0) && (RSensor_val == 1)){
        Motor1.setSpeed(112.5);
        Motor2.setSpeed(25);
        Motor1.run(FORWARD);
        Motor2.run(FORWARD);
        delay(100);
        t+=0.1;
        }
        else if ((LSensor_val == 1) && (RSensor_val == 0)){
        Motor1.setSpeed(25);
        Motor2.setSpeed(112.5);
        Motor1.run(FORWARD);
        Motor2.run(FORWARD);
        delay(100);
        t+=0.1;
        }
        else if ((LSensor_val == 1) && (RSensor_val == 1)){
        Motor1.setSpeed(150);
        Motor2.setSpeed(150);
        Motor1.run(FORWARD);
        Motor2.run(FORWARD);
        delay(100);
        t+=0.1;
        }
        else if ((LSensor_val == 0) && (RSensor_val == 0)){
        Motor1.setSpeed(150);
        Motor2.setSpeed(150);
        Motor1.run(FORWARD);
        Motor2.run(FORWARD);
        delay(100);
        t+=0.1;
        }
      Serial.print("Distance Traveled : ");
      Serial.println(t*c);
}
