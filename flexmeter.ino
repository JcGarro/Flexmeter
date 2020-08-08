#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
float voltage= 0.0;
int pot = A2;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lcd.begin(16,2);
lcd.setCursor(1,0);
lcd.print("Circumference");
}

void loop() {
  // put your main code here, to run repeatedly:
voltage =  analogRead(pot)*(11.5/1023)+19.7; //
lcd.setCursor(4,1);
lcd.print(voltage, 4);
lcd.print(" ");
lcd.setCursor(11,1);
lcd.print("cm");
Serial.println(voltage, 4);
delay(300);

}

