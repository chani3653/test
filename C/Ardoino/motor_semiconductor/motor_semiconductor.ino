#define CW HIGH
#define CCW LOW

void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int motorSpeed = analogRead(0)/4.0;
  setMotor(motorSpeed,CW);
}

void setMotor(int motorSpeed, boolean motorDir)
{
  analogWrite(9,motorSpeed);
  digitalWrite(8,motorDir);
  digitalWrite(7,!motorDir);
}
