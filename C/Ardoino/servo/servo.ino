#include<Servo.h>

unsigned int potVal;
int angle;

Servo myServo;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(8,500,2300);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(0);
  angle = (potVal/1023.0) * 180.0;
  myServo.write(angle);

  Serial.print("angle : ");
  Serial.println(angle);
  delay(15);
}
