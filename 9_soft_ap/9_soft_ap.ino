#include<ESP8266WiFi.h>
String ssid="";
String password="";
char s=0,p=0;
int flag=0;
char ss[50],pwd[50];
void ssidread()
{
    while(1)
    {
      if(Serial.available()>0)
      {
        s=Serial.read();
        if(s=='\n')
          break;
        else
          ssid+=s;
      }
    }
}
void pwdread()
{
    while(1)
    {
      if(Serial.available()>0)
      {
        p=Serial.read();
        if(p=='\n')
          break;
        else
          password+=p;
      }
    }
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.mode(WIFI_AP);
  Serial.println("Enter desired SSID: ");
  ssidread();
  Serial.println("Enter password(>=8 characters): ");
  pwdread();
  Serial.print("You entered\nSSID: ");
  Serial.println(ssid);
  Serial.print("Password: ");
  Serial.println(password);
  ssid.toCharArray(ss,50);
  password.toCharArray(pwd,50);
  flag=WiFi.softAP(ss,pwd);
  if(flag==1)
    Serial.println("AP Created successfully!");
  else
    Serial.println("Failed!");
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
