#include <ESP8266WiFi.h>
//constchar* ssid = "POTDAR";
//constchar* password = "godhdya123";
void setup(void)
{
// Start Serial
  Serial.begin(115200);
// Connect to WiFi
  WiFi.begin("Shivam's iPhone", "starwars123");
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
// Print the IP address
  Serial.println(WiFi.localIP());
}
void loop() 
{
}
