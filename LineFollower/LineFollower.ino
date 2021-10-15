int leftMostSense = A0;
int leftSense = A1;
int rightSense = A2;
int rightMostSense = A3;
int nmax = 0;

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
  int A = sq(analogRead(leftMostSense)/100);
  int B = sq(analogRead(leftSense)/100);
  int C = sq(analogRead(rightSense)/100);
  int D = sq(analogRead(rightMostSense)/100);
  Serial.print(A);
  Serial.print(" ");
  Serial.print(B);
  Serial.print(" ");
  Serial.print(C);
  Serial.print(" ");
  Serial.println(D);
  
}
