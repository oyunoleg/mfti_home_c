#ifndef FILE_API_H
#define FILE_API_H

#include <stdio.h>
#include <stdlib.h>

FILE *try_open_file(const char filename[], const char mode[]);
void write_error_file(const char *format, ...);
void drop_error_file();

#endif