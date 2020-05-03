#include "Arduino.h"

namespace minialarm {

const int PIN_LED = 5;
const int PIN_MOTION = 2;
const int PIN_SPEAKER = 6;

void play(long secLength, int hzFreq) {
  Serial.println("Playing sound");
  long msecLength = secLength * 1000;
  int msecPeriod = (1.0 / hzFreq) * 1000000;
  long msecElapsed = 0;

  while (msecElapsed < msecLength) {
    digitalWrite(PIN_SPEAKER, HIGH);
    delayMicroseconds(msecPeriod / 2);
    digitalWrite(PIN_SPEAKER, LOW);
    delayMicroseconds(msecPeriod / 2);
    msecElapsed += msecPeriod;
  }
}

void setup() {
  Serial.begin(9600);
  Serial.print("Setting up...");
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_MOTION, INPUT);
  pinMode(PIN_SPEAKER, OUTPUT);
  Serial.println(" OK");
}

void loop() {
  int motion = digitalRead(PIN_MOTION);

  if (motion == HIGH) {
    Serial.println("Motion is HIGH");
    digitalWrite(PIN_LED, HIGH);
    play(300, 160);
    delay(700);
  } else {
    Serial.println("Motion is LOW");
    digitalWrite(PIN_LED, LOW);
    delay(1000);
  }
}

}  // namespace minialarm