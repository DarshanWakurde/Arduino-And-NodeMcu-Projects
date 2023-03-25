#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
Adafruit_MPU6050 mpu;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("Adafruit MPU6050 test!");

  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

}

void loop() {
  // put your main code here, to run repeatedly:
sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
    Serial.print("Acceleration X: ");
  Serial.print(a.acceleration.x);
  delay(1000);
  Serial.print(", Y: ");
  Serial.print(a.acceleration.y);
  delay(1000);
  Serial.print(", Z: ");
  Serial.print(a.acceleration.z);
  delay(1000);
}
