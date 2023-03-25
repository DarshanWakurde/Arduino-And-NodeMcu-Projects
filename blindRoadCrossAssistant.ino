const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;
const int trigPin1 = 11;
const int echoPin1= 12;
long duration1;
int distance1;
const int buz=6;

#include <Servo.h>
Servo myservo;
void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  myservo.attach(8); 
  Serial.begin(9600); 
  pinMode(buz,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
    digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1 * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance1);
  if(distance<5)
  {
    if(distance1>5)
    {
    myservo.write(180);
    mstart();
    buzstr();
    }
    delay(5000);
  }
  else if(distance1<5)
  {
    if(distance>5)
    {
    myservo.write(0);
    mstop();
    buzend();
    }
    
  }
 else
 {
  myservo.write(0);
  mstop();
 }

}

void mstart(){
digitalWrite(7,HIGH);
digitalWrite(8,LOW);
}
void mstop(){
digitalWrite(7,LOW);
digitalWrite(8,LOW);
}

void buzstr()
{
  digitalWrite(buz,HIGH);
  delay(250);
    digitalWrite(buz,LOW);
    delay(100);
  
  digitalWrite(buz,HIGH);
  delay(350);
    digitalWrite(buz,LOW);
    delay(100);
  
  digitalWrite(buz,HIGH);
  delay(450);
    digitalWrite(buz,LOW);
    delay(100);
  
  digitalWrite(buz,HIGH);
  delay(550);
    digitalWrite(buz,LOW);
    delay(100);
  
}

void buzend()
{
  digitalWrite(buz,HIGH);
  delay(550);
    digitalWrite(buz,LOW);
    delay(100);
  
  digitalWrite(buz,HIGH);
  delay(450);
    digitalWrite(buz,LOW);
    delay(100);
  
  digitalWrite(buz,HIGH);
  delay(350);
    digitalWrite(buz,LOW);
    delay(100);
  
  digitalWrite(buz,HIGH);
  delay(250);
    digitalWrite(buz,LOW);
    delay(100);
}
