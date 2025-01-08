#include <IRremote.h>
const int IR_RECEIVE_PIN = 12;   
String ir_code = String(IrReceiver.decodedIRData.command,DEC);
void setup(){
  pinMode(3,OUTPUT);
  Serial.begin(9600); 
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}
void loop(){
  if(IrReceiver.decode()) {
    ir_code = String(IrReceiver.decodedIRData.command,DEC);
    if(ir_code=="8"){
      digitalWriteFast(3,HIGH);
      if(analogRead(3)>=255){
        Serial.println("HI");
        test();
      }
    }
    else if(ir_code=="197"){
    digitalWriteFast(3,LOW);  
    }
    delay(250);
    IrReceiver.resume();
  }
}

void test(){
  while(true){
    if(IrReceiver.decode()){
      ir_code = String(IrReceiver.decodedIRData.command,DEC);
      if(ir_code!="8"){
        Serial.println("H");
        break;
      }
      delay(250);
      IrReceiver.resume();
    }
  }
} 
  