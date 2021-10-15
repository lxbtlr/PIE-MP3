<<<<<<< HEAD:Motor_test/Motor_test.ino
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <PID_v1.h> // Brett Beauregard PID library 
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotor_R = AFMS.getMotor(3);
Adafruit_DCMotor *myMotor_L = AFMS.getMotor(4);
int speed_L = 0;
int speed_R = 0;
int i = 0;
int t = 0;
int diff;

double Setpoint, Input, Output; //variables that are critical for PID control
//Specify the links and initial tuning parameters
double Kp=2, Ki=5, Kd=1;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup() {
  long baudRate = 115200;       // NOTE1: The baudRate for sending & receiving programs must match
  Serial.begin(baudRate);     // NOTE2: Set the baudRate to 115200 for faster communication  
  
}

void loop() {
  speed_L = 100;
  Serial.print(speed_L);
  speed_R = 100;
  myMotor_L->setSpeed(speed_L);
  myMotor_R->setSpeed(speed_R);
  myMotor_L->run(FORWARD);
  myMotor_R->run(BACKWARD);
}
=======
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <PID_v1.h> // Brett Beauregard PID library 
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotor_R = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor_L = AFMS.getMotor(2);
Adafruit_DCMotor *myMotor_1 = AFMS.getMotor(3);
Adafruit_DCMotor *myMotor_2 = AFMS.getMotor(4);
int speed_L = 100;
int speed_R = 100;
int i = 0;
int t = 0;
int diff;


void setup() {
  long baudRate = 115200;       // NOTE1: The baudRate for sending & receiving programs must match
  Serial.begin(baudRate);     // NOTE2: Set the baudRate to 115200 for faster communication  
  
}

void loop() {
  speed_L = 100;
  speed_R = 100;
  myMotor_L->setSpeed(speed_L);
  myMotor_R->setSpeed(speed_R);
  myMotor_1->setSpeed(speed_L);
  myMotor_2->setSpeed(speed_R);
  myMotor_L->run(FORWARD);
  myMotor_R->run(FORWARD);
  myMotor_1->run(FORWARD);
  myMotor_2->run(FORWARD);
//  delay(3000);
//  speed_L = 150;
//  speed_R = 50;
//  myMotor_L->setSpeed(speed_L);
//  myMotor_R->setSpeed(speed_R);
//  myMotor_L->run(FORWARD);
//  myMotor_R->run(FORWARD);
//  delay(3000);
//  speed_L = 50;
//  speed_R = 150;
//  myMotor_L->setSpeed(speed_L);
//  myMotor_R->setSpeed(speed_R);
//  myMotor_L->run(FORWARD);
//  myMotor_R->run(FORWARD);
//  delay(3000);
}
>>>>>>> 6612e341bd659e2d1aedb107a6a8af4b2fd3b7f5:Robot_moving_test/Robot_moving_test.ino
