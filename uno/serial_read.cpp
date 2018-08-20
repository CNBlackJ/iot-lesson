#include <Arduino.h>

int LED_PIN = 13;
int val;

void setup() {
		Serial.begin(9600);
		pinMode(LED_PIN, OUTPUT);
}

void loop() {
		val = Serial.read(); // 读取向串口发送的数据，每次只读一个字节数据
		if (-1 != val) {     // 没有数据到达，val为-1；有数据到达，val为数据中第一个字符的ASCII码
		  Serial.print("val : ");
			Serial.println(val);
			if ('H' == val) {
				digitalWrite(LED_PIN, HIGH);
				delay(500);
				digitalWrite(LED_PIN, LOW);
				Serial.print("Available: ");
				Serial.println(Serial.available(), DEC); // 返回串口缓冲区剩余的字符个数;最多缓冲128个字节
			}
		}
}