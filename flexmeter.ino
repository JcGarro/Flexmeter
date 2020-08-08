#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Configuration of the LCD
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

//Initialization of Variables
float voltage= 0.0;
float length = 0.0;
float conversion = 0.0;
int potentio = A2; //Set the port of the potentiometer input in Analog2
float len = 19.7; //The initial length of the device
float lenm = 11.5; //The maximum change that can be made or the length of moving part


void setup() {
//Intialization of the LCD Screen
Serial.begin(9600);

lcd.begin(16,2);
lcd.setCursor(1,0);
lcd.print("Circumference"); //This lcd will display "Circumference"
}

void loop() {
//The main expression for the prototype
voltage= analogRead(potentio);
conversion=(lenm/1023)+len;
length =  voltage*conversion; 

//As the code run this will display the converted value as 'Length+"cm"' 
lcd.setCursor(4,1);
lcd.print(length, 4);
lcd.print(" ");

lcd.setCursor(11,1);
lcd.print("cm");

//Show the value in the com port to verify if the LCD is displaying the expected value
Serial.println(length, 4);

delay(300); //Make delay before make another loop

}

