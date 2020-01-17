#include<EEPROM.h>

int count = 1;
int redpin = 6;
int greenpin = 5;
int bluepin = 3;

byte fndData[10][7] = {
  {0,0,0,0,0,0,1},
  {1,0,0,1,1,1,1},
  {0,0,1,0,0,1,0},
  {0,0,0,0,1,1,0},
  {1,0,0,1,1,0,0},
  {0,1,0,0,1,0,0},
  {0,1,0,0,0,0,0},
  {0,0,0,1,1,1,1},
  {0,0,0,0,0,0,0},
  {0,0,0,0,1,0,0}
};

 unsigned char color[5][3] = {
      {0,0,255},
      {0,153,255},
      {153,0,255},
      {204,0,33},
      {255,0,0}
    };

void displayNum(byte num)
{
  for(int i=7;i<=13;i++)
  {
    digitalWrite(i,fndData[num][i-7]);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  count = EEPROM.read(0);
  if(count > 5){
      count = 1;
    }
    pinMode(4,OUTPUT);
  for(int i=7;i<=13;i++)
  {
    pinMode(i,OUTPUT);
  }
  pinMode(2,INPUT_PULLUP);
  attachInterrupt(0,interrupt,CHANGE);
  pinMode(redpin,OUTPUT);
  pinMode(greenpin,OUTPUT);
  pinMode(bluepin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int temp = Serial.read();
  int temp2 = Serial.read();
  delay(10);
  if(temp < 58 && temp > 47)
  {
    count = checkSerial(temp-48,temp2-48);
  }
  displayNum(count);
  setRgbColor(color[count-1][0],color[count-1][1],color[count-1][2]);
  EEPROM.write(0,count);
}

void interrupt()
{
  count++;
  if(count > 5){
      count = 1;
    }
}

void setRgbColor(char r, char g, char b)
{
  analogWrite(redpin,255-r);
  analogWrite(greenpin,255-g);
  analogWrite(bluepin,255-b); 
}

int checkSerial(int n, int n2)
{
  if(n==1 && n2 <=0)
    return 1;
  else if(n*10+n2 <=20)
    return 2;
  else if(n*10+n2 <=30)
    return 3;
  else if(n*10+n2 <=40)
    return 4;
  else if(n*10+n2 <=50)
    return 5;
    else
    return 5;
}
