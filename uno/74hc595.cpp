#include <Arduino.h>

int latchPin = 8;
int clockPin = 12;
int dataPin = 11; //这里定义了那三个脚
void setup ()
{
  Serial.begin(9600);
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT); //让三个脚都是输出状态
}
void loop()
{
  for(int a=0; a<256; a++)   //这个循环的意思是让a这个变量+1一直加到到256，每次循环都进行下面的活动
  {
    digitalWrite(latchPin,LOW); //将ST_CP口上面加低电平让芯片准备好接收数据
    shiftOut(dataPin,clockPin,MSBFIRST,a);
    //这个就是用MSBFIRST参数让0-7个针脚以高电平输出（LSBFIRST 低电平）是dataPin的参数，
    //clockPin的参数是变量a，前面我们说了这个变量会一次从1+1+到256，是个十进制数，
    // 输入到芯片后会产生8个二进制数，达到开关的作用
    Serial.println(a);
    digitalWrite(latchPin,HIGH); //将ST_CP这个针脚恢复到高电平
    delay(1000); //暂停1秒钟让你看到效果
  }
  // digitalWrite(latchPin,LOW); //将ST_CP口上面加低电平让芯片准备好接收数据
  // shiftOut(dataPin,clockPin,MSBFIRST,255);
  // digitalWrite(latchPin,HIGH); //将ST_CP这个针脚恢复到高电平
  // delay(500);
}