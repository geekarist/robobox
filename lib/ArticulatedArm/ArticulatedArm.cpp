#include "Arduino.h"
#include "Servo.h"

namespace articulatedarm {

Servo servo1;
Servo servo2;

void setup() {
  servo1.attach(2);
  servo2.attach(4);
}

void loop() {
  Serial.print("Increase angle: ");
  for (int motorPosition = 0; motorPosition <= 90; motorPosition++) {
    Serial.print('.');
    servo1.write(motorPosition);
    servo2.write(motorPosition);
    delay(15);
  }
  Serial.println();
  Serial.print("Decrease angle: ");
  for (int motorPosition = 90; motorPosition >= 0; motorPosition--) {
    Serial.print('.');
    servo1.write(motorPosition);
    servo2.write(motorPosition);
    delay(15);
  }
  Serial.println();
}

}  // namespace articulatedarm