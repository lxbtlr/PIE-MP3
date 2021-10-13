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
