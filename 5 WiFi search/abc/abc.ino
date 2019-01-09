#include<ESP8266WiFi.h>
int num=0;
int i=0;
void setup()
{
    WiFi.mode(WIFI_STA);   //station mode
    WiFi.disconnect();
    Serial.begin(115200);
   
}
void loop()
{
  num=WiFi.scanNetworks();
  Serial.print("Number of networks found=  ");
  Serial.println(num);
  if(n==0)
    println("No networks found");
  else
  {
  Serial.println("SSID");
  
  for(i=0;i<=num;i++)
  {
    Serial.println(WiFi.SSID(i));
  }
  }
} 

