

#include <SoftwareSerial.h>



SoftwareSerial espSerial(5, 6);
String str;
float h, t;
void setup(){
  
  Serial.begin(115200);
  espSerial.begin(115200);
  delay(2000);
}

void loop(){

  Serial.print("Temperature = ");
  
  Serial.print("Humidity = ");

  str ="hi";
  espSerial.println(str);

  delay(2000);
}
