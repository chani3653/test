#include <SoftwareSerial.h>

#define STOP 0
#define SPEED1 80
#define SPEED2 100
#define SPEED3 255
SoftwareSerial BTSerial(2,3);

void setup() {
  // put your setup code here, to run once:
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(9,OUTPUT);
  BTSerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(BTSerial.available())
  {
    ledON(BTSerial.read());
  }
}
void ledON(char btdata)
{
  if(btdata == '0')
  {
    analogWrite(9,STOP);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  }
  else if(btdata == '1')
  {
    analogWrite(9,SPEED1);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  }
  else if(btdata == '2')
  {
    analogWrite(9,SPEED2);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  }
  else if(btdata == '3')
  {
    analogWrite(9,SPEED3);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
  }
}
