////////////////////////////////////////////////////////////////////////////////
// 902 sequencer
// https://github.com/tczerwonka/sequencer-sdr1k/
// this is an arduino pro board
////////////////////////////////////////////////////////////////////////////////

#define PWR_LED   2
#define PTT_LED   3
#define PTT_IN    4
#define TR_RELAY  5
#define MMIC_PWR  6
#define TX  1
#define RX  0

int current = RX;
int previous = RX;


void setup() {
  pinMode(PWR_LED, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(PTT_LED, OUTPUT);
  pinMode(TR_RELAY, OUTPUT);
  pinMode(MMIC_PWR, OUTPUT);
  pinMode(PTT_IN, INPUT_PULLUP);

  digitalWrite(PWR_LED, HIGH);
}

void loop() {
  if (!digitalRead(PTT_IN)) {
    if (previous == RX) {
      //go to TX
      current = RX;
      digitalWrite(PTT_LED, HIGH);
      digitalWrite(13, HIGH);
      digitalWrite(TR_RELAY, HIGH);
      delay(10);
      digitalWrite(MMIC_PWR, HIGH);
      previous = TX;
    } //prev == RX
  } else {
    if (previous == TX) {
      //go to RX
      digitalWrite(MMIC_PWR, LOW);
      delay(10);
      digitalWrite(TR_RELAY, LOW);
      digitalWrite(PTT_LED, LOW);
      digitalWrite(13, LOW);
      previous = RX;
      delay(500);
    }
  }
}
