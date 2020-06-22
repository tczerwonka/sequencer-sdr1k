// SDR sequencer for microwave transverters
// Originally targeted to the SDR-1000 and now adding FlexWire support




#include "pindefs.h"
#include <Wire.h>
#include <LiquidCrystal.h>

//SainSmart LCD Keypad Shield v1.0
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);




void setup() {

  //i2c specific stuff
  Wire.begin(0x4c);       //0x4C is the xvtr interface
  Wire.onReceive(receiveEvent);
  

  //LCD stuff
  lcd.begin(16,2);
  lcd.print("hello world");

  //SDR-1000-specific pins
  pinMode(CONTROL1, INPUT_PULLUP);
  pinMode(CONTROL2, INPUT_PULLUP);
  pinMode(CONTROL3, INPUT_PULLUP);
  pinMode(CONTROL4, INPUT_PULLUP);
  pinMode(CONTROL5, INPUT_PULLUP);
  pinMode(CONTROL6, INPUT_PULLUP);
  pinMode(PTT_ACTIVE, INPUT_PULLUP);
  
  Serial.begin(9600);
}



void loop() {
  int val = 0;
  
  val = digitalRead(CONTROL1);
  Serial.print("control1:");
  Serial.print(val);
  Serial.print("\n");
  
  val = digitalRead(CONTROL2);
  Serial.print("control2:");
  Serial.print(val);
  Serial.print("\n");
  
  val = digitalRead(CONTROL3);
  Serial.print("control3:");
  Serial.print(val);
  Serial.print("\n");
  
  val = digitalRead(CONTROL4);
  Serial.print("control4:");
  Serial.print(val);
  Serial.print("\n");
  
  val = digitalRead(CONTROL5);
  Serial.print("control5:");
  Serial.print(val);
  Serial.print("\n");
  
  val = digitalRead(CONTROL6);
  Serial.print("control6:");
  Serial.print(val);
  Serial.print("\n");
  

  val = digitalRead(PTT_ACTIVE);
  Serial.print("PTT_ACTIVE:");
  Serial.print(val);
  Serial.print("\n");
   
  delay(1000);

}


// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  while(1 < Wire.available()) // loop through all but the last
  {
    char c = Wire.read(); // receive byte as a character
    lcd.print(c);         // print the character
  }
  int x = Wire.read();    // receive byte as an integer
  lcd.println(x);         // print the integer
}
