#include <IRremote.h>
const int IR_RECEIVE_PIN = 12;   
String ir_code = String(IrReceiver.decodedIRData.command, HEX);
void setup(){
  pinMode(3,OUTPUT);
  Serial.begin(9600); 
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  digitalWrite(3,LOW);
}
void loop(){
  if(IrReceiver.decode()){
    Serial.println("---");
    String ir_code = String(IrReceiver.decodedIRData.command, HEX);
    if(ir_code!="0")
      Serial.println(ir_code);
    if(ir_code=="8"){
      digitalWrite(3,HIGH);
      //IrReceiver.restartTimer(1000);
    }
    if(ir_code=="c4"||ir_code=="c5"){
      digitalWrite(3,LOW);
      //IrReceiver.restartTimer(1000);
    }
    delay(250);
    IrReceiver.resume();
    Serial.println("___");
  }

}