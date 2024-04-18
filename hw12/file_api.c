#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include "main.h"

FILE *try_open_file(const char filename[], const char mode[])
{
    FILE *fp = fopen(filename, mode);
    if (fp == NULL)
    {
        fprintf(stderr, "Error opening file '%s' for mode '%s'.\n", filename, mode);
    }
    return fp;
}

/* Сохраняет форматированный текст в лог-файл.
Принимает строку формата и любое количество параметров.
Usage: write_error_file("Error %s on line %d\n", "example_str", 42); */
void write_error_file(const char *format, ...)
{
    FILE *fp = try_open_file(ERROR_LOGFILE, "a");
    if (fp != NULL)
    {
        time_t current_time = time(NULL);
        struct tm *timeinfo = localtime(&current_time);
        char formatted_time[20];
        strftime(formatted_time, sizeof(formatted_time), "%Y-%m-%d %H:%M:%S", timeinfo);
        fprintf(fp, "--- %s ----\n", formatted_time);

        va_list args;
        va_start(args, format);
        vfprintf(fp, format, args);
        va_end(args);
        fclose(fp);
    }
}

void drop_error_file()
{
    remove(ERROR_LOGFILE);
}
