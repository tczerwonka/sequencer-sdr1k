// SDR sequencer for microwave transverters
// Originally targeted to the SDR-1000 and now adding FlexWire support




#include "pindefs.h"
#include "translation.h"
#include <Wire.h>
#include <LiquidCrystal.h>

//SainSmart LCD Keypad Shield v1.0
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);




void setup() {

  //i2c specific stuff
  Wire.begin(0x26);       //0x4C - 8 bit, 0x26 i2c 8 bit
  Wire.onReceive(receiveEvent);


  //LCD stuff
  lcd.begin(16, 2);
  lcd.print("hello world");

  //SDR-1000-specific pins
  pinMode(CONTROL1, INPUT_PULLUP);
  pinMode(CONTROL2, INPUT_PULLUP);
  pinMode(CONTROL3, INPUT_PULLUP);
  pinMode(CONTROL4, INPUT_PULLUP);
  pinMode(CONTROL5, INPUT_PULLUP);
  pinMode(CONTROL6, INPUT_PULLUP);
  pinMode(PTT_ACTIVE, INPUT_PULLUP);

  pinMode(IO0_0, INPUT);
  pinMode(IO0_1, INPUT);
  pinMode(IO0_2, INPUT);
  pinMode(IO0_3, INPUT);
  pinMode(IO0_4, INPUT);
  pinMode(IO0_5, INPUT);
  pinMode(IO0_6, INPUT);
  pinMode(IO0_7, INPUT);
  pinMode(IO1_0, INPUT);
  pinMode(IO1_1, INPUT);
  pinMode(IO1_2, INPUT);
  pinMode(IO1_3, INPUT);
  pinMode(IO1_4, INPUT);
  pinMode(IO1_5, INPUT);
  pinMode(IO1_6, INPUT);
  pinMode(IO1_7, INPUT);

  Serial.begin(9600);
    int val;

}



void loop() {

  int val;

	val = digitalRead(IO0_0);
	Serial.print(val);

    val = digitalRead(IO0_1);
  Serial.print(val);

    val = digitalRead(IO0_2);
  Serial.print(val);

    val = digitalRead(IO0_3);
  Serial.print(val);

    val = digitalRead(IO0_4);
  Serial.print(val);

    val = digitalRead(IO0_5);
  Serial.print(val);

      val = digitalRead(IO0_6);
  Serial.print(val);

    val = digitalRead(IO0_7);
  Serial.print(val);

  Serial.print(" ");

    val = digitalRead(IO1_0);
  Serial.print(val);

    val = digitalRead(IO1_1);
  Serial.print(val);

    val = digitalRead(IO1_2);
  Serial.print(val);

    val = digitalRead(IO1_3);
  Serial.print(val);

    val = digitalRead(IO1_4);
  Serial.print(val);

    val = digitalRead(IO1_5);
  Serial.print(val);

      val = digitalRead(IO1_6);
  Serial.print(val);

    val = digitalRead(IO1_7);
  Serial.print(val);

  Serial.println();

}


void sdr1k() {
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
  while (1 < Wire.available()) // loop through all but the last
  {
    char c = Wire.read(); // receive byte as a character
    lcd.print(c);         // print the character
    Serial.println(c);
  }
  int x = Wire.read();    // receive byte as an integer
  lcd.println(x);         // print the integer
  Serial.println(x);

}
