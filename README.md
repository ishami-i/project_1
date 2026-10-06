# Project 1: C and Arduino Formative Assignment

A formative assignment made of four problems, each solved in its own directory. Three are standard C programs and one is an Arduino sketch.

## Repository structure

```
.
├── README.md
├── .gitignore
├── sensor_monitoring_system/
│   ├── README.md
│   └── main.c
├── transaction_control_flow/
│   ├── README.md
│   ├── main.c
│   ├── main.h
│   ├── balance.c
│   ├── deposit.c
│   ├── withdraw.c
│   └── summary.c
├── recursive_problem_solving/
│   ├── README.md
│   └── main.c
└── smart_parking_system/
    ├── README.md
    ├── smart_parking_system.ino
    └── smart_parking_system.png
```

## The four problems

| # | Directory | Topic | Language |
|---|-----------|-------|----------|
| 1 | [`sensor_monitoring_system`](sensor_monitoring_system/) | Water-quality index from temperature and turbidity readings | C |
| 2 | [`transaction_control_flow`](transaction_control_flow/) | Menu-driven mobile-money transaction system | C (multi-file) |
| 3 | [`recursive_problem_solving`](recursive_problem_solving/) | Delivery-distance analysis with a recursive sum | C |
| 4 | [`smart_parking_system`](smart_parking_system/) | Ultrasonic parking-space indicator | Arduino (C++) |

### 1. Sensor monitoring system
A water-quality monitoring device reads a temperature and a turbidity value, calculates a simplified quality index, classifies the water as Good, Warning or Critical, and prints a formatted report.

### 2. Transaction processing and control flow
A mobile-money agent repeatedly processes deposits, withdrawals, balance checks and summaries from a menu, with input validation and handling of invalid operations.

### 3. Functions and recursive problem solving
A logistics company analyses the distances of N delivery routes: total, average, longest route, routes above a limit, and a recursive sum of the distances.

### 4. Arduino-based smart parking system
A shopping-centre parking indicator detects whether a space is occupied and shows the result with LEDs and a buzzer. The directory includes the circuit drawing.

## Requirements

- **Problems 1 to 3:** a C compiler such as `gcc` or `clang` (C99 or later).
- **Problem 4:** the Arduino IDE (or `arduino-cli`) and the hardware listed in that directory's README, or a simulator such as Tinkercad.

## Building and running

Each C directory is built on its own. From the repository root:

```bash
# 1. Sensor monitoring system
gcc -Wall -Wextra -o sensor_monitoring_system/main sensor_monitoring_system/main.c
./sensor_monitoring_system/main

# 2. Transaction control flow
cd transaction_control_flow
gcc -Wall -Wextra -o momo main.c balance.c deposit.c withdraw.c summary.c
./momo
cd ..

# 3. Recursive problem solving
gcc -Wall -Wextra -o recursive_problem_solving/main recursive_problem_solving/main.c
./recursive_problem_solving/main
```

For problem 4, open `smart_parking_system/smart_parking_system.ino` in the Arduino IDE, select your board and port, and upload.

## Notes

- Compiled binaries (`main`, `momo`) are build output and don't need to be committed.
- Open each directory's own README for details on design, sample runs and usage.
