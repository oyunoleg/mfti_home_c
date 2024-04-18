#ifndef TEMP_API_H
#define TEMP_API_H

#include <inttypes.h>
#include "main.h"

typedef struct
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
} Sensor;

int add_sensor(int index, Sensor sensors[], uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, int8_t temperature);
int parse_csv_file(char filename[], Sensor sensors[]);
int remove_sensor(int size, Sensor sensors[], int index);
int print_sensors(int size, Sensor sensors[], int max_limit);

int filtered_count(int size, Sensor sensors[], uint16_t year, uint8_t month);
int8_t avg_monthly_temperature(int size, Sensor sensors[], uint16_t year, uint8_t month);
int8_t min_monthly_temperature(int size, Sensor sensors[], uint16_t year, uint8_t month);
int8_t max_monthly_temperature(int size, Sensor sensors[], uint16_t year, uint8_t month);

int8_t avg_yearly_temperature(int size, Sensor sensors[], uint16_t year);
int8_t min_yearly_temperature(int size, Sensor sensors[], uint16_t year);
int8_t max_yearly_temperature(int size, Sensor sensors[], uint16_t year);

int compare_by_time(const void *a, const void *b);
int compare_by_temperature(const void *a, const void *b);
void sort_by_time(int size, Sensor sensors[]);
void sort_by_temperature(int size, Sensor sensors[]);

#endif
