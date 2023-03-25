
#include <SoftwareSerial.h>

SoftwareSerial espSerial(5, 6);

String str;
void setup(){
Serial.begin(115200);
espSerial.begin(115200);
delay(2000);
}
void loop()
{
Serial.print("H: ");

Serial.print("% ");
Serial.print(" T: ");

Serial.println("C");
str =String("coming from arduino: ")+String("H= ")+String("T= ");
espSerial.println("hello");
delay(1000);
}
