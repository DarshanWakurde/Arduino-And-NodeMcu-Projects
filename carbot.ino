int Incoming_value = 0;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(6,OUTPUT); // led red pin
 pinMode(7,OUTPUT); // led green pin
 pinMode(8,OUTPUT); // led blue pin
 pinMode(9,OUTPUT); // led white pin
 pinMode(10,OUTPUT); // led yellow pin
 pinMode(A1,INPUT);
 pinMode(A0,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 int x=analogRead(A1);
  int y=analogRead(A2);
  Serial.print(x);
  Serial.print("   ");
  Serial.println(y);
if(y==0)
{
 digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
}
else if(y>1200) 
{
 digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
}
 else if(x>1200)
{
 digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
}
else if(x==0)
{
   digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
}

  }
