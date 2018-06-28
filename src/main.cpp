#include <Arduino.h>

void setup()
{
   Serial.begin(9600); // 打开串口，设置波特率为9600 bps
}
void loop()
{
   int val;
   val=analogRead(0);   //传感器接于模拟口0

   int val1;
   val1 = digitalRead(0);

   Serial.print(" A0 , D0 : ")
   Serial.print(val)
   Serial.print(" , ")
   Serial.println(val1)
   delay(100);
}