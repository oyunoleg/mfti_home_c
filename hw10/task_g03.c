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
    char c, last_char;
    int count = 0;

    // Открытие входного файла для чтения
    if ((fp = try_open_file(INPUT_FILE, "r")) == NULL)
        return 1;

    // Чтение первой строки из входного файла
    while (((c = getc(fp)) != EOF) && (c != '\n'))
    {
        line[count++] = c;
        last_char = c;
    }
    line[count] = '\0';
    fclose(fp);

    // Открытие выходного файла для записи
    if ((fp = try_open_file(OUTPUT_FILE, "w")) == NULL)
        return 1;

    // Запись в выходной файл
    for (int i = 0; i < count - 1; ++i)
    {
        if (line[i] == last_char)
            fprintf(fp, "%d ", i);
    }
    fclose(fp);

    return 0;
}
