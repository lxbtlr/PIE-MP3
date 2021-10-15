#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <PID_v1.h> // Brett Beauregard PID library 
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotor_R = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor_L = AFMS.getMotor(2);
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
  AFMS.begin();
 
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
  Serial.print('I');
  return 0;
}

int motor_run(int Output){
  //makes the motors run with different speeds depending on the output from the PID
  diff = Output; 
  speed_L = 100 - diff; //inicial motor speed in straigt line can change
  speed_R = 100 + diff; //inicial motor speed in straigt line can change
  myMotor_L->setSpeed(speed_L);
  myMotor_R->setSpeed(speed_R);
  myMotor_L->run(FORWARD);
  myMotor_R->run(FORWARD);
}
  
//}
//void turn(int angle, int speed_ang){
//  //function that takes in an angle in rad and angular speed and turns car.
//  int t = millis();
//  int turn_time;
//  speed_L = speed_ang;
//  speed_R = speed_ang;
//  myMotor_L->setSpeed(speed_L);
//  myMotor_R->setSpeed(speed_R);
//  turn_time = speed_ang/(angle*1000); //in milisecs
//  while (turn_time >= millis()-t){
//    
//    myMotor_L->run(FORWARD);
//    myMotor_R->run(BACKWARD);
//  }  
//}
