#define vx A0
#define vy A1

void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  pinMode(vx,INPUT);
  pinMode(vy,INPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(analogRead(vx));
  Serial.print("\t");
  Serial.println(analogRead(vy));
  delay(500);
  
  

}
