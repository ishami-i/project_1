# Recursive Problem Solving

A delivery-distance analysis program written in C. It stores the distances of N routes in an integer array and reports useful statistics, including a sum calculated recursively.

## Files

| File | Purpose |
|------|---------|
| `main.c` | Input handling, all analysis functions and the results report |

## Functions

| Function | Role |
|----------|------|
| `total_distance` | Sum of all distances (iterative) |
| `average_distance` | Average distance; reuses `total_distance` |
| `longest_route` | Largest distance in the array |
| `count_above` | Number of routes strictly greater than a given limit |
| `recursive_sum` | Sum of the distances using recursion |

### The recursive function

```c
int recursive_sum(const int distances[], int n)
{
    if (n <= 0)
        return 0;                                    /* base case */

    return distances[n - 1] + recursive_sum(distances, n - 1);
}
```

- **Base case:** when `n <= 0` there is nothing left to add, so it returns `0`.
- **Progress:** each call reduces `n` by 1, so it always moves toward the base case.
- **Result:** each call adds the last remaining element to the sum of the rest and returns it to its caller.

### Function reuse

`average_distance` calls `total_distance` instead of repeating the summing logic.

## Input rules

- Number of routes: 1 to 100 (`MAX_ROUTES`).
- Distances: non-negative integers.
- Invalid input prints an error message and exits with code 1.

## Build and run

```bash
gcc -Wall -Wextra -o main main.c
./main
```

## Sample run

```
Number of routes: 6
Distances: 12 25 18 40 15 30
Distance limit: 20

===== DELIVERY DISTANCE ANALYSIS =====
Total distance: 140 km
Average distance: 23.33 km
Longest route: 40 km
Routes above 20 km: 3
Recursive sum: 140 km
```
