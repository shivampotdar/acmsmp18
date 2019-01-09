int ctr=0,curstate=0,prevstate=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(3,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  curstate=digitalRead(3);
  if(curstate!=prevstate)
    {
      if(curstate==1)
      ctr++;
    }
  if(ctr==5)
    {
      digitalWrite(2,HIGH);
      delay(700);
      digitalWrite(2,LOW);
      ctr=0;
    }
  prevstate=curstate;
  Serial.print("ctr=");
  Serial.println(ctr);
  delay(100);
}
