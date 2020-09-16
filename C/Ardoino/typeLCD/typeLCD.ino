#include <LiquidCrystal.h>

LiquidCrystal lcd(3,4,5,6,7,8);
int time1 = 100, time2 = 2000, lcdCnt = 0, cnt = 0, line = 0;
char sentence[] = "This is an Arduino electronic display. Come out at least as much as you want to write. Isn't it amazing? It comes out one by one. hahahahahahahahahahahahaha. I've made. I won't tell you. :)";
//적고 싶은 문장 적어용~

void setup() {
  // set up the LCD's number of columns and rows:
  
  lcd.begin(16, 2);
  // Print a message to the LCD.
}

void loop()
{
  lcd.clear();
  while (cnt < sizeof(sentence)-1)
  {
    if (lcdCnt == 16 ) lcdCnt = 0;
    show();
    lineSwitching();
  }
    delay(time2);
    cnt = 0;
    lcdCnt = 0;
    line = 0;
}

void show ()
{
   lcd.setCursor(lcdCnt,line);
   lcd.print(sentence[cnt]);
   cnt++;
   lcdCnt++;
   delay (time1);
}

void lineSwitching ()
{
  if (cnt % 16 == 0 && line == 0) line = 1;
  else if (cnt % 16 == 0 && line == 1) 
  { 
    line = 0; 
    delay(time2);
    lcd.clear(); 
  }
}
