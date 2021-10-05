int leftMostSense = A0;
int leftSense = A1;
int rightSense = A2;
int rightMostSense = A3;

/*
take in the sensor values - denoise them

*/
void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  pinMode(leftMostSense, INPUT);
  pinMode(leftSense, INPUT);
  pinMode(rightSense, INPUT);
  pinMode(rightMostSense, INPUT);
}

void loop() {
  long sensorValue =0;
  // put your main code here, to run repeatedly:
  for(int i = 0; i<100;i++){
    sensorValue += analogRead(rightMostSense);
    }
  sensorValue = sensorValue/100;
  Serial.println(sensorValue);
}
