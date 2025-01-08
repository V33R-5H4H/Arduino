#include <AFMotor.h>
#define rad 3.1845
#define Pi 3.14
AF_DCMotor Motor1(1);//Left Motor
AF_DCMotor Motor2(2);//Right Motor
int LSensor = A4; //Left IR Sensor Port
int RSensor = A5; //Right IR Sensor Port
int LSensor_val=0;
int RSensor_val=0;
float t=0;
float c=0;
void setup(){ 
    Serial.begin(9600);//Initialize Serial Monitor With Baud Rate of 9600
    pinMode(LSensor,INPUT); //Setting Pinmode
    pinMode(RSensor,INPUT); //Setting Pinmode
    Motor1.setSpeed(180);
    Motor1.run(RELEASE);
    Motor2.setSpeed(180);
    Motor2.run(RELEASE);
    c=2*Pi*rad;
}
void loop(){
        LSensor_val=digitalRead(LSensor);
                RSensor_val=digitalRead(RSensor);
                        if ((LSensor_val == 0) && (RSensor_val == 1)){
                                Motor1.setSpeed(112.5);
                                        Motor2.setSpeed(25);
                                                Motor1.run(FORWARD);
                                                        Motor2.run(FORWARD);
                                                                delay(100);
                                                                …        Motor2.setSpeed(150);
                                                                        Motor1.run(FORWARD);
                                                                                Motor2.run(FORWARD);
                                                                                        delay(100);
                                                                                                t+=0.1;
                                                                                                        }
                                                                                                          Serial.print("Distance Traveled : ");
                                                                                                            Serial.println(t*c);
                                                                                                            }
                                                                                                            }
  Serial.print("Distance Traveled : ");
  Serial.println(t*c);
}