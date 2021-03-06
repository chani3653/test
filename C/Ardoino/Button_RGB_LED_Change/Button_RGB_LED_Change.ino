#include <EEPROM.h>
int count=0;
int swCount=0;
int swBuf=0;
int incomingByte=0;

byte fndData[10][8] = {
  {1, 1, 1, 1, 1, 0 ,1, 0},//0
  {0, 1, 1, 0, 0, 0, 0, 0},//1
  {1, 1, 0, 1, 1, 1, 0, 0},//2
  {1, 1, 1, 1, 0, 1, 0, 0},//3
  {0, 1, 1, 0, 0, 1, 1, 0},//4
  {1, 0, 1, 1, 0, 1, 1, 0},//5
  {1, 0, 1, 1, 1, 1 ,1, 0},//6
  {1, 1, 1, 0, 0, 0 ,0, 0},//7
  {1, 1, 1, 1, 1, 1 ,1, 0},//8
  {1, 1, 1, 1, 0, 1 ,1, 0}//9
};
void displayNum(byte num)
{
  for(int i =1;i<9;i++)
  {
    digitalWrite(i,fndData[num][i-1]);
  }
}
void setup() {
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT); 
    for(int i=0;i<9;i++)
  {
    pinMode(i,OUTPUT);
  }
  Serial.begin(9600);
  swCount = EEPROM.read(0);
  count = EEPROM.read(1);
}
unsigned char color[10][3]=
{
  {255,0,0},
  {0,255,0},
  {0,0,255},
  {255,255,0},
  {255,0,255},
  {0,255,255},
  {255,255,100},
  {255,100,255},
  {100,100,255},
  {100,255,255}
  };
void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()>0)
 {
    incomingByte=Serial.read();
    Serial.println(incomingByte);
    if(incomingByte=='1')
    {
       swCount=0;
       count=1;
      }
    else if(incomingByte=='2')
    {
       swCount=1;
       count=2;
      }
    else if(incomingByte=='3')
    {
       swCount=2;
       count=3;
      }
      else if(incomingByte=='4')
    {
       swCount=3;
       count=4;
      }
      else if(incomingByte=='5')
    {
       swCount=4;
       count=5;
      }
      else if(incomingByte=='6')
    {
       swCount=5;
       count=6;
      }
     else if(incomingByte=='7')
    {
       swCount=6;
       count=7;
      }
      else if(incomingByte=='8')
    {
       swCount=7;
       count=8;
      }
      else if(incomingByte=='9')
    {
       swCount=8;
       count=9;
      }
      else if(incomingByte=='0')
    {
       swCount=9;
       count=0;
      }
        displayNum(count);
        setRgbColor(color[swCount][0],color[swCount][1],color[swCount][2]);
        EEPROM.write(0,swCount);
        EEPROM.write(1,count);
  }
 }
void setRgbColor(char r,char g,char b)
{
  analogWrite(11,255-r);
  analogWrite(10,255-g);
  analogWrite(9,255-b);
 }
