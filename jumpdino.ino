#include <Servo.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Servo.h>
Adafruit_MPU6050 mpu;
Servo myservo; 
void setup() {
   myservo.attach(9);
  // put your setup code here, to run once:
 Serial.begin(9600);
  while (!Serial)
    delay(10);
      if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");
}

void loop() {
   sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  float avg=abs(g.gyro.x);
  Serial.println(avg);
  delay(500);  
  
if(avg>2)
{
  myservo.write(30);
  delay(250);
  myservo.write(0);
  delay(250);
  
}
}
