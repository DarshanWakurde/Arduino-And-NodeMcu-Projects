#include <Servo.h>
#define buzz 13
Servo m;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(A0,INPUT);
  m.attach(7);
  digitalWrite(13,LOW);
  Serial.begin(9600);
}

void loop()
{
  float x=analogRead(A0);
  float y= ((x-159)/352);
  Serial.println(x);
  
  
  int angle=(y*180);
  Serial.println(angle);
  m.write(angle);
  if(angle<170){
  digitalWrite(13,HIGH); 
  }
}
