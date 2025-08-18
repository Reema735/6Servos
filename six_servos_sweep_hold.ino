/*
  Week 3 — 6 Servos (Sweep 2s then Hold 90°)
  Author: Reema Alghamdi
  Email: Algghamdir735@gmail.com

  Description:
    - All six servos sweep for ~2 seconds (back and forth).
    - After that, all servos hold at 90° (neutral).
    - Pins are configurable in the PINS[] array.
    - Use external 5–6V power for servos and tie GND with Arduino GND.
*/

#include <Servo.h>

const uint8_t PINS[6] = {3, 5, 6, 9, 10, 11}; // change if needed
Servo S[6];

const unsigned long SWEEP_MS = 2000;     // 2 seconds
const unsigned long STEP_MS  = 15;       // sweep speed
int pos = 0, dirStep = +4;               // 0..180
unsigned long t0, lastStep;

void attachAll() {
  for (int i=0;i<6;i++) {
    S[i].attach(PINS[i]);
    S[i].write(90);
  }
}

void writeAll(int angle) {
  for (int i=0;i<6;i++) S[i].write(angle);
}

void setup() {
  attachAll();
  t0 = millis();
  lastStep = millis();
}

void loop() {
  unsigned long now = millis();

  // Phase 1: sweep for ~2s
  if (now - t0 < SWEEP_MS) {
    if (now - lastStep >= STEP_MS) {
      lastStep = now;
      pos += dirStep;
      if (pos >= 180) { pos = 180; dirStep = -dirStep; }
      if (pos <= 0)   { pos = 0;   dirStep = -dirStep; }
      writeAll(pos);
    }
    return;
  }

  // Phase 2: hold at 90°
  writeAll(90);
  delay(20);
}
