#include<LiquidCrystal.h>
#include<math.h>

#define A 0.001129148
#define B 0.000234125
#define C 0.0000000876741
#define Vin 5.0
#define R2 10000.0

LiquidCrystal lcd(12,11,2,3,4,5);

void setup() {
  lcd.begin(16,2);
  lcd.print("Temperature");
}


double SteinharHart(double R)
{
  double logR = log(R);
  double logR3 = logR * logR * logR;
  return 1.0 / (A + B * logR + C * logR3);
}

void loop() {
  int adcData = analogRead(0);
  double Vout = (adcData*Vin) / 1023;
  double Rth = ((Vin * R2) / Vout) - R2;
  double T = SteinharHart(Rth) - 273.15;
  lcd.setCursor(0,1);
  lcd.print(T);
  
  delay(15);
}
