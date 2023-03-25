#include <SimpleDHT.h>
int pinDHT22 = 2;

  float temperature = 0;
  float humidity = 0;
  DHT dht(2, DHTTYPE);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
     temperature =  dht.readTemperature();
       Serial.print((int)temperature); Serial.print(" *C, "); 

}
