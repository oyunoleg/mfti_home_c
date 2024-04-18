#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include "temp_api.h"
#include "file_api.h"

// Выодит в консоль справку.
static void print_help()
{
    puts("List of arguments:");
    puts("  -h for help.");
    puts("  -f <filename> for load data.");
    puts("  -y <xxxx> for year  (0: all).");
    puts("  -m <xx>   for month (0: all).");
}

// Выодит в консоль значение температуры с учетом знака.
static void print_temperature(char prefix[], int8_t temperature)
{
    if (temperature > 0)
        printf("%s%+3d\n", prefix, temperature);
    else
        printf("%s%3d\n", prefix, temperature);
}

// Выодит в консоль статистику.
static void get_statistics(int size, Sensor sensors[], uint16_t year, uint8_t month)
{
    // Выводим отсортированный список 1.
    puts("## Sorted by temperature #");
    sort_by_temperature(size, sensors);
    print_sensors(size, sensors, 5);
    puts("");

    // Выводим отсортированный список 2.
    puts("##### Sorted by time #####");
    sort_by_time(size, sensors);
    print_sensors(size, sensors, 5);
    puts("");

    int res_count = 0;

    // Получаем статистику за месяц.
    puts("### Monthly statistics ###");
    res_count = filtered_count(size, sensors, year, month);
    if (res_count > 0)
    {
        print_temperature("- Average: ", avg_monthly_temperature(size, sensors, year, month));
        print_temperature("- Minimum: ", min_monthly_temperature(size, sensors, year, month));
        print_temperature("- Maximum: ", max_monthly_temperature(size, sensors, year, month));
    }
    else
        puts(" - No any data for this year-month.");
    printf("records: %d, month: '%04d-%02d'\n", res_count, year, month);
    puts("");

    // Получаем статистику за год.
    puts("### Yearly statistics  ###");
    res_count = filtered_count(size, sensors, year, 0);
    if (res_count > 0)
    {
        print_temperature("- Average: ", avg_yearly_temperature(size, sensors, year));
        print_temperature("- Minimum: ", min_yearly_temperature(size, sensors, year));
        print_temperature("- Maximum: ", max_yearly_temperature(size, sensors, year));
    }
    else
        puts(" - No any data for this year.");
    printf("records: %d, year: '%04d'\n", res_count, year);
    puts("");
}

// Читает аргументы командной строки.
static void read_argv(int argc, char *argv[], int *help_flag,
                      char filename[], int *year, int *month)
{
    int rez;
    // Обходим все аргументы командной строки
    while ((rez = getopt(argc, argv, "hHf:y::m::")) != -1)
    {
        // printf("- %c %s\n", rez, optarg);
        switch (rez)
        {
        case 'h':
        case 'H':
            print_help();
            *help_flag = 1;
            break;
        case 'f':
            if (optarg != NULL && optarg[0] != '-')
            {
                strncpy(filename, optarg, FILENAME_MAX_LENGTH);
            }
            else
            {
                fprintf(stderr, "Error: missing argument for -f.\n");
                exit(1);
            }
            break;
        case 'y':
            if (optarg != NULL && optarg[0] != '-')
            {
                *year = atoi(optarg);
            }
            break;
        case 'm':
            if (optarg != NULL && optarg[0] != '-')
            {
                *month = atoi(optarg);
            }
            break;
        case '?':
            fprintf(stderr, "Error: unknown arguments.\n");
            exit(1);
        }
    }
}

int main(int argc, char *argv[])
{
    puts("The program in started!");
    char filename[FILENAME_MAX_LENGTH] = {0};
    int help_printed = 0, year = 0, month = 0;

    drop_error_file(); // drop log-file "errors.txt"

    read_argv(argc, argv, &help_printed, filename, &year, &month);
    if (help_printed == 1)
        return 0;

    static Sensor sensors[DATA_MAX_LENGTH] = {0};
    int size = parse_csv_file(filename, sensors);
    if (size == 0)
    {
        printf("No data parsed from file '%s'.\n", filename);
        return 1;
    }

    get_statistics(size, sensors, year, month);
    printf("filename: '%s'\n", filename);
    printf("total records: %d\n", size);

    return 0;
}
