#define BLYNK_PRINT Serial 
#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp8266.h> 
#include <Servo.h>
 
 
char auth[] = "b25846ffa649429fac7f6b28ab524adc"; 
 
char ssid[] = "GrowthAI.tech"; 
char pass[] = "GrowthAI"; 
 
int forWard=D1;      // forward
int backWard=D2;     // backward
int turnRight=D3;    // turnright
int turnLeft=D4;     // turnleft
int autoMode=D5;     // auto run
 
void setup(){ 
  // Debug console 
  Serial.begin(9600); 
  Blynk.begin(auth, ssid, pass); 
  pinMode(forWard, OUTPUT);
  pinMode(backWard, OUTPUT);
  pinMode(turnRight, OUTPUT);
  pinMode(turnLeft, OUTPUT);
	pinMode(autoMode, OUTPUT);
} 

void loop(){ 
  Blynk.run(); 
}
 
// Handling Joystick data 
BLYNK_WRITE(V1){ 
  int x = param[0].asInt(); 
  int y = param[1].asInt();

	if(x==1) { // forward
		digitalWrite(forWard, HIGH);
		digitalWrite(backWard, LOW);
		digitalWrite(turnRight, LOW);
		digitalWrite(turnLeft, LOW);
		digitalWrite(autoMode, LOW);
	} else if (x == -1) { // backward
		digitalWrite(forWard, LOW);
		digitalWrite(backWard, HIGH);
		digitalWrite(turnRight, LOW);
		digitalWrite(turnLeft, LOW);
		digitalWrite(autoMode, LOW);
	} else if (x == 0){ // stop
		digitalWrite(forWard, LOW);
		digitalWrite(backWard, LOW);
		digitalWrite(turnRight, LOW);
		digitalWrite(turnLeft, LOW);
		digitalWrite(autoMode, LOW);
	} else if (y == 1) { // turn right
		digitalWrite(forWard, LOW);
		digitalWrite(backWard, LOW);
		digitalWrite(turnRight, HIGH);
		digitalWrite(turnLeft, LOW);
		digitalWrite(autoMode, LOW);
	} else if (y == -1) { // turn left
		digitalWrite(forWard, LOW);
		digitalWrite(backWard, LOW);
		digitalWrite(turnRight, LOW);
		digitalWrite(turnLeft, HIGH);
		digitalWrite(autoMode, LOW);
	} else if (y == 0) { // stop
		digitalWrite(forWard, LOW);
		digitalWrite(backWard, LOW);
		digitalWrite(turnRight, LOW);
		digitalWrite(turnLeft, LOW);
		digitalWrite(autoMode, LOW);
	}
}  
