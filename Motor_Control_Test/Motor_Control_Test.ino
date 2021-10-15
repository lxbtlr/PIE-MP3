#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <PID_v1.h> // Brett Beauregard PID library 
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotor_R = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor_L = AFMS.getMotor(2);
int leftSense = A1;
int rightSense = A2;
int speed_L = 0;
int speed_R = 0;
int i = 0;
int t = 0;
int diff;

double Setpoint, Input, Output; //variables that are critical for PID control
//Specify the links and initial tuning parameters
double Kp=2, Ki=0, Kd=0;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup() {
  long baudRate = 115200;       // NOTE1: The baudRate for sending & receiving programs must match
  Serial.begin(baudRate);     // NOTE2: Set the baudRate to 115200 for faster communication  
  AFMS.begin();
  
  pinMode(leftSense, INPUT);
  pinMode(rightSense, INPUT);
 
  //initialize the variables we're linked to
  //Input = analogRead(PIN_INPUT); //will need to change
  Setpoint = 0;//should be the middle of the sensor range
  //turn the PID on
  myPID.SetMode(AUTOMATIC);//from PID library
  // put your setup code here, to run once:

}

void loop() {
  //PID implemetation code:
  int go_fast; //need for function call
  Input = sens_read();//calls the fuction sens_read and sets Imput to be the error
  myPID.Compute(); //calls the PID fuction and executes
  go_fast = motor_run(Output); //calls the funtion mot_run with the output from the PID.  Effectivly changes the motor speed
}

float sens_read(){
  //reads the 4 sensors and returns an angle at which the line is currently detected
  int L_sens = analogRead(leftSense);
  int R_sens = analogRead(rightSense);
  Serial.print(L_sens);
  Serial.print("  ");
  Serial.print(R_sens);
  Serial.println();
  int ang = abs(leftSense - rightSense);//definitly wrong
  Serial.print("  ang:");
  Serial.print(ang);
  Serial.println();
  return ang;
}

int motor_run(int Output){
  //makes the motors run with different speeds depending on the output from the PID
  diff = Output;
  Serial.print("  diff:"); 
  Serial.print(diff);
  Serial.println();
  speed_L = 50 - diff; //inicial motor speed in straigt line can change
  speed_R = 50 + diff; //inicial motor speed in straigt line can change
  myMotor_L->setSpeed(speed_L);
  myMotor_R->setSpeed(speed_R);
  myMotor_L->run(FORWARD);
  myMotor_R->run(FORWARD);
}
