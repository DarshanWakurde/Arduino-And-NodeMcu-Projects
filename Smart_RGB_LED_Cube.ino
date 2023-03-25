

int red_light_pin= 9;
int green_light_pin = 10;
int blue_light_pin = 11;

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);


// SDA D2    SCL D1
void setup()
{
  Serial.begin(9600);
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  
// SCL 2   SDA 0    Nano A4 SDA    A5 SCL
  
  
  while (!accel.begin())          
  {
    Serial.println("No valid sensor found");
    delay(100);
  }
  
Serial.println("No");
}
void loop()
{
  
  sensors_event_t event;
  accel.getEvent(&event);
//     Serial.print("X: "); Serial.print(event.acceleration.x); Serial.print("  ");
//     Serial.print("Y: "); Serial.print(event.acceleration.y); Serial.print("  ");
//     Serial.print("Z: "); Serial.print(event.acceleration.z); Serial.print("  ");
//     Serial.println("m/s^2 ");
//  delay(500);
  float x = event.acceleration.x;
  float y = event.acceleration.y;
  float z = event.acceleration.z;

  if ((y < 11) && (y > 8))
  {
    Serial.println("3");
    int number = 3;
    RGB_color(0, 0, 255); // Blue
  }

  else if ((y > (-11)) && (y < (-8)))
  {
    Serial.println("1");
    int number = 1;
    RGB_color(255, 0, 0); // Red
    }

  else if ((z < 11) && (z > 8))
  {
    Serial.println("4");
    int number = 4;
    RGB_color(0, 255, 255); // Cyan
  }

  else if ((z > (-11)) && (z < (-8)))
  {
    Serial.println("2");
    int number = 2;
    RGB_color(0, 255, 0); // Green
    }
  //
    else if ((x > (8)) && (x < (11)))
  {
    Serial.println("5");
    int number = 5;
    RGB_color(255, 255, 0); // Yellow
    }
    else if ((x > (-11)) && (x < (-8)))
  {
    Serial.println("6");
    int number = 6;
    RGB_color(0, 0, 0); // White
    }
    delay(500);
}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
