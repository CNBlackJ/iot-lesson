#include <HCSR04.h>
//#include <SoftwareSerial.h>

int E1 = 10;
int M1 = 12;
int E2 =11;
int M2 = 13;

int distancecm=0; 
const int trigPin = 8; 
const int echoPin = 9;
UltraSonicDistanceSensor distanceSensor(trigPin, echoPin);

//SoftwareSerial mySerial(2, 3); 

long duration;
int distance; 
int run_mode = 0;

void setup() {
  Serial.begin(9600);
  //mySerial.begin(9600);
  pinMode(M1,OUTPUT);
  pinMode(M2,OUTPUT);
  stopRun();
}



void loop() { 
  //int value = mySerial.read();
  int value = Serial.read();

  if (value>-1) {
    //Serial.println(value);
     if (value == 5) {
      changeMode();
     }
  }

  
  if (run_mode>1) {
    beginAutoMode();
  } else {
    
    switch (value) {
      case 1: forward();break;
      case 2: backward();break;
      case 3: trunLeft();break;
      case 4: trunRight();break;
    }
  }

  delay(500);
}

void stopRun() {
	analogWrite(E1, 0);
	analogWrite(E2, 0);
}
  
void beginRun() {
  analogWrite(E1, 255);
  analogWrite(E2, 255);
}

void changeMode() {
	//Serial.println("Change mode");
	stopRun();
	
	run_mode=run_mode+1;
	
	if (run_mode==3){
		run_mode = 0;
		stopRun();
	} else {
		beginRun();
	}
		
	//Serial.print("run_mode =");
	//Serial.println(run_mode);
}


void forward() {
  //Serial.println("Go forward");
  digitalWrite(M1,LOW);
  digitalWrite(M2,LOW);
  beginRun();
}

void trunLeft() {
    //Serial.println("Go left");

  digitalWrite(M1,LOW);
  digitalWrite(M2,HIGH);
  beginRun();
}


void trunRight() {
    //Serial.println("Go right");

  digitalWrite(M1,HIGH);
  digitalWrite(M2,LOW);
  beginRun();
}

void backward() {
    //Serial.println("Go back");

  digitalWrite(M1,HIGH);
  digitalWrite(M2,HIGH);
  beginRun();
}

void beginAutoMode() {
  distancecm= distanceSensor.measureDistanceCm();
  // Serial.println(distancecm);
  if (distancecm>-1) {
    distance = distancecm  ;
  }
  
  if(distance<5) {

     //1.turn back
     digitalWrite(M1,HIGH);
     digitalWrite(M2, HIGH);
     delay(1000);
     //2. turn around
     digitalWrite(M1,LOW);
     delay(2000);
     digitalWrite(M1,HIGH);
     
  } else {
     digitalWrite(M1,LOW);
     digitalWrite(M2, LOW);
  }
}


