#define LED 11
#define POTENTIOMETER A1

void setup() 
{
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
}

void loop() 
{
  int PotentioValue = analogRead(POTENTIOMETER);
  //int Brightness = PotentioValue/4;      
  int Brightness = map(PotentioValue,0,1023,0,255);
  Serial.println(Brightness);
  analogWrite(LED,Brightness);
}
