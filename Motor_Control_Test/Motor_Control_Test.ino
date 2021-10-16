#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <PID_v1.h> // Brett Beauregard PID library 
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotor_R = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor_L = AFMS.getMotor(4);
int Sense_0 = A0; //inicilizes sensors
int Sense_1 = A1;
int Sense_2 = A2;
int Sense_3 = A3;

int speed_L = 0;
int speed_R = 0;
int i = 0;
int t = 0;
int diff;

double Setpoint, Input, Output; //variables that are critical for PID control
//Specify the links and initial tuning parameters
double Kp=.5, Ki=0, Kd=0;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup() {
  long baudRate = 115200;       // NOTE1: The baudRate for sending & receiving programs must match
  Serial.begin(baudRate);     // NOTE2: Set the baudRate to 115200 for faster communication  
  AFMS.begin();
  
  pinMode(Sense_0, INPUT);
  pinMode(Sense_1, INPUT);
  pinMode(Sense_2, INPUT);
  pinMode(Sense_3, INPUT);
 
  //initialize the variables we're linked to
  Setpoint = 60;//should be the middle of the sensor range
  //turn the PID on
  myPID.SetMode(AUTOMATIC);//from PID library
  // put your setup code here, to run once:

}

void loop() {
  //PID implemetation code:
  int go_fast; //need for function call
  Input = sens_read();//calls the fuction sens_read and sets Imput to be the error
  Serial.print("input");
  Serial.print(Input);
  Serial.println();
  myPID.Compute(); //calls the PID fuction and executes
  Serial.print("output");
  Serial.print(Output);
  Serial.println();
  go_fast = motor_run(Output); //calls the funtion mot_run with the output from the PID.  Effectivly changes the motor speed
}

float sens_read(){
  //reads the 4 sensors and returns an angle at which the line is currently detected
  int Sense_A = analogRead(Sense_0);
  int Sense_B = analogRead(Sense_1);
  int Sense_C = analogRead(Sense_2);
  int Sense_D = analogRead(Sense_3);
 
  Sense_A = sq(Sense_A/100);
  Sense_B = sq(Sense_B/100);
  Sense_C = sq(Sense_C/100);
  Sense_D = sq(Sense_D/100);
 
//  Serial.print(Sense_A);
//  Serial.print("  ");
//  Serial.print(Sense_B);
//  Serial.print("   ");
//  Serial.print(Sense_C);
//  Serial.print("  ");
//  Serial.print(Sense_D);
//  Serial.println();
  
  int sense = 0;
  int threshold = 50;
  
  if (Sense_A > threshold){
    sense = 0;  
    }
    else if (Sense_B > threshold){
    sense = 20;
    }
    else if (Sense_C > threshold){
    sense = 40;
    }
    else if (Sense_D > threshold){
    sense = 60;
    }
    else{
      sense = 25; //will probably come back to bite us
    }
  
//  Serial.print(sense);
//  Serial.println();
  
//  Serial.print("ang:  ");
//  Serial.print(ang);
//  Serial.println();
  return sense;
}

int motor_run(int Output){
  //makes the motors run with different speeds depending on the output from the PID
  diff = Output - 30;
  Serial.print("diff:  "); 
  Serial.print(diff);
  Serial.println();
  speed_L = 40 - diff; //inicial motor speed in straigt line can change
  speed_R = 40 + diff; //inicial motor speed in straigt line can change
  myMotor_L->setSpeed(speed_L);
  myMotor_R->setSpeed(speed_R);
  Serial.print("speed_L");
  Serial.println(speed_L);
  Serial.print("speed_R");
  Serial.println(speed_R);
  myMotor_L->run(FORWARD);
  myMotor_R->run(FORWARD);
}
