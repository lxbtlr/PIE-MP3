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
  
//  nmax = max(A,B);
//  nmax = max(nmax,C);
//  nmax = max(nmax,D);
//  Serial.println(nmax);



//  Serial.print("A: ");
//  if (A >= 800) {
//    Serial.print("1 ");
//  } else {
//    Serial.print("0 ");
//  }
//  Serial.print("B: ");
//  if (B >= 800) {
//    Serial.print("1 ");
//  } else {
//    Serial.print("0 ");
//  }
//  Serial.print("C: ");
//  if (C >= 800) {
//    Serial.print("1 ");
//  } else {
//    Serial.print("0 ");
//  }
//  Serial.print("D: ");
//  if (D >= 800) {
//    Serial.println("1");
//  } else {
//    Serial.println("0");
//  }
}
