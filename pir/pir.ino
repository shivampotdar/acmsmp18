
void setup() {
  // put your setup code here, to run once:
  pinMode(PIRin,INPUT);
  pinMode(LED,OUTPUT);
  pinMode(buzz,OUTPUT);
  digitalWrite(LED,LOW);
  digitalWrite(buzz,LOW);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(PIRin)==HIGH)
  {
     Serial.print("Motion Detected!");
     pirres="Yes";
     digitalWrite(LED,HIGH);
     delay(1000);
     digitalWrite(LED,LOW); 
     digitalWrite(buzz,HIGH);
     delay(500);
     digitalWrite(buzz,LOW);
   }
  delay(2000);
}
