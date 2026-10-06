# Smart Parking System (Arduino)

A small-scale smart parking indicator for a shopping centre. An ultrasonic sensor detects whether a car is in front of the space, a button stores whether the space is taken, and LEDs and a buzzer show the result to drivers.

## Files

| File | Purpose |
|------|---------|
| `smart_parking_system.ino` | Arduino sketch |
| `smart_parking_system.png` | Circuit drawing (made in Tinkercad) |

## Hardware

- Arduino Uno
- Parallax PING))) ultrasonic distance sensor
- 1 red LED and 1 green LED, each with a series resistor
- 1 piezo buzzer
- 1 push button
- Breadboard and jumper wires

## Pin connections

| Component | Arduino pin |
|-----------|-------------|
| Push button | D6 (`INPUT_PULLUP`, other leg to GND) |
| PING))) signal | D7 |
| Red LED (via resistor) | D8 |
| Green LED (via resistor) | D9 |
| Buzzer (+) | D10 |
| PING))) 5V / GND | 5V / GND |

See `smart_parking_system.png` for the wiring.

## Behaviour

| Car detected (closer than 2 m) | Space marked taken | Red LED | Green LED | Buzzer |
|---|---|---|---|---|
| Yes | Yes | On | Off | On |
| Yes | No | Off | On | Off |
| No | Any | Off | Off | Off |

- The button toggles the stored "taken" state on each press, with a 200 ms debounce.
- The sensor is read with a 30 ms timeout, so a missing echo never blocks the program. No echo is treated as "nothing nearby".
- The button is checked again during the 100 ms wait at the end of each loop, so quick presses aren't missed.
- Distance and space state are printed to the Serial Monitor at 9600 baud, for example:

```
Distance: 1.20 m | Spot: FREE
```

## How to run

1. Build the circuit as shown in the drawing.
2. Open `smart_parking_system.ino` in the Arduino IDE.
3. Select **Arduino Uno** and the correct port, then upload.
4. Open the Serial Monitor at 9600 baud to see the readings.

## Configuration

| Setting | Where | Default |
|---------|-------|---------|
| Detection distance | `thresholdMeters` | 2.0 m |
| Pin assignments | `buttonPin`, `pingPin`, `redLed`, `greenLed`, `buzzer` | 6, 7, 8, 9, 10 |
| Buzzer tone | `tone(buzzer, 1000)` | 1000 Hz |
