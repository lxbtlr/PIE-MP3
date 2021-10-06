#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotor_R = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor_L = AFMS.getMotor(2);
int speed_L = 0;
int speed_R = 0;
int i = 0;
int t = 0;

void setup() {
  long baudRate = 115200;       // NOTE1: The baudRate for sending & receiving programs must match
  Serial.begin(baudRate);     // NOTE2: Set the baudRate to 115200 for faster communication  
  AFMS.begin();
  myMotor_L->setSpeed(speed_L);
  myMotor_R->setSpeed(speed_R);
  
  // put your setup code here, to run once:

}

void loop() {
  speed_L = 0;
  speed_R = 0;
  myMotor_L->setSpeed(speed_L);
  myMotor_R->setSpeed(speed_R);
  t = millis();
  Serial.println(t);
  if (i < t)
    myMotor_L->run(FORWARD);
    myMotor_R->run(FORWARD);
    i = millis();
  
  // put your main code here, to run repeatedly:

}
//function that takes in an angle and returns an 
