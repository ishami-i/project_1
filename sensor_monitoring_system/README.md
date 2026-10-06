# Sensor Monitoring System

A water-quality monitoring program written in C. It takes a temperature reading and a turbidity reading, calculates a simplified water-quality index, classifies the water, and prints a formatted report.

## Files

| File | Purpose |
|------|---------|
| `main.c` | Complete program: index calculation, classification and report output |

## How it works

### Index formula

```
Index = 100 - (TemperatureDeviation + TurbidityPenalty)

TemperatureDeviation = |Temperature - 25|
TurbidityPenalty     = Turbidity / 2
```

### Classification

| Index | Status |
|-------|--------|
| 80 or higher | Good |
| 60 to below 80 | Warning |
| Below 60 | Critical |

### Functions

| Function | Role |
|----------|------|
| `absolute(float)` | Absolute value of a float |
| `calculate_index(float, float)` | Computes the water-quality index |
| `classify_water(float)` | Returns "Good", "Warning" or "Critical" |
| `main()` | Holds the sensor readings and prints the report |

The readings are hard-coded in `main()` (31.0 °C and 30.0 NTU). On a real device they would come from the sensors.

## Build and run

```bash
gcc -Wall -Wextra -o main main.c
./main
```

## Sample output

```
===== WATER QUALITY MONITORING REPORT =====
Temperature   : 31.0 C
Turbidity     : 30.0 NTU
Quality Index : 79.0
Status        : Warning
===========================================
```

Check: deviation = |31 - 25| = 6, penalty = 30 / 2 = 15, index = 100 - (6 + 15) = 79, which is in the Warning range.

## Changing the readings

Edit these two lines in `main()` and recompile:

```c
float temperature = 31.0f;   /* degrees Celsius */
float turbidity   = 30.0f;   /* NTU */
```
