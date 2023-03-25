void setup() {
 pinMode(7,INPUT);
 Serial.begin(9600);
 pinMode(13,OUTPUT);


}

void loop() {
 digitalRead(7);
 Serial.print(digitalRead(7));


if(digitalRead(7)==LOW)
{
  digitalWrite(13,HIGH);
  delay(200);
    digitalWrite(13,LOW);
  delay(200);
}
else
{
digitalWrite(13,LOW);
}
}
