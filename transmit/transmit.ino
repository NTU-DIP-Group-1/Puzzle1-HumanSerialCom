#include <SoftwareSerial.h>

//Pins
int pin_null  = 5;
int pin_serial = 7;
int pin_button = 2;


//Definitions
String code = "6824.";
SoftwareSerial serial_pin(pin_null, pin_serial); //Rx, Tx. (RX not used)

//Setup
void setup()
{
  Serial.begin(9600);
  serial_pin.begin(9600);
  pinMode(pin_button, INPUT_PULLUP);
}

//Main loop
void loop() 
{
  //if button is pressed
  if (digitalRead(pin_button))
  { 
    Serial.print("Button Pressed");
    Serial.print(digitalRead(pin_button));
    char buf[10];
    code.toCharArray(buf, 10);

    //while button is down, code is sent every second
    while (digitalRead(pin_button))
    {
      serial_pin.write(buf);
      Serial.print(buf);
      delay(1000);
      serial_pin.write(buf);
      Serial.print(buf);
      delay(1000);
      serial_pin.write(buf);
      Serial.print(buf);
      delay(1000);
    }
  }
}
