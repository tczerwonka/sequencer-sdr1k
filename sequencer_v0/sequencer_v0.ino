// SDR1000 sequencer


#include "pindefs.h"

void setup() {
  // put your setup code here, to run once:
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
