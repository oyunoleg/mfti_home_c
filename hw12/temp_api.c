#include <stdio.h>
#include <stdlib.h>
#include "temp_api.h"
#include "file_api.h"

int add_sensor(int index, Sensor sensors[], uint16_t year, uint8_t month,
               uint8_t day, uint8_t hour, uint8_t minute, int8_t temperature)
{
    // Convensions: year == 0 is ALL; month == 0 is ALL
    if (month <= 12 && hour < 24 && minute < 60)
    {
        sensors[index].year = year;
        sensors[index].month = month;
        sensors[index].day = day;
        sensors[index].hour = hour;
        sensors[index].minute = minute;
        sensors[index].temperature = temperature;
        index++;
    }
    return index;
}

int parse_csv_file(char filename[], Sensor sensors[])
{
    FILE *fp = try_open_file(filename, "r");
    if (fp == NULL)
        return 0;

    char line[100];    // Строка в файле
    int line_num = 0;  // Счетчик строк файла
    int count = 0;     // Счетчик элементов массива
    int err_count = 0; // Счетчик ошибочных строк

    uint16_t year;
    uint8_t month, day, hour, minute;
    int8_t temperature;

    for (line_num = 0; fgets(line, sizeof(line), fp) != NULL && line_num < DATA_MAX_LENGTH; ++line_num)
    {
        // 2021;01;16;01;01;-47
        int parsed_values = sscanf(line, "%hu;%hhu;%hhu;%hhu;%hhu;%hhd",
                                   &year, &month, &day, &hour, &minute, &temperature);
        // Если parsed_values == 6 - все значения были прочитаны
        if (parsed_values == 6)
        {
            count = add_sensor(count, sensors, year, month, day, hour, minute, temperature);
        }
        else
        {
            err_count++;
            if (err_count == 1)
                puts("\n####  Parsing errors: ####");
            printf("Error #%d: file '%s', line %d\n", err_count, filename, line_num + 1);
            write_error_file("Error #%d: file '%s', line %d\n%s\n", err_count, filename, line_num + 1, line);
        }
    }
    fclose(fp);
    if (err_count > 0)
        printf("Total errors: %d.\n\n", err_count);

    return count;
}

int remove_sensor(int size, Sensor sensors[], int index)
{
    if (index < 0 || index >= size)
        return size; 
   
    // Сдвигаем влево, начиная с index.
    for (int i = index; i < size - 1; ++i)
    {
        sensors[i] = sensors[i + 1];
    }
    return size - 1;
}

int print_sensors(int size, Sensor sensors[], int max_limit)
{
    if (max_limit > size)
        max_limit = size;
    int i = 0;
    for (i = 0; i < max_limit; ++i)
    {
        printf("#%d: %04d-%02d-%02d %02d:%02d t=%3d\n", i + 1,
               sensors[i].year,
               sensors[i].month,
               sensors[i].day,
               sensors[i].hour,
               sensors[i].minute,
               sensors[i].temperature);
    }
    return i;
}

int filtered_count(int size, Sensor sensors[], uint16_t year, uint8_t month)
{
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (sensors[i].year == year || year == 0)
        {

            if (sensors[i].month == month || month == 0)
            {
                count++;
            }
        }
    }
    return count;
}

int8_t avg_monthly_temperature(int size, Sensor sensors[], uint16_t year, uint8_t month)
{
    int sum = 0, count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (sensors[i].year == year || year == 0)
        {
            if (sensors[i].month == month || month == 0)
            {
                sum += sensors[i].temperature;
                count++;
            }
        }
    }
    return (uint8_t)(sum / (count != 0 ? count : 1));
}

int8_t min_monthly_temperature(int size, Sensor sensors[], uint16_t year, uint8_t month)
{
    int8_t min = 99;
    for (int i = 0; i < size; ++i)
    {
        if (sensors[i].year == year || year == 0)
        {

            if (sensors[i].month == month || month == 0)
            {
                if (sensors[i].temperature < min)
                    min = sensors[i].temperature;
            }
        }
    }
    return min;
}

int8_t max_monthly_temperature(int size, Sensor sensors[], uint16_t year, uint8_t month)
{
    int8_t max = -99;
    for (int i = 0; i < size; ++i)
    {
        if (sensors[i].year == year || year == 0)
        {

            if (sensors[i].month == month || month == 0)
            {
                if (sensors[i].temperature > max)
                    max = sensors[i].temperature;
            }
        }
    }
    return max;
}

int8_t avg_yearly_temperature(int size, Sensor sensors[], uint16_t year)
{
    int sum = 0, count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (sensors[i].year == year || year == 0)
        {
            sum += sensors[i].temperature;
            count++;
        }
    }
    return (uint8_t)(sum / (count != 0 ? count : 1));
}

int8_t min_yearly_temperature(int size, Sensor sensors[], uint16_t year)
{
    int8_t min = 99;
    for (int i = 0; i < size; ++i)
    {
        if (sensors[i].year == year || year == 0)
        {
            if (sensors[i].temperature < min)
                min = sensors[i].temperature;
        }
    }
    return min;
}

int8_t max_yearly_temperature(int size, Sensor sensors[], uint16_t year)
{
    int8_t max = -99;
    for (int i = 0; i < size; ++i)
    {
        if (sensors[i].year == year || year == 0)
        {
            if (sensors[i].temperature > max)
                max = sensors[i].temperature;
        }
    }
    return max;
}

int compare_by_time(const void *a, const void *b)
{
    Sensor *pa = (Sensor *)a;
    Sensor *pb = (Sensor *)b;

    if (pa->year != pb->year)
        return pa->year - pb->year;
    if (pa->month != pb->month)
        return pa->month - pb->month;
    if (pa->day != pb->day)
        return pa->day - pb->day;
    if (pa->hour != pb->hour)
        return pa->hour - pb->hour;
    if (pa->minute != pb->minute)
        return pa->minute - pb->minute;
    return 0;
}

int compare_by_temperature(const void *a, const void *b)
{
    Sensor *pa = (Sensor *)a;
    Sensor *pb = (Sensor *)b;
    return pa->temperature - pb->temperature;
}

void sort_by_time(int size, Sensor sensors[])
{
    qsort(sensors, size, sizeof(Sensor), compare_by_time);
}

void sort_by_temperature(int size, Sensor sensors[])
{
    qsort(sensors, size, sizeof(Sensor), compare_by_temperature);
}
