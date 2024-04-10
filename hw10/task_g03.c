/*
G3 Практ 1
Последний номер символа
В файле .txt дана строка из 1000 символов.
Показать номера символов, совпадающих
с последним символом строки. Результат записать в файл .txt

Данные на входе: 	Строка не более 1000 символов
Данные на выходе: 	Целые числа через пробел - номера символа,
который совпадает с последним символом строки.

Пример
Данные на входе: 	aabbcdb
Данные на выходе: 	2 3
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LINE_WIDTH 1001
const char *INPUT_FILE = "input.txt";
const char *OUTPUT_FILE = "output.txt";

FILE *try_open_file(const char filename[], const char mode[])
{
    FILE *fp = fopen(filename, mode);
    if (fp == NULL)
    {
        char message[1001];
        snprintf(message, sizeof(message), "Error opening file '%s' mode '%s'", filename, mode);
        perror(message);
    }
    return fp;
}

int main(void)
{

    FILE *fp;
    char line[LINE_WIDTH] = {0};

    if ((fp = try_open_file(INPUT_FILE, "r")) == NULL)
        return 1;
    fscanf(fp, "%[^\n]", line);
    fclose(fp);

    if ((fp = try_open_file(OUTPUT_FILE, "w")) == NULL)
        return 1;

    // Последний alphanum символ
    int last_char_idx = strlen(line) - 1;
    while (last_char_idx >= 0 && !isalnum(line[last_char_idx]))
        last_char_idx--;

    // Запись индксов таких же символов в файл
    for (int i = 0; i < last_char_idx; ++i)
    {
        if (line[i] == line[last_char_idx])
            fprintf(fp, "%d ", i);
    }
    fclose(fp);

    return 0;
}
