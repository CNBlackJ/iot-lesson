#include <Arduino.h>
#include <AudioFileSourceSPIFFS.h>
#include <AudioGeneratorMP3.h>
#include <AudioOutputI2SNoDAC.h>

AudioGeneratorMP3 *mp3;
AudioFileSourceSPIFFS *file;
AudioOutputI2SNoDAC *out;

// 0: stop to play
// 1: 1.mp3
// 2: 2.mp3
// 3: 3.mp3
// 4: 4.mp3
int flag = 0;
int val;

int TOUCH_HEAD_PIN = 2;
int TOUCH_BACK_PIN = 3;
int TOUCH_BUM_PIN = 4;

bool isTouch = false;

void setup(){
  Serial.begin(9600);
  pinMode(TOUCH_HEAD_PIN, INPUT);
  pinMode(TOUCH_BACK_PIN, INPUT);
  pinMode(TOUCH_BUM_PIN, INPUT);
  
  delay(1000);
  SPIFFS.begin();
  out = new AudioOutputI2SNoDAC();
  mp3 = new AudioGeneratorMP3();
}

void loop()
{
  headVal = digitalRead(TOUCH_HEAD_PIN);
  backVal = digitalRead(TOUCH_BACK_PIN);
  bumVal = digitalRead(TOUCH_BUM_PIN);

  headBackVal = headVal + backVal;
  headBumVal = headVal + bumVal;
  backBumVal = backVal + bumVal;

  isTouch = headVal + backVal + bumVal;

  if (isTouch) {
      
  }

  
  
  if (val >= 20 && val < 30) {
    Serial.print("val : ");
    Serial.println(val);
    flag = 1;
  } else if (val >= 30) {
    Serial.print("val : ");
    Serial.println(val);
    flag = 2;
  }

  
  if (mp3->isRunning()) {
    if (!mp3->loop()){
       mp3->stop();
       delete file;
       delete mp3;
       mp3 = new AudioGeneratorMP3();
    }
  } else {
    if (flag == 1) {
      Serial.println("playing 1.mp3");
      file = new AudioFileSourceSPIFFS("/1.mp3");
    } else if (flag == 2) {
      Serial.println("palying tone4.mp3");
      file = new AudioFileSourceSPIFFS("/tone4.mp3");
    } else {
      flag = 0;
    }
    if (flag != 0) {
      flag = 0;
      delay(5000);
      mp3->begin(file, out);  
    }
  }
}