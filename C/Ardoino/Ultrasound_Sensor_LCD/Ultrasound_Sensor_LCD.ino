#include<LiquidCrystal.h>

LiquidCrystal lcd(12,11,2,3,4,5);

long duration,Cm,In;


void setup() {
  // put your setup code here, to run once:
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(9,INPUT);
  digitalWrite(8,LOW);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(8,HIGH);
  delayMicroseconds(8);
  digitalWrite(8,LOW);
  duration = pulseIn(9,HIGH);

  Cm = duration / 29.1 / 2;
  In = duration / 74 / 2;

if(Cm < 50)
{
  beep(Cm*50);
}
  lcd.setCursor(0,1);
  lcd.print("Cm = ");
  lcd.print(Cm);
  lcd.setCursor(1,1);
  lcd.print("  In = ");
  lcd.println(In);
}


void beep(unsigned long delayms)
{
  analogWrite(10,150);
  delay(delayms);
  analogWrite(10,0);
  delay(delayms);
}
