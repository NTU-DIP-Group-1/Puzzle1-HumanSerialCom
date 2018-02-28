#include <SoftwareSerial.h>

//Pins
int pin_null  = 5;
int pin_serial = 6;
int pin_button = 10;


//Definitions
String code = "1234.";
SoftwareSerial serial_pin(pin_null, pin_serial); //Rx, Tx. (RX not used)

//Setup
void setup() 
{
  Serial.begin(4800);
  serial_pin.begin(9600);
  pinMode(pin_button, INPUT);
}

//Main loop
void loop() 
{
  //if button is pressed
  if (digitalRead(pin_button))
  { 
    Serial.print("Button Pressed");
    char buf[10];
    code.toCharArray(buf, 10);

    //while button is down, code is sent every 500ms
    while (digitalRead(pin_button))
    {
      serial_pin.write(buf);
      delay(500);
    }
  }
}
