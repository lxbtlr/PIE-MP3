#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotor_R = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor_L = AFMS.getMotor(2);

void setup() {
  
  AFMS.begin();
  myMotor_L->setSpeed(50);
  myMotor_R->setSpeed(50);
  
  // put your setup code here, to run once:

}

void loop() {
  myMotor_L->run(FORWARD);
  myMotor_R->run(FORWARD);
  // put your main code here, to run repeatedly:

}
