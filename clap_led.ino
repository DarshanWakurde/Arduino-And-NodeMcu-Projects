int soundSensor=8;
int LED=13;
boolean LEDStatus=false;

void setup() {
  Serial.begin(9600);
 pinMode(soundSensor,INPUT);
 pinMode(LED,OUTPUT);

}

void loop() {

  int SensorData=digitalRead(soundSensor); 
  Serial.println(SensorData);
  delay(500);
  

  
 } 
