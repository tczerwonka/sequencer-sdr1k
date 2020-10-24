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

int rf_relay_selected = 0;
int rf_secondary_relay_selected = 0;
int pwr_relay_selected = 0;

int debug = 0;

void setup() {

  //i2c specific stuff
  //Wire.begin(0x26);       //0x4C - 8 bit, 0x26 i2c 8 bit
  //Wire.onReceive(receiveEvent);


  //LCD stuff
  lcd.begin(16, 2);
  lcd.print("Sequencer V0.1");


  //SDR-1000-specific pins
  //pinMode(CONTROL1, INPUT_PULLUP);
  //pinMode(CONTROL2, INPUT_PULLUP);
  //pinMode(CONTROL3, INPUT_PULLUP);
  //pinMode(CONTROL4, INPUT_PULLUP);
  //pinMode(CONTROL5, INPUT_PULLUP);
  //pinMode(CONTROL6, INPUT_PULLUP);
  //pinMode(PTT_ACTIVE, INPUT_PULLUP);

  pinMode(PTT_MIC, INPUT_PULLUP);

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

  pinMode(RF1A, OUTPUT);
  pinMode(RF2A, OUTPUT);
  pinMode(RF3A, OUTPUT);
  pinMode(RF4A, OUTPUT);
  pinMode(RF5A, OUTPUT);
  pinMode(RF6A, OUTPUT);
  pinMode(RF7A, OUTPUT);
  pinMode(RF8A, OUTPUT);

  pinMode(DC12RY1, OUTPUT);
  pinMode(DC12RY2, OUTPUT);
  pinMode(DC12RY3, OUTPUT);
  pinMode(DC12RY4, OUTPUT);
  pinMode(DC12RY5, OUTPUT);
  pinMode(DC12RY6, OUTPUT);
  pinMode(DC12RY7, OUTPUT);
  pinMode(DC12RY8, OUTPUT);
  pinMode(DC5RY1, OUTPUT);
  pinMode(DC5RY2, OUTPUT);
  
  //logic on this backwards
  digitalWrite(F2304MHZ, HIGH);

  Serial.begin(9600);

}


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void loop() {

  check_ptt();


  for (int i = 0; i < PCA9555_pins; i++) {
    bitWrite(PCA9555_0, i, digitalRead(PCA9555_pins_0[i]));
  }
  for (int i = 0; i < PCA9555_pins; i++) {
    bitWrite(PCA9555_1, i, digitalRead(PCA9555_pins_1[i]));
  }

  if (debug) {
    Serial.print("PCA9555_0: ");
    Serial.print(PCA9555_0);

    Serial.print(" PCA9555_1: ");
    Serial.println(PCA9555_1);
    Serial.println();
  }


  //low bits
  if (PCA9555_1 == 0) {

    //UCB 2
    if (PCA9555_0 == 0) {
      if (frequency != 50) {
        frequency = 50;
        lcd.setCursor(0, 0);
        lcd.clear();
        lcd.print("HF-PASSTHRU");
        transvert_enable(0);
        select_rf(0);
        select_rf_secondary(0);
      } //if freq
    } // if HF

    //144MHz -- select RF1A direct out to separate transverter
    //realized that my 222 and 144 transverter have separate inputs
    //not worth modifying a working transverter so the RF1A and RF2A become
    //a split RX/TX for 222 as I can do 144 either with the onboard 144
    //transverter or with my FT847 or add some relays in the future
    //Also -- losing 3456MHz so forget about that band...
    //UCB 3
    if (PCA9555_0 == 8) {
      if (frequency != 144) {
        frequency = 144;
        lcd.setCursor(0, 0);
        lcd.clear();
        lcd.print("2M");
        transvert_enable(1);
        select_rf(RF8A);
        select_rf_secondary(0);
      } //if freq
    } // if 144

    //222MHz -- select RF2A direct out to separate transverter
    //UCB 4
    if (PCA9555_0 == 16) {
      if (frequency != 222) {
        frequency = 222;
        lcd.setCursor(0, 0);
        lcd.clear();
        lcd.print("222");
        transvert_enable(1);
        select_rf(RF1A);
        select_rf_secondary(0);
      } // if freq
    } // if 222

    //432MHz -- select RF4A direct to the internal transverter
    //UCB 5
    if (PCA9555_0 == 32) {
      if (frequency != 432) {
        frequency = 432;
        lcd.setCursor(0, 0);
        lcd.clear();
        lcd.print("432");
        transvert_enable(1);
        select_rf(RF4A);
        select_rf_secondary(0);
      } // if freq
    } // if 432

    //902MHz -- select RF3 -- internal 144MHz transverter
    //          select RF5 -- 902 output
    //UCB 6
    if (PCA9555_0 == 64) {
      if (frequency != 902) {
        frequency = 902;
        lcd.setCursor(0, 0);
        lcd.clear();
        lcd.print("902");
        transvert_enable(1);
        //RF4A is the internal 144MHz transverter
        select_rf(RF3A);
        select_rf_secondary(RF5A);
      } // if freq
    } // if 902

    //1296MHz -- select RF4 -- internal 144MHz transverter
    //UCB 7
    if (PCA9555_0 == 128) {
      if (frequency != 1296) {
        frequency = 1296;
        lcd.setCursor(0, 0);
        lcd.clear();
        lcd.print("1296");
        transvert_enable(1);
        //RF4A is the internal 144MHz transverter
        select_rf(RF3A);
        select_rf_secondary(RF6A);
      } // if freq
    } // if 1296

  }

  if (PCA9555_0 == 0) {

    //2304MHz -- select RF4 internatl 144MHz
    //UCB 8
    if (PCA9555_1 == 1) {
      if (frequency != 2304) {
        frequency = 2304;
        lcd.setCursor(0, 0);
        lcd.clear();
        lcd.print("2304");
        transvert_enable(1);
        //RF4A is the internal 144MHz transverter
        select_rf(RF4A);
        select_rf_secondary(RF7A);
      } // if freq
    } // if 2304

    //3456MHz -- select RF4 internatl 144MHz
    //UCB 9
    if (PCA9555_1 == 2) {
      if (frequency != 3456) {
        frequency = 3456;
        lcd.setCursor(0, 0);
        lcd.clear();
        lcd.print("3456");
        transvert_enable(1);
        //RF4A is the internal 144MHz transverter
        select_rf(RF4A);
        select_rf_secondary(RF8A);
      } // if freq
    } // if 3456

  } //if PCA9555_0 == 0
}


////////////////////////////////////////////////////////////////////////////////
// select_tx
//    select a transmit power relay -- 0 turns them all off
////////////////////////////////////////////////////////////////////////////////
void select_tx(int relay) {
  digitalWrite(pwr_relay_selected, LOW);
  if (relay == 0) {
    //50MHz -- turn the last selected relay off
    digitalWrite(pwr_relay_selected, LOW);
  } else {
    digitalWrite(relay, HIGH);
  }
  pwr_relay_selected = relay;
}



////////////////////////////////////////////////////////////////////////////////
// select_rf
//  select an RF relay -- 0 turns them all off
////////////////////////////////////////////////////////////////////////////////
void select_rf(int relay) {
  digitalWrite(rf_relay_selected, LOW);
  if (relay == 0) {
    //50MHz -- turn the last selected relay off
    digitalWrite(rf_relay_selected, LOW);
  } else {
    digitalWrite(relay, HIGH);
  }
  rf_relay_selected = relay;
}



////////////////////////////////////////////////////////////////////////////////
// check_ptt
//  check to see if PTT is enabled -- then key the pad and the transverter
////////////////////////////////////////////////////////////////////////////////
void check_ptt() {
  if (digitalRead(PTT_MIC) == LOW) {
    digitalWrite(PTT_MAIN, HIGH);
    delay(100);
    if (frequency == 144) {
      select_tx(F144MHZ);
    }
    if (frequency == 222) {
      select_rf(RF2A);
      select_tx(F222MHZ);
    }
    if (frequency == 432) {
      select_tx(F432MHZ);
    }
    if (frequency == 902) {
      select_tx(F902MHZ);
    }
    if (frequency == 1296) {
      select_tx(F1296MHZ);
    }
    if (frequency == 2304) {
      select_tx(F2304MHZ);
    }
    delay(50);
    digitalWrite(SDR_PTT_OUT, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("TX");
    
  } else {
    lcd.setCursor(0, 1);
    lcd.print("RX");
    digitalWrite(SDR_PTT_OUT, LOW);
    delay(50);
    digitalWrite(PTT_MAIN, LOW);
    select_tx(0);
    
    //if 222, select the RX relay
    if (frequency == 222) {
      select_rf(RF1A);
    }
    
  } //else
}


////////////////////////////////////////////////////////////////////////////////
// select_rf_secondary
//  These are the secondary relays fed by the 144mhz intermediate transverter
//  select an RF relay -- 0 turns them all off
////////////////////////////////////////////////////////////////////////////////
void select_rf_secondary(int relay) {
  digitalWrite(rf_secondary_relay_selected, LOW);
  if (relay == 0) {
    //50MHz -- turn the last selected relay off
    digitalWrite(rf_secondary_relay_selected, LOW);
  } else {
    digitalWrite(relay, HIGH);
  }
  rf_secondary_relay_selected = relay;
}



////////////////////////////////////////////////////////////////////////////////
// transvert_enable
//    enable the transverter -- off for HF, on for everything else
////////////////////////////////////////////////////////////////////////////////
void transvert_enable(int enable) {
  if (enable == 1) {
    digitalWrite(XV_EN, HIGH);
    lcd.setCursor(10, 1);
    lcd.print("XV_EN ");
  } else {
    lcd.setCursor(10, 1);
    lcd.print("XV_OFF");
    digitalWrite(XV_EN, LOW);
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
