#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3);

int State = 0;

void setup()
{
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(7, INPUT_PULLUP);
}

void loop() 
{
  int SWState = digitalRead(7);
  
  if ( SWState == LOW)
  {
    digitalWrite (4, HIGH);
  }
   
  else if ( SWState == HIGH && State == 0)
  {
    digitalWrite (4, LOW);
  }
  if ( BTSerial.available())
  {
    Relay(BTSerial.read());
  }

}

void Relay(char BTState)
{
  if ( BTState == '1')
  {
    digitalWrite (4, HIGH);
    BTSerial.println("ON");
    State = 1;
  }
  
  else if ( BTState == '0')
  {
    digitalWrite (4, LOW);
    BTSerial.println("OFF");
    State = 0;
  }
}
