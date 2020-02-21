#include<LiquidCrystal.h>

LiquidCrystal lcd(12,11,2,3,4,5);

void setup() {
  lcd.begin(16,2);

}

void loop() 
{
    lcd.setCursor(0,0);
    lcd.print(" first sentence");
    delay(3000);
    lcd.clear();
    lcd.print(" second sentence");
    delay(3000);
    lcd.clear();
    lcd.print(" third sentence");
    delay(3000);
    lcd.clear();
    lcd.print(" go first");
    lcd.setCursor(1,0);
    lcd.print(" Sentence");
    delay(3000);
    lcd.clear();
}
