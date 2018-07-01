#include "painlessMesh.h"

#define   MESH_PREFIX     "ESPMESH"     // 名称/密码/端口一致才能连接到同一个mesh网络
#define   MESH_PASSWORD   "mypassword"
#define   MESH_PORT       5555

void receivedCallback( uint32_t from, String &msg );

painlessMesh  mesh;

void setup() {
  Serial.begin(115200);
  pinMode(D2, OUTPUT);
    
  mesh.setDebugMsgTypes( ERROR | STARTUP | CONNECTION );

  mesh.init( MESH_PREFIX, MESH_PASSWORD, MESH_PORT );
  mesh.onReceive(&receivedCallback);
}

void loop() {
  mesh.update();
}

void receivedCallback( uint32_t from, String &msg ) { // 被控制设备接收到消息，执行该回调
  Serial.printf("echoNode: Received from %u msg=%s\n", from, msg.c_str());
  mesh.sendSingle(from, msg);

  // 重新把string转化成json进行解析
  DynamicJsonBuffer jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(msg);
  if (root.containsKey("topic")) {
    if (String("ledStatus").equals(root["topic"].as<String>())) {
      digitalWrite(D2, root["status"].as<uint32_t>()); // 打开D2引脚控制的led
      delay(500);
    }
  }
  digitalWrite(D2, LOW);
}