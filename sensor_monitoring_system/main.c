#include <stdio.h>

/* Absolute value for float */
static float absolute(float x)
{
    return (x < 0.0f) ? -x : x;
}

/* Calculates the simplified water-quality index */
float calculate_index(float temperature, float turbidity)
{
    float temperature_deviation = absolute(temperature - 25.0f);
    float turbidity_penalty = turbidity / 2.0f;

    return 100.0f - (temperature_deviation + turbidity_penalty);
}

/* Classifies the water based on the index */
const char *classify_water(float index)
{
    if (index >= 80.0f)
        return "Good";
    else if (index >= 60.0f)
        return "Warning";
    else
        return "Critical";
}

int main(void)
{
    /* Sensor readings, hard coded */
    float temperature = 31.0f;   /* measured in degrees Celsius */
    float turbidity   = 30.0f;   /* measured in NTU */

    float index = calculate_index(temperature, turbidity);
    const char *status = classify_water(index);

    printf("===== WATER QUALITY MONITORING REPORT =====\n");
    printf("Temperature   : %.1f C\n", temperature);
    printf("Turbidity     : %.1f NTU\n", turbidity);
    printf("Quality Index : %.1f\n", index);
    printf("Status        : %s\n", status);
    printf("===========================================\n");

    return 0;
}