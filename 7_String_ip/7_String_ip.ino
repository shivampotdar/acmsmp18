char abc=0;
String ip="";
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()>0)
  {
    abc=Serial.read();
        if(abc=='x')
      ip="";
    if(abc!='\n')
      ip+=abc;

              
  }
  Serial.print("ip=");
  Serial.println(ip);
  delay(100);
}
