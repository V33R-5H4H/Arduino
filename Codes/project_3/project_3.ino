int x=0;
int ones=0;
int tens=0;
int hundreds=0;
int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;
int D1 = 9;
int D2 = 10;
int D3 = 13;
int latchPin = 1;//Pin 11
int clockPin = 12;//Pin 10
int dataPin = 11;//Pin 13

void setup() {
  Serial.begin(9600);
  pinMode(pinA, OUTPUT);
    pinMode(pinB, OUTPUT);
    pinMode(pinC, OUTPUT);
    pinMode(pinD, OUTPUT);
    pinMode(pinE, OUTPUT);
    pinMode(pinF, OUTPUT);
    pinMode(pinG, OUTPUT);
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
    pinMode(D3, OUTPUT);
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
    digitalWrite(D3, LOW);

}

void loop() {
  digitalWrite(latchPin,HIGH);
  shiftOut(dataPin, clockPin, MSBFIRST,255);
  delay(1000);
  digitalWrite(latchPin,LOW);
  ones=0;
  tens=0;
  hundreds=0;
  for (int i= 10;i<=256;i++){
    ones+=1;
    if(ones==10){
      tens+=1;
      ones=0;
      if(tens==10){
        hundreds+=1;
        tens=0;
      }
    }
    if(hundreds){
      displayDigit(hundreds,D1);
      delay(100);
      displayDigit(tens,D2);
      delay(100);
      displayDigit(ones,D3);
      delay(200);
    }if(tens){
      displayDigit(tens,D2);
      delay(100);
      displayDigit(ones,D3);
      delay(200);
    }if(ones){
      displayDigit(ones,D3);
      delay(200);
    }
  }
}


void reset(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH); 
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
}

void displayDigit(int digit,int disp) {
    reset();
    digitalWrite(disp, HIGH);

    if (digit == 0) {
        digitalWrite(pinA, LOW);
        digitalWrite(pinB, LOW);
        digitalWrite(pinC, LOW);
        digitalWrite(pinD, LOW);
        digitalWrite(pinE, LOW);
        digitalWrite(pinF, LOW);
    } else if (digit == 1) {
        digitalWrite(pinB, LOW);
        digitalWrite(pinC, LOW);
    } else if (digit == 2) {
        digitalWrite(pinA, LOW);
        digitalWrite(pinB, LOW);
        digitalWrite(pinD, LOW);
        digitalWrite(pinE, LOW);
        digitalWrite(pinG, LOW);
    } else if (digit == 3) {
        digitalWrite(pinA, LOW);
        digitalWrite(pinB, LOW);
        digitalWrite(pinC, LOW);
        digitalWrite(pinD, LOW);
        digitalWrite(pinG, LOW);
    } else if (digit == 4) {
        digitalWrite(pinB, LOW);
        digitalWrite(pinC, LOW);
        digitalWrite(pinF, LOW);
        digitalWrite(pinG, LOW);
    } else if (digit == 5) {
        digitalWrite(pinA, LOW);
        digitalWrite(pinC, LOW);
        digitalWrite(pinD, LOW);
        digitalWrite(pinF, LOW);
        digitalWrite(pinG, LOW);
    } else if (digit == 6) {
        digitalWrite(pinA, LOW);
        digitalWrite(pinC, LOW);
        digitalWrite(pinD, LOW);
        digitalWrite(pinE, LOW);
        digitalWrite(pinF, LOW);
        digitalWrite(pinG, LOW);
    } else if (digit == 7) {
        digitalWrite(pinA, LOW);
        digitalWrite(pinB, LOW);
        digitalWrite(pinC, LOW);
    } else if (digit == 8) {
        digitalWrite(pinA, LOW);
        digitalWrite(pinB, LOW);
        digitalWrite(pinC, LOW);
        digitalWrite(pinD, LOW);
        digitalWrite(pinE, LOW);
        digitalWrite(pinF, LOW);
        digitalWrite(pinG, LOW);
    } else if (digit == 9) {
        digitalWrite(pinA, LOW);
        digitalWrite(pinB, LOW);
        digitalWrite(pinC, LOW);
        digitalWrite(pinD, LOW);
        digitalWrite(pinF, LOW);
        digitalWrite(pinG, LOW);
    } else {
    }
}