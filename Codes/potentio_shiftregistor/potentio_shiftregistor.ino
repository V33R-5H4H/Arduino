int latchPin = 8;//Pin 11
int clockPin = 12;//Pin 10
int dataPin = 11;//Pin 13
int x=0;
void setup() {
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A3, INPUT);
  pinMode(A5, OUTPUT);
  analogWrite(A1,0);
  analogWrite(A5,255);
  
}
void loop(){
  x=map(analogRead(A3),0,1024,0,271);
  if(x<15)
    x=x;
  else if (x>=15)
    x-=15;
  Serial.println(x);
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin, clockPin, MSBFIRST,x); 
  digitalWrite(latchPin,HIGH);
  delay(500);
}