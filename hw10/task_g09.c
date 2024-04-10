/*
G9 ДЗ 4
Удалить повторяющиеся символы
В файле .txt строка из меленьких и больших английских букв, знаков препинания и пробелов.
Требуется удалить из нее повторяющиеся символы и все пробелы.
Результат записать в файл .txt.

Данные на входе: 		Строка из меленьких и больших английских букв, знаков препинания и пробелов.
Размер строки не более 1000 сивмолов.
Данные на выходе: 	Строка из меленьких и больших английских букв.

Пример
Данные на входе: 	abc cde def
Данные на выходе: 	abcdef
*/
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1001
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

int is_exists(int size, char arr[], char c)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == c)
            return 1;
    }
    return 0;
}

int main(void)
{
    FILE *fp;
    char str[MAX_LENGTH] = {0};
    char uniques[MAX_LENGTH] = {0};
    int count = 0;

    // Чтение строки из входного файла в массив
    if ((fp = try_open_file(INPUT_FILE, "r")) == NULL)
        return 1;
    fscanf(fp, "%[^\n]", str);
    fclose(fp);

    // Только уникальные без пробела
    count = 0;
    for (int i = 0; str[i] != '\0' && i < MAX_LENGTH; ++i)
    {
        if (str[i] == ' ')
            continue;

        if (!is_exists(count, uniques, str[i]))
            uniques[count++] = str[i];
    }
    uniques[count] = '\0';

    // Запись в выходной файл
    if ((fp = try_open_file(OUTPUT_FILE, "w")) == NULL)
        return 1;
    fprintf(fp, "%s", uniques);
    fclose(fp);

    return 0;
}
