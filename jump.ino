   #include <Servo.h>
#define ldr 8
Servo myservo; 
void setup() {
myservo.attach(3);   
 pinMode(ldr,INPUT);
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int no=digitalRead(ldr);
Serial.print(no);
if(no==0){
  myservo.write(50);
  delay(100);
  myservo.write(0);
  
}
}
