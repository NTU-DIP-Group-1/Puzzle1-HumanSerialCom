#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <utility/Adafruit_MCP23017.h>

//Pins
const int pin_null= 10;
const int pin_serial= 8;
const int pin_LCD_1 = A1; //auto init
const int pin_LCD_2 = A2; //auto init 

//vars
bool no_recieve_flag = true;

//Definitions
SoftwareSerial serial_pin(pin_serial, pin_null); //Rx, Tx (Tx not used)
Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

//Setup
void setup() 
{
  Serial.begin(4800);
  serial_pin.begin(9600);
  lcd.begin(16, 2);
  lcd.setBacklight(0x7);
  lcd.print("Wait for pin");
}

//Main loop
void loop() 
{
  //first instance of signal recieved
  if (serial_pin.available())
  {
    lcd.clear();
    lcd.print("Recieved: ");
    //loop to print each char in the pipeline
    while (serial_pin.available())
    {
      char input = serial_pin.read();
      lcd.print(input);
      Serial.write(input);
      if (input == '.')
      {
        break;
      }
    }
    //display the recieved pin for half a second
    delay(1000);
    //clear screen
    lcd.clear();
  }
  else
  {
    lcd.clear();
    lcd.print("Wait for pin");
    delay(500);
  }
}

void scrollprint(String text, int txtlength)
{
  lcd.setCursor(0, 0);
  lcd.print(text);
   for (int positionCounter = 0; positionCounter < txtlength; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(150);
  }
}




