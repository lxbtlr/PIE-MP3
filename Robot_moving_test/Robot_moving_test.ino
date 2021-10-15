
#include <Adafruit_MotorShield.h>

int leftSense = A1;
int rightSense = A2;


// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *myMotor_L = AFMS.getMotor(1);
// You can also make another motor on port M2
Adafruit_DCMotor *myMotor_R = AFMS.getMotor(2);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps

  pinMode(leftSense, INPUT);
  pinMode(rightSense, INPUT);
  
  if (!AFMS.begin()) {         // create with the default frequency 1.6KHz
  // if (!AFMS.begin(1000)) {  // OR with a different frequency, say 1KHz
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }
  Serial.println("Motor Shield found.");

  // Set the speed to start, from 0 (off) to 255 (max speed)
  myMotor_R->setSpeed(150);
  myMotor_R->run(FORWARD);
  myMotor_L->setSpeed(150);
  myMotor_L->run(FORWARD);
  // turn on motor
  myMotor_R->run(RELEASE);
  myMotor_L->run(RELEASE);
}

void loop() {
  myMotor_R->setSpeed(50);
  myMotor_R->run(FORWARD);
  myMotor_L->setSpeed(50);
  myMotor_L->run(FORWARD);
  delay(1000);
  myMotor_R->setSpeed(100);
  myMotor_R->run(FORWARD);
  myMotor_L->setSpeed(100);
  myMotor_L->run(FORWARD);
  
  
  delay(1000);
}
