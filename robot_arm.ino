


#include <Servo.h>
int VRx = A0;
int VRy = A1;
Servo myservo;
Servo myservo1;
void setup() 
{
  Serial.begin(9600);
  myservo.attach(9);
  myservo1.attach(10);
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
 

}

void loop() {
 int xPosition = analogRead(VRx);
 int yPosition = analogRead(VRy);

  Serial.print(xPosition);
  Serial.print("\t");
  Serial.println(yPosition);
 

   int ang=map(xPosition,0,1023,0,180);
   int ang1=map(yPosition,0,1023,0,180);

  myservo.write(ang);
   myservo1.write(ang1);

}
