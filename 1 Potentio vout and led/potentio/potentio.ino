  int vin=0;
  int vout=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  pinMode(9,OUTPUT);
  Serial.begin(9600);
  vin=0;
}

void loop() {
  // put your main code here, to run repeatedly:
  vin=analogRead(A0);
  Serial.print("VIN=");
  Serial.print(vin);
  vout=map(vin,0,1023,255,0);
  Serial.print("          VOUT=");
  Serial.println(vout);
  analogWrite(9,vout);
  delay(10);
  

}
