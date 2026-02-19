/*
 * File: section_2.c
 * Description: Demonstrates struct usage and pointer-based function calls
 */

#include <stdio.h>

#define MODEL_NAME_LENGTH 20

typedef struct
{
    float fuel_level;
    float max_fuel_level;
    char model[MODEL_NAME_LENGTH];
} Car;

/**
 * @brief Refuels a car without exceeding maximum fuel level
 *
 * @param[in,out] p_car   Pointer to car structure
 * @param[in]     amount  Amount of fuel to add
 */
void refuel(Car *p_car, float amount)
{
    if (p_car == NULL)
    {
        return;
    }

    p_car->fuel_level += amount;

    if (p_car->fuel_level > p_car->max_fuel_level)
    {
        p_car->fuel_level = p_car->max_fuel_level;
    }
}

int main(void)
{
    Car my_car =
    {
        .fuel_level = 5.0f,
        .max_fuel_level = 50.0f,
        .model = "Sedan"
    };

    printf("Before refuel: %.2f L\n", my_car.fuel_level);

    refuel(&my_car, 30.0f);

    printf("After refuel:  %.2f L\n", my_car.fuel_level);

    return 0;
}