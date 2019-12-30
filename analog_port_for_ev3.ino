#include <Wire.h>

#define SLAVE_ADDRESS 0x04
void setup() 
{
    Wire.begin(SLAVE_ADDRESS);
    Wire.onReceive(receiveData);
    Wire.onRequest(sendData);
}
int pin,st,val=0,flag=0,index=0;
char buf[8];
byte b[1];
void loop()
{
  if(flag==1)
  {
    flag=0;
    Serial.println(pin);
    val=analogRead(pin);
    b[0] = map(val,0,1024, 100, 0);

  }
}

void receiveData(int byteCount)
{
    while(Wire.available()>0) 
    {
      pin=Wire.read();
      flag=1;
    }
}

void sendData()
{
  Wire.write(b,1);
}
