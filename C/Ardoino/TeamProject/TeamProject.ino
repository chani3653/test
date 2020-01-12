#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include <SoftReset.h>  
#include <MFRC522.h>
#include <EEPROM.h>
#include <DHT.h>
#include <SPI.h>

LiquidCrystal lcd(3, 4, 5, 6, 7, 8);
SoftwareSerial BTserial(A2, A3); //TX,RX
MFRC522 mfrc(10, 9);
DHT dht;

int powerState = 0;
int ErrCnt = 0;
int lockCnt = 0;
String pwString = "";

//RFID
//3.3V RST GND IRQ MISO MOSI SCK SD A
//      9           12   11  13  10

//LCD
//VSS VDD V0 RW     RS E  D4 D5 D6 D7 A K
// -   +  저 -      3  4  5  6  7  8  + -

void setup() 
{  
  lcd.begin(16, 2); //16열 2줄짜리 LCD임을 설정해줌.  
  BTserial.begin(9600);
  Serial.begin(9600);
  SPI.begin();
  mfrc.PCD_Init();  
  dht.setup(2);
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  lockCnt = EEPROM.read(0);
} 

void loop()
{
  if ( !mfrc.PICC_IsNewCardPresent() || !mfrc.PICC_ReadCardSerial()) 
  { 
    lcd.setCursor(0, 0);
    lcd.print("     Please");
    lcd.setCursor(0, 1);
    lcd.print("  Tap the CARD");
    while (ErrCnt >= 3 || lockCnt == 1)
    { 
      lockCnt = 1;
      EEPROM.write(0,lockCnt);
      if (BTserial.available())
      {
        char pw = (char)BTserial.read();
        pwString+=pw;
        delay(5);
        if (pwString.equals("1234")) 
        {
           Serial.println("Password Correct!");
           BTserial.println("Password Correct!");
           lockCnt = 0;
           EEPROM.write(0,lockCnt);
           soft_restart();
        }
      }
      lcd.setCursor(0,0);
      lcd.print(" Connect BT and");
      lcd.setCursor(0, 1);
      lcd.print(" Input Password");
    }
    lcd.display();
    if (powerState == 0) return;
  } 

  if(mfrc.uid.uidByte[0] == 237 && mfrc.uid.uidByte[1] == 32 && mfrc.uid.uidByte[2] == 178 && mfrc.uid.uidByte[3] == 94 && powerState ==0) 
  {
    //113 105 151 8 0 
      tone(A0,523,100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("     HELLO!!");
      lcd.setCursor(0, 1);
      lcd.print("  Turn ON PC!!");
      digitalWrite(A1,HIGH);
      delay(500);
      digitalWrite(A1,LOW);
      delay(5000);  
      lcd.clear();
      powerState = 1;
   }

   else {
    if (powerState == 1) return;
    ErrCnt++;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("     ERROR!");
    lcd.setCursor(0, 1);
    lcd.print("   COUNT : ");
    lcd.print(ErrCnt);
    delay(500);
    tone(A0,523,100);                
    delay(200);
    tone(A0,523,100);                
    delay(200);
    tone(A0,523,100);
    delay(500);
    lcd.clear();
  }  
  
  while (powerState == 1)
  {
      int temp = dht.getTemperature(), humi = dht.getHumidity();
      lcd.setCursor(0, 0);
      lcd.display();
      lcd.print("  SYSTEM STATE");
      lcd.setCursor(0,1);
      lcd.print(" T:");
      lcd.print(temp);
      lcd.print("C");
      lcd.print("    H:");
      lcd.print(humi);
      lcd.print("%");
      delay(1500);
      
      if( mfrc.PICC_IsNewCardPresent() && mfrc.PICC_ReadCardSerial() && mfrc.uid.uidByte[0] == 237 && mfrc.uid.uidByte[1] == 32 && mfrc.uid.uidByte[2] == 178 && mfrc.uid.uidByte[3] == 94) 
      {
        tone(A0,523,100);
        lcd.clear();
        lcd.print("     BYE BYE");
        lcd.setCursor(0, 1);
        lcd.print("Turn OFF the PC!");
        digitalWrite(A1,HIGH);
        delay(500);
        digitalWrite(A1,LOW);
        delay(3000);
        lcd.clear();
        delay(10000);
        soft_restart();
     }
  }
}
