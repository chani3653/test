#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3);

int BTState = 0; 

void setup() 
{
  // put your setup code here, to run once:
  BTSerial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(7, INPUT_PULLUP);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  int HWState = digitalRead(7);
  if ( HWState == HIGH ) SWState('0');
  if ( HWState == LOW ) SWState('1');
  if ( HWState == HIGH && BTState == 0 ) SWState('0');
  if ( HWState == LOW && BTState == 1 ) SWState('1');
  if ( HWState == HIGH && BTState == 1 ) SWState('1');
  if ( HWState == LOW && BTState == 0 ) SWState('0');
  if ( BTSerial.available()) 
  {
    if ( BTSerial.read() == '1') BTState = 1;
    if ( BTSerial.read() == '0') BTState = 0;
    SWState ( BTSerial.read());
  }
}

void SWState(char State)
{
  if ( State == '1' )
  {
    digitalWrite ( 4, HIGH );
  }
  
  if ( State == '0' )
  {
    digitalWrite ( 4, LOW );
  }
}
