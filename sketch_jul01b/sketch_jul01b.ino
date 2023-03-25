void setup() {
pinMode(13,OUTPUT);
Serial.begin(9600);
}

void loop() {
  digitalWrite(13,LOW);
  delay(2500);
    digitalWrite(13,HIGH);
  delay(5000);
}
