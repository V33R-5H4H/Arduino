/*
Components
Arduino Uno R3
Shift Register 74HC595N
Wires
8 LEDs
8 220 ohm Resisters
Breadboard
*/
int latchPin = 8;//Pin 12
int clockPin = 12;//Pin 11
int dataPin = 11;//Pin 14
int x=0;
void setup() {
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin, clockPin, MSBFIRST,255);
  digitalWrite(latchPin,HIGH);
  delay(500);
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin, clockPin, MSBFIRST,0);
  digitalWrite(latchPin,HIGH);
}
void loop(){
  while (!Serial.available()) {}
  digitalWrite(latchPin,LOW);
  x=Serial.parseInt();          //Receives Input from Serial Monitor
  if(x>0 && x<256){
    Serial.print("Received : ");
    Serial.println(x);
    shiftOut(dataPin, clockPin, MSBFIRST,x); //Performs bit shift operation
  }else if(x>=256&&x!=0){
    x=0;
    shiftOut(dataPin, clockPin, MSBFIRST,x);
    Serial.println("Invalid Number");
    Serial.println("Reset");
  }
  digitalWrite(latchPin,HIGH);
  delay(50);
}