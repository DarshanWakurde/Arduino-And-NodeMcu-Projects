void setup() {
  // put your setup code here, to run once:
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(11,HIGH);
delay(100);
digitalWrite(12,HIGH);
delay(100);
digitalWrite(13,HIGH);
delay(100);
digitalWrite(11,LOW);
delay(100);
digitalWrite(12,LOW);
delay(100);
digitalWrite(13,LOW);

digitalWrite(11,LOW);

digitalWrite(12,LOW);

digitalWrite(13,LOW);
delay(150);

digitalWrite(11,HIGH);
digitalWrite(12,HIGH);
digitalWrite(13,HIGH);
delay(2000);
digitalWrite(13,LOW);

digitalWrite(11,LOW);

digitalWrite(12,LOW);

digitalWrite(13,LOW);
delay(150);
digitalWrite(13,HIGH);
delay(100);
digitalWrite(12,HIGH);
delay(100);
digitalWrite(12,HIGH);
delay(100);


}
