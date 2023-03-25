
void setup() {
  // put your setup code here, to run once:
pinMode(8,INPUT);
pinMode(13,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

if(digitalRead(8)==LOW)
{
  digitalWrite(13,HIGH);
 
}
 if(digitalRead(13==HIGH))
  {
  Serial.println("OBJECT DETECTED");
  delay(5000);
  }
else
{
  digitalWrite(13,LOW);
}

}
