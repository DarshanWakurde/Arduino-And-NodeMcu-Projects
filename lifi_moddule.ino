


#define ldr 8

int val;
int val2;
String duration;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ldr, INPUT_PULLUP);
  Serial.println();
  Serial.print("LiFi Project");
  delay(3000);
  Serial.print("Send any message");
  Serial.print("from LiFi App..");
  delay(3000);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = digitalRead(ldr);
  while(val == 0)
  {
    int val2 = digitalRead(ldr);
    duration += val2;
    if(duration == "001")
    {
      Serial.println("Received message: hi");
      Serial.print("hi");
    }
    if(duration == "0001")
    {
      Serial.println("Received message: hello");
      Serial.print("hello");
    }      
    if(duration == "00001")
    {
      Serial.println("Received message: how are you?");
      Serial.print("how are you?");
    }
    if(duration == "000001")
    {
      Serial.println("Received message: I am fine");
      Serial.print("I am fine");
    }
    if(duration == "0000001")
    {
      Serial.println("Received message: ok");
      Serial.print("ok");
    }
    if(duration == "00000001")
    {
      Serial.println("Received message: good morning");
      Serial.print("good morning");
    }
    if(duration == "000000001")
    {
      Serial.println("Received message: good afternoon");
      Serial.print("good afternoon");
    }
    if(duration == "0000000001")
    {
      Serial.println("Received message: good evening");
      Serial.print("good evening");
    }
    if(duration == "00000000001")
    {
      Serial.println("Received message: thank you");
      Serial.print("thank you");
    }
    if(duration == "000000000001")
    {
      Serial.println("Received message: sorry");
      Serial.print("sorry");
    }
    if(val2 == 1)
    {
      duration = "";
      break;
    }
    delay(200);
  }
}
