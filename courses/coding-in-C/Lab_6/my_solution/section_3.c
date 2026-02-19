/*
 * File: section3_sensor_fusion.c
 * Description: Sensor fusion with threshold-based object detection
 */

#include <stdio.h>

#define MAX_SAMPLES 3000

typedef struct
{
    float time;
    double probability;
} SensorData;

typedef struct
{
    int id;
    double threshold;
    SensorData data[MAX_SAMPLES];
    int object_detection[MAX_SAMPLES];
    int sample_count;
} Sensor;

/**
 * @brief Reads sensor data from file
 */
int read_sensor_file(const char *file_name, Sensor *p_sensor)
{
    FILE *p_file = fopen(file_name, "r");
    int index = 0;

    if ((p_file == NULL) || (p_sensor == NULL))
    {
        return 0;
    }

    while ((index < MAX_SAMPLES) &&
           (fscanf(p_file, "%f %lf",
                   &p_sensor->data[index].time,
                   &p_sensor->data[index].probability) == 2))
    {
        index++;
    }

    fclose(p_file);
    p_sensor->sample_count = index;

    return 1;
}

/**
 * @brief Generates binary detection signal
 */
void generate_detection(Sensor *p_sensor)
{
    for (int i = 0; i < p_sensor->sample_count; i++)
    {
        if (p_sensor->data[i].probability > p_sensor->threshold)
        {
            p_sensor->object_detection[i] = 1;
        }
        else
        {
            p_sensor->object_detection[i] = 0;
        }
    }
}

/**
 * @brief Prints detection intervals
 */
void print_intervals(const int *p_signal,
                     const SensorData *p_data,
                     int length)
{
    int is_active = 0;
    float start_time = 0.0f;

    for (int i = 0; i < length; i++)
    {
        if ((p_signal[i] == 1) && (is_active == 0))
        {
            start_time = p_data[i].time;
            is_active = 1;
        }
        else if ((p_signal[i] == 0) && (is_active == 1))
        {
            printf("Start: %.2f s End: %.2f s\n",
                   start_time,
                   p_data[i - 1].time);
            is_active = 0;
        }
    }

    if (is_active == 1)
    {
        printf("Start: %.2f s End: %.2f s\n",
               start_time,
               p_data[length - 1].time);
    }
}

int main(void)
{
    Sensor sensor_1 = { .id = 1, .threshold = 0.8 };
    Sensor sensor_2 = { .id = 2, .threshold = 0.7 };
    int fused_signal[MAX_SAMPLES] = {0};

    read_sensor_file("sensor1.txt", &sensor_1);
    read_sensor_file("sensor2.txt", &sensor_2);

    generate_detection(&sensor_1);
    generate_detection(&sensor_2);

    for (int i = 0; i < sensor_1.sample_count; i++)
    {
        if ((sensor_1.object_detection[i] == 1) &&
            (sensor_2.object_detection[i] == 1))
        {
            fused_signal[i] = 1;
        }
        else
        {
            fused_signal[i] = 0;
        }
    }

    printf("\nSensor 1 detections:\n");
    print_intervals(sensor_1.object_detection,
                    sensor_1.data,
                    sensor_1.sample_count);

    printf("\nSensor 2 detections:\n");
    print_intervals(sensor_2.object_detection,
                    sensor_2.data,
                    sensor_2.sample_count);

    printf("\nFused signal (both sensors):\n");
    print_intervals(fused_signal,
                    sensor_1.data,
                    sensor_1.sample_count);

    return 0;
}