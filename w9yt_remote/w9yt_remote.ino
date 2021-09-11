////////////////////////////////////////////////////////////////////////////////
// W9YT sequencer
//  Control a generic 8-channel relay board for rotator switching, etc.
//  Pro Micro burn as Leonardo
////////////////////////////////////////////////////////////////////////////////


#include "pindefs.h"

void setup() {

  pinMode(RY1A, OUTPUT);
  pinMode(RY2A, OUTPUT);
  pinMode(RY3A, OUTPUT);
  pinMode(RY4A, OUTPUT);
  pinMode(RY5A, OUTPUT);
  pinMode(RY6A, OUTPUT);
  pinMode(RY7A, OUTPUT);
  pinMode(RY8A, OUTPUT);

  digitalWrite(RY1A, HIGH);
  digitalWrite(RY2A, HIGH);
  digitalWrite(RY3A, HIGH);
  digitalWrite(RY4A, HIGH);
  digitalWrite(RY5A, HIGH);
  digitalWrite(RY6A, HIGH);
  digitalWrite(RY7A, HIGH);
  digitalWrite(RY8A, HIGH);

  Serial.begin(9600);
}



void loop() {
  Serial.println("turning on");
  digitalWrite(RY1A, LOW);
  digitalWrite(RY2A, LOW);
  digitalWrite(RY3A, LOW);
  digitalWrite(RY4A, LOW);
  digitalWrite(RY5A, LOW);
  digitalWrite(RY6A, LOW);
  digitalWrite(RY7A, LOW);
  digitalWrite(RY8A, LOW);
  delay(5000);
  Serial.println("turning off");
  digitalWrite(RY1A, HIGH);
  digitalWrite(RY2A, HIGH);
  digitalWrite(RY3A, HIGH);
  digitalWrite(RY4A, HIGH);
  digitalWrite(RY5A, HIGH);
  digitalWrite(RY6A, HIGH);
  digitalWrite(RY7A, HIGH);
  digitalWrite(RY8A, HIGH);

  delay(5000);
  Serial.println("turning on");
  digitalWrite(RY1A, LOW);
  delay(100);
  digitalWrite(RY2A, LOW);
  delay(100);
  digitalWrite(RY3A, LOW);
  delay(100);
  digitalWrite(RY4A, LOW);
  delay(100);
  digitalWrite(RY5A, LOW);
  delay(100);
  digitalWrite(RY6A, LOW);
  delay(100);
  digitalWrite(RY7A, LOW);
  delay(100);
  digitalWrite(RY8A, LOW);
  Serial.println("turning off");
  delay(8000);
  digitalWrite(RY1A, HIGH);
  delay(100);
  digitalWrite(RY2A, HIGH);
  delay(100);
  digitalWrite(RY3A, HIGH);
  delay(100);
  digitalWrite(RY4A, HIGH);
  delay(100);
  digitalWrite(RY5A, HIGH);
  delay(100);
  digitalWrite(RY6A, HIGH);
  delay(100);
  digitalWrite(RY7A, HIGH);
  delay(100);
  digitalWrite(RY8A, HIGH);

}
