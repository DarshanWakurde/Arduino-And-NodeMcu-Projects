 int ldr = 0; 
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
  
}

void loop()
{
  ldr = digitalRead(12);
 if (ldr == LOW)
      digitalWrite(13, HIGH);
 else
      digitalWrite(13, LOW);
}
