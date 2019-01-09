#include<ESP8266WiFi.h>
int num=0,i,ctr=0;
char s=0,p=0;
String ssid="";
int flag=0;
String password="";
char ss[50],pwd[50];
void ssidread()
{
   // Serial.println("I'm in SSID read");
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
   //Serial.println("I'm in pwd read");
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

void setup() 
{
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  Serial.begin(115200);
}

void loop() 
{
  delay(1000);
  num=WiFi.scanNetworks();
  Serial.print("Number of networks found= ");
  Serial.println(num);
  if(num==0)
    Serial.println("No networks found");
  else
    {
      Serial.println("  SSID(s)");
      for(i=0;i<num;i++)
      {
        Serial.print(i+1);
        Serial.print(" : ");
        Serial.println(WiFi.SSID(i));
      }
    }
  ssid="";
  password="";
  Serial.println("Enter the SSID of the network you want to connect to: ");
  ssidread();  
  Serial.println("Enter the password: ");
  pwdread();
  Serial.print("You entered\nSSID: ");
  Serial.println(ssid);
  Serial.print("Password: ");
  Serial.println(password);
  //delay(5000);  
  ssid.toCharArray(ss,50);
  password.toCharArray(pwd,50);
  WiFi.begin(ss,pwd);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    Serial.print(".");
    ctr++;
    if(ctr==15)
    {
      Serial.println("Connection timed out!");
      break;
    }
  }
  if(WiFi.status()==WL_CONNECTED)
    Serial.println("Connected!");
  else
    Serial.println("FAILED!, please recheck the credentials");
  delay(3000);

}
