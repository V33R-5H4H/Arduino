#include <NewPing.h>
#define Trig_Pin A4
#define Echo_Pin A5
#define Max_Dis 400
NewPing sonar(Trig_Pin,Echo_Pin,Max_Dis);
void setup() 
{
  Serial.begin(9600);
}

void loop()
{
  Serial.print("Distance =");
  Serial.print(sonar.ping_cm());
  Serial.println("Cm");
  delay(500);
}
