#include <Servo.h>
Servo servo;
int pos = 90;

void setup()
{
  servo.attach(10);
  servo.write(0);
  delay(500);
}

void loop()
{
  servo.write(0);
  delay(2000);

  servo.write(180);
  delay(2000);
}
