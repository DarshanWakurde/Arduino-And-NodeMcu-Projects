       int Incoming_value = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  if (Serial.available() > 0)
  {
    Incoming_value = Serial.read();
   
    Serial.print(Incoming_value);
  if(Incoming_value=='a')
  {
    digitalWrite(8,HIGH);
    digitalWrite(7,LOW);
  }
  else if(Incoming_value=='b')
  {
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
  }
  else
  {
    digitalWrite(8,LOW);
    digitalWrite(7,LOW);
  }
  }
}
