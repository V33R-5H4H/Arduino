void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);

}

void loop() {
  float x=map(analogRead(A0),0,1023,0,255);
  Serial.print("x : ");
  Serial.println(x);
  delay(1000);
  float y=map(analogRead(A1),0,1023,0,255);
  Serial.print("y : ");
  Serial.println(y);
  delay(1000);
  float z=map(analogRead(A2),0,1023,0,255);
  Serial.print("z : ");
  Serial.println(z);
  delay(1000);
}
