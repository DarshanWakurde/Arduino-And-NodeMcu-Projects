#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;
int red_light_pin= 9;
int green_light_pin = 13;
int blue_light_pin = 11;

void setup(void) {
  
  Serial.begin(115200);
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens
      pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  pinMode(13,OUTPUT);

  Serial.println("Adafruit MPU6050 test!");

  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

  //setupt motion detection
  mpu.setHighPassFilter(MPU6050_HIGHPASS_0_63_HZ);
  mpu.setMotionDetectionThreshold(1);
  mpu.setMotionDetectionDuration(20);
  mpu.setInterruptPinLatch(true);  // Keep it latched.  Will turn off when reinitialized.
  mpu.setInterruptPinPolarity(true);
  mpu.setMotionInterrupt(true);

  Serial.println("");
  delay(100);
}

void loop() {

  if(mpu.getMotionInterruptStatus()) {
    /* Get new sensor events with the readings */
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    /* Print out the values */
    Serial.print("AccelX:");
    Serial.println(a.acceleration.x);
  
    Serial.print("AccelY:");
    Serial.println(a.acceleration.y);
 
    Serial.print("AccelZ:");
    Serial.println(a.acceleration.z);

   float x=a.acceleration.x;
   float y=a.acceleration.y;
   float z=a.acceleration.z;

    if ((x<2) && (z < (2))&&(y>5))
  {
    Serial.println("3");
    int number = 3;
 
    digitalWrite(9,HIGH);
    digitalWrite(13,LOW);// Blue
  }

  else if ((x<2) && (z < (2))&&(y<0))
  {
    Serial.println("1");
    digitalWrite(13,HIGH);
        digitalWrite(9,LOW);// Red
    }

  else if ((x<2)&&(y<2)&&(z>6))
  {
    Serial.println("4");
   
     digitalWrite(9,LOW);
     digitalWrite(13,LOW);// Cyan
  }
  delay(100);
    
}
}
