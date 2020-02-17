#include<Stepper.h>

int in1Pin = 12;
int in2Pin = 11;
int in3Pin = 10;
int in4Pin = 9;

Stepper motor(32,in1Pin,in2Pin,in3Pin,in4Pin);

 
 void setup() {
  Serial.begin(9600);
  motor.setSpeed(600);
}

void serialEvent()
{
  int angle = Serial.parseInt();
  motor.step(angleToStep(angle));
}

int angleToStep(int angle)
{
  return (2048.0*angle)/360.0;
}

void loop() {
  
}
