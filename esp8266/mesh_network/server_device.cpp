#include <ESP8266WiFi.h>
#include <ESP8266WiFiMesh.h>

unsigned int request_i = 0;
unsigned int response_i = 0;

#define LED_PIN = D2  // 定义LED灯输出引脚
#define SW_PIN = D0   // 定义开关控制输入引脚

String manageRequest(String request);
ESP8266WiFiMesh mesh_node = ESP8266WiFiMesh(ESP.getChipId(), manageRequest);

String manageRequest(String request)
{
    Serial.print("received: ");
    Serial.println(request);

    char response[60];
    sprintf(response, "Hello world response #%d from Mesh_Node%d.", response_i++, ESP.getChipId());
    if (request == "ON") {         // 收到的消息是"ON"
      digitalWrite(LED_PIN, HIGH); // 打开LED
      delay(500);                  // 延迟500毫秒
    }
    digitalWrite(LED_PIN, LOW);    // 关闭LED
    return response;
}

void setup()
{
    Serial.begin(115200);
    delay(10);

    pinMode(LED_PIN, OUTPUT);
    pinMode(SW_PIN, INPUT);

    Serial.println();
    Serial.println();
    Serial.println("Setting up mesh node...");

    mesh_node.begin();
}

void loop()
{
    mesh_node.acceptRequest();

    int ledStatus = digitalRead(SW_PIN); // 读取开关的状态
    if (ledStatus == 1) {
      char request[2];
      sprintf(request, "ON");
      mesh_node.attemptScan(request);    // 发送打开LED灯的消息："ON"
    } else {
      char request[60];
      sprintf(request, "Hello world request #%d from Mesh_Node%d.", request_i++, ESP.getChipId());
      mesh_node.attemptScan(request); 
    }
    delay(1000);
}