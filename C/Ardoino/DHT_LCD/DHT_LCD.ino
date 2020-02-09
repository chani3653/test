#include<DHT.h>
#include<LiquidCrystal.h>
DHT dht;

LiquidCrystal lcd(12,11,2,3,4,5);

void setup() {
  Serial.begin(9600);
  dht.setup(2);
  lcd.begin(16,2);
}

void loop() {
  delay(dht.getMinimumSamplingPeriod());
  float temp = dht.getTemperature();
  float humidity = dht.getHumidity();
  lcd.setCursor(0,0)
  lcd.print("temp : ");
  lcd.print(temp,2);
  lcd.print(" C");
  lcd.setCursor(1,0)
  lcd.print("  humidity : ");
  lcd.print(humidity,2);
  lcd.print(" %");
}
