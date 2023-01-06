long duration;
long distance;
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  Serial.begin(9600);
  pinMode(7,INPUT);
  pinMode(8,OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
    lcd.begin();
    lcd.backlight();
}

void loop()
{
  digitalWrite(8,LOW);
  delayMicroseconds(2);
  digitalWrite(8,HIGH);
  delayMicroseconds(10);
  digitalWrite(8,LOW);

  duration = pulseIn(7,HIGH);

  distance = duration/58.2;

  Serial.println(distance);

  delay(50);

   lcd.setCursor(0,0);
   lcd.print("Distance =");
   lcd.setCursor(12,0);
   lcd.print(distance);
   delay(1000);
   lcd.clear();
 //  lcd.setCursor(0,1);
  // lcd.print("M 7405290407");





}
