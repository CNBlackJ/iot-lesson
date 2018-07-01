#include "painlessMesh.h"

#define   MESH_PREFIX     "ESPMESH"     // 设置当前MESH网络的名称
#define   MESH_PASSWORD   "mypassword"  // 密码
#define   MESH_PORT       5555          // 端口

painlessMesh  mesh;

void receivedCallback( uint32_t from, String &msg );

void sendMsg(int lesStatus) {
    // 以json的形式进行包装数据
    // 为什么用json：
    // https://gitlab.com/painlessMesh/painlessMesh#json-based
    DynamicJsonBuffer jsonBuffer;
    JsonObject& msg = jsonBuffer.createObject();
    msg["msgId"] = millis();
    msg["topic"] = "ledStatus";
    msg["status"] = lesStatus;
    msg["nodeId"] = mesh.getNodeId();

    String str;
    msg.printTo(str);         // 把json转成string
    mesh.sendBroadcast(str);  // 发送广播消息

    msg.printTo(Serial);
    Serial.printf("\n");
}

void setup() {
  Serial.begin(115200);
  mesh.setDebugMsgTypes( ERROR | CONNECTION | S_TIME ); // 设置需要展示的debug信息(打印到串口监视器)
  mesh.init( MESH_PREFIX, MESH_PASSWORD, MESH_PORT, WIFI_AP_STA, 6 ); // 初始化mesh网络

  mesh.onNewConnection([](size_t nodeId) {          // 新节点接入的时候
    Serial.printf("New Connection %u\n", nodeId);   // 打印节点唯一id
  });

  mesh.onDroppedConnection([](size_t nodeId) {        // 节点连接丢失的时候
    Serial.printf("Dropped Connection %u\n", nodeId); // 打印丢失的节点id
  });

  mesh.onReceive(&receivedCallback);                  // 收到消息的时候，执行receivedCallback()
}

void loop() {
  int lesStatus = digitalRead(D0);  // 获取开关状态
  if (lesStatus == 1) {             // 状态是1
    sendMsg(lesStatus);             // 把状态消息发送出去
  } else {
    Serial.println("status 0");
  }
  mesh.update();                    // 更新mesh网络
  delay(1000);
}

void receivedCallback( uint32_t from, String &msg ) { // 收到消息的时候，执行该回调方法，打印收到的消息
  Serial.printf("control server: Received from %u msg=%s\n", from, msg.c_str());
}