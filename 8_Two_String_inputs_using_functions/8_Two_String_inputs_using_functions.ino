char s=0,p=0;
String ssid="";
String password="";
char ss[50],pd[50];
void ssidread()
{
    Serial.println("I'm in SSID read");
    while(1)
    {
      if(Serial.available()>0)
      {
        s=Serial.read();
        if(s=='\n')
          break;
        else
          {*ss=s;
           *ss+=sizeof(char);
          }
      }
    }
}
void pwdread()
{
   Serial.println("I'm in pwd read");
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
  Serial.begin(115200);
}

void loop() 
{
  ssid="";
  password="";
  Serial.println("Enter the SSID of the network you want to connect to: ");
  ssidread();  
  Serial.println("Enter the password: ");
  pwdread();
  Serial.println(ssid);
  Serial.println(password);
  ssid.toCharArray(ss,50);
  password.toCharArray(pd,50);
  Serial.println(ss);
  Serial.println(pd);
  delay(5000);
}
