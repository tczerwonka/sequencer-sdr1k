// SDR sequencer for microwave transverters
// Originally targeted to the SDR-1000 and now adding FlexWire support




#include "pindefs.h"
#include "translation.h"
#include <Wire.h>
#include <LiquidCrystal.h>

//SainSmart LCD Keypad Shield v1.0
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

uint8_t PCA9555_0;
uint8_t PCA9555_1;

int frequency;
char line0[17];
char line1[17];

void setup() {

  //i2c specific stuff
  Wire.begin(0x26);       //0x4C - 8 bit, 0x26 i2c 8 bit
  Wire.onReceive(receiveEvent);


  //LCD stuff
  lcd.begin(16, 2);
  lcd.print("Sequencer V0");


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

}



void loop() {

  for (int i = 0; i < PCA9555_pins; i++) {
    bitWrite(PCA9555_0, i, digitalRead(PCA9555_pins_0[i]));
  }
  for (int i = 0; i < PCA9555_pins; i++) {
    bitWrite(PCA9555_1, i, digitalRead(PCA9555_pins_1[i]));
  }

  //Serial.print("PCA9555_0: ");
  //Serial.print(PCA9555_0);

  //Serial.print(" PCA9555_1: ");
  //Serial.println(PCA9555_1);
  //Serial.println();


  //low bits
  if (PCA9555_1 == 0) {

    //UCB 2
    if (PCA9555_0 == 0) {
      if (frequency != 50) {
        frequency = 50;
        lcd.setCursor(0, 0);
        lcd.clear();
        lcd.print("HF-PASSTHRU");
      } //if freq
    } // if HF

    //UCB 3
    if (PCA9555_0 == 4) {
      if (frequency != 144) {
        frequency = 144;
        lcd.setCursor(0, 0);
        lcd.clear();
        lcd.print("2M");
      } //if freq
    } // if 144

    //UCB 4
    if (PCA9555_0 == 16) {
      if (frequency != 222) {
        frequency = 222;
        lcd.setCursor(0, 0);
        lcd.clear();
        lcd.print("222");
      } // if freq
    } // if 222

    //UCB 5
    if (PCA9555_0 == 32) {
      if (frequency != 432) {
        frequency = 432;
        lcd.setCursor(0, 0);
        lcd.clear();
        lcd.print("432");
      } // if freq
    } // if 432

    //UCB 6
    if (PCA9555_0 == 64) {
      if (frequency != 902) {
        frequency = 902;
        lcd.setCursor(0, 0);
        lcd.clear();
        lcd.print("902");
      } // if freq
    } // if 902

    //UCB 7
    if (PCA9555_0 == 128) {
      if (frequency != 1296) {
        frequency = 1296;
        lcd.setCursor(0, 0);
        lcd.clear();
        lcd.print("1296");
      } // if freq
    } // if 1296
    
  }

  if (PCA9555_0 == 0) {  

    //UCB 8
    if (PCA9555_1 == 1) {
      if (frequency != 2304) {
        frequency = 2304;
        lcd.setCursor(0, 0);
        lcd.clear();
        lcd.print("2304");
      } // if freq
    } // if 2304

    //UCB 9
    if (PCA9555_1 == 2) {
      if (frequency != 3456) {
        frequency = 3456;
        lcd.setCursor(0, 0);
        lcd.clear();
        lcd.print("3456");
      } // if freq
    } // if 3456
    
  }




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
