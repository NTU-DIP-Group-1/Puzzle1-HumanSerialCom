#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

//Pins
const int pin_null= 10;
const int pin_serial= 8;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; //LCD pins

//Definitions
SoftwareSerial serial_pin(pin_serial, pin_null); //Rx, Tx (Tx not used)
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //LCD interface pins

//Setup
void setup() 
{
  Serial.begin(4800);
  serial_pin.begin(9600);
  lcd.begin(16, 2);
}

//Main loop
void loop() 
{
  if (serial_pin.available())
  {
    String input_string = serial_URL.read();
    Serial.write(input_string);
    lcd.print(input_string);
  }
}




