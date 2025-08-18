# Week 3 — 6 Servos (Arduino UNO)

**Student:** Reema Alghamdi  
**Email:** Algghamdir735@gmail.com  
**Date:** 2025-08-18

## What I built
I programmed six servo motors using Arduino UNO. First, all servos execute a *Sweep* motion for about **2 seconds** (back and forth). After that, I command **all servos to hold at 90°** (neutral position). I wrote the code using the built‑in `Servo.h` library and made the pins configurable.

## Hardware & Wiring (what I used)
- Arduino UNO
- 6 × Micro Servos (SG90 or similar)
- External 5–6V power supply (recommended)
- Jumper wires

**Pins mapping (editable in code):** `3, 5, 6, 9, 10, 11`  

**Power note:** I powered the servos from an **external 5–6V** supply. I connected the **GND of the external supply to Arduino GND** (common ground) to keep signals referenced correctly.

Typical servo wires:

- RED → +5~6V

- BROWN/BLACK → GND

- ORANGE/YELLOW → Signal (to the Arduino pin)


## How to run my code
1. Open Arduino IDE → *File → New*.

2. Paste the file `six_servos_sweep_hold.ino`.

3. (Optional) Change the pins inside `PINS[]` if needed.

4. Select **Board: Arduino UNO** and the correct **COM port**.

5. Upload. You will see all six servos sweep for ~2 seconds, then hold at **90°**.

---

## Humanoid Walking — my high‑level algorithm
I imagined a simple humanoid with 6 servos: **L/R hip, knee, ankle**. I designed a state machine that repeats left–right steps while keeping balance:

1. **Stand**: All joints at 90°.
2. **Shift weight to left**: slight ankle/torso lean (Right ankle +5°, Left ankle −5°).
3. **Lift right foot**: Right hip +10°, Right knee +20°, Right ankle +10°.
4. **Swing right forward**: Right hip +20° more; keep knee flexed.
5. **Right foot contact**: Right ankle −10°; right knee returns toward 90°.
6. **Transfer weight to right**: swap ankle lean (Left +5°, Right −5°).
7. **Lift left foot**: Left hip +10°, Left knee +20°, Left ankle +10°.
8. **Swing left forward**: Left hip +20°.
9. **Left foot contact**: Left ankle −10°; left knee to 90°.

10. **Repeat** from step 2.


Each sub‑step takes ~150–300 ms with smooth interpolation to avoid jerky motion. Throughout the cycle I keep the **center of mass over the support foot** using small ankle corrections (±5–10°) and I limit angles within mechanical constraints.

---

## Repository files
- `six_servos_sweep_hold.ino` — my Arduino sketch.

- `README.md` — this report (what I did, wiring, and the walking algorithm).


> Note: powering six servos from the Arduino 5V pin is **not recommended**. Always use an external supply with common GND.
