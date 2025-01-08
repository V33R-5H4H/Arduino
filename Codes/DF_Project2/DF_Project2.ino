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
}
void loop(){
	for(x=0;x<=255;x++){								//Increments variable x from 0 to 255
  	  digitalWrite(latchPin,LOW);
		  shiftOut(dataPin, clockPin, MSBFIRST,x);		//Performs Bit shift operation 
  		digitalWrite(latchPin,HIGH);
  		delay(500);
	}
}
