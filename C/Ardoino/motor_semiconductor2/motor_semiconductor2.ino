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
  if(analogRead(0) > 1023/2)
  { 
    int motorSpeed = (analogRead(0)-(1023/2))/2.0;
    setMotor(motorSpeed,CW);
  }
  else if(analogRead(0) < 1023/2)
  {
    int motorSpeed = ((1023/2)-analogRead(0))/2.0;
    setMotor(motorSpeed,CCW);
  }
}

void setMotor(int motorSpeed, boolean motorDir)
{
  analogWrite(9,motorSpeed);
  digitalWrite(8,motorDir);
  digitalWrite(7,!motorDir);
}
