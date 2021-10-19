#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <PID_v1.h> // Brett Beauregard PID library 
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotor_R = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor_L = AFMS.getMotor(4);


int speed_L = 0;
int speed_R = 0;
int i = 0;
int t = 0;
int diff;

void setup() {
  long baudRate = 115200;       // NOTE1: The baudRate for sending & receiving programs must match
  Serial.begin(baudRate);     // NOTE2: Set the baudRate to 115200 for faster communication  
  AFMS.begin();
  
}

void loop() {
  int base_speed = 60;
  speed_L = base_speed; //inicial motor speed in straigt line can change
  speed_R = base_speed; //inicial motor speed in straigt line can change
  myMotor_L->setSpeed(speed_L);
  myMotor_R->setSpeed(speed_R);
  myMotor_L->run(FORWARD);
  myMotor_R->run(FORWARD);
  delay(2000);
  base_speed = 30;
  speed_L = base_speed; //inicial motor speed in straigt line can change
  speed_R = base_speed; //inicial motor speed in straigt line can change
  myMotor_L->setSpeed(speed_L);
  myMotor_R->setSpeed(speed_R);
  myMotor_L->run(FORWARD);
  myMotor_R->run(FORWARD);
  delay(2000);
   base_speed = 15;
  speed_L = base_speed; //inicial motor speed in straigt line can change
  speed_R = base_speed; //inicial motor speed in straigt line can change
  myMotor_L->setSpeed(speed_L);
  myMotor_R->setSpeed(speed_R);
  myMotor_L->run(FORWARD);
  myMotor_R->run(FORWARD);
  delay(2000);
}
