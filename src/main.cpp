#include <Arduino.h>
#include <IRremote.h>

// int RESV_PIN = 11;
// IRrecv irrecv(RESV_PIN);
// decode_results results;

IRsend irsend;

void setup ()
{
  Serial.begin(9600);
  // irrecv.enableIRIn();
}
void loop()
{
  int val = Serial.read(); // 读取向串口发送的数据，每次只读一个字节数据
  if (-1 != val) {     // 没有数据到达，val为-1；有数据到达，val为数据中第一个字符的ASCII码
    Serial.print("val : ");
    Serial.println(val);
    if ('h' == val) {
      // on: 807FC03F
      // off: 722B04B7
      irsend.sendNEC(0x807FC03F, 32);
    }
    if ('j' == val) {
      // on: 807FC03F
      // off: 722B04B7
      irsend.sendNEC(0x722B04B7, 32);
    }
  }

  // if(irrecv.decode(&results)) {
  //   Serial.println(results.value, HEX);
  //   Serial.println();
  //   irrecv.resume();
  // }
  delay(2000);
}