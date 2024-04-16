#include <inttypes.h>

typedef struct
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
} Sensor;

int8_t temperature_avg_month(int size, Sensor sensors[], uint16_t year, uint8_t month);
int8_t temperature_max_month(int size, Sensor sensors[], uint16_t year, uint8_t month);
int8_t temperature_min_month(int size, Sensor sensors[], uint16_t year, uint8_t month);

int8_t temperature_avg_year(int size, Sensor sensors[], uint16_t year);
int8_t temperature_max_year(int size, Sensor sensors[], uint16_t year);
int8_t temperature_min_year(int size, Sensor sensors[], uint16_t year);
