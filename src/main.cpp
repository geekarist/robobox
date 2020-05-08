#include "Arduino.h"
#include "ArticulatedArm.h"

void setup() {
  Serial.begin(9600);
  Serial.println("Setup");
  articulatedarm::setup();
}

void loop() {
  Serial.println("Loop");
  articulatedarm::loop();
}