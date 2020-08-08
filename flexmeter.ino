#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
float voltage= 0.0;
float length = 0.0;

//Set the port of the input in Analog2
int pot = A2;

void setup() {
//Intialization of the LCD Screen
Serial.begin(9600);
//This lcd will display "Circumference"
lcd.begin(16,2);
lcd.setCursor(1,0);
lcd.print("Circumference");
}

void loop() {
//The main expression for the prototype
voltage= analogRead(pot)
length =  voltage*(11.5/1023)+19.7; 

//As the code run this will display the converted value as "Length cm" 
lcd.setCursor(4,1);
lcd.print(length, 4);

lcd.print(" ");
lcd.setCursor(11,1);

lcd.print("cm");
Serial.println(length, 4);
//Make delay before make another loop
delay(300);

}

