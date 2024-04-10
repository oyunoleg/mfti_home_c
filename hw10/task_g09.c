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

// Только уникальные без пробела
void get_uniques(const char in[], char out[])
{
    int count = 0;
    for (int i = 0; i < strlen(in) && in[i] != '\0'; ++i)
    {
        if (in[i] == ' ')
            continue;

        // Есть ли уже символ в массиве out
        int exists = 0;
        for (int j = 0; j < count; ++j)
        {
            if (in[i] == out[j])
            {
                exists = 1;
                break;
            }
        }

        if (!exists)
            out[count++] = in[i];
    }
    out[count] = '\0';
}

int main(void)
{
    FILE *fp;
    char str[MAX_LENGTH] = {0};
    char uniques[MAX_LENGTH] = {0};

    if ((fp = try_open_file(INPUT_FILE, "r")) == NULL)
        return 1;
    fscanf(fp, "%[^\n]", str);
    fclose(fp);

    get_uniques(str, uniques);

    if ((fp = try_open_file(OUTPUT_FILE, "w")) == NULL)
        return 1;
    fprintf(fp, "%s", uniques);
    fclose(fp);

    return 0;
}
