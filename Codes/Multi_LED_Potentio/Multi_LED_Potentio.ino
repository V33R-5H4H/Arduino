#define LED1 11
#define LED2 10
#define LED3 9
#define POTENTIOMETER A1
#define LED_Number 3
void setup() 
{
  Serial.begin(9600);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
}

void loop() 
{
  int PotentioValue = analogRead(POTENTIOMETER);
  int LED_Choice = PotentioValue/( 1024 /LED_Number);
  Serial.println(LED_Choice);
  if (LED_Choice > LED_Number-1)
  {
    LED_Choice = LED_Number-1;
  } 
  
  if (LED_Choice == 0)
  {
    digitalWrite(LED1,HIGH);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
  }

    else if (LED_Choice == 1)
  {
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,HIGH);
    digitalWrite(LED3,LOW);
  }

    else 
  {
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,HIGH);
  }
}
