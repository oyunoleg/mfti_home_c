/*
G4 ДЗ 1
По одному разу
В файле .txt даны два слова не более 100 символов каждое, разделенные одним пробелом.
Найдите только те символы слов, которые встречаются в обоих словах только один раз.
Напечатайте их через пробел в файл .txt в лексикографическом порядке.

Данные на входе:	Два слова из маленьких английских букв через пробел.
Длинна каждого слова не больше 100 символов.
Данные на выходе: 	Маленькие английские буквы через пробел.

Пример №1
Данные на входе:	hello world
Данные на выходе: 	o


Данные на входе: 	aabcd bcef
Данные на выходе: 	b c
*/

#include <stdio.h>
#include <string.h>

const char *INPUT_FILE = "input.txt";
const char *OUTPUT_FILE = "output.txt";
#define MAX_LENGTH 101

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

// Сортирует строку.
void sort_str(char str[])
{
    char temp;
    int size = strlen(str);
    for (int i = 0; i < size; ++i)
    {
        for (int j = size - 1; j > i; --j)
        {
            if (str[i] > str[j])
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

/* Заполняет массив out символами из in, которые встречаются в обоих словах только один раз.*/
void process(char in[], char out[])
{
    int len = strlen(in);
    int out_len = 0;

    // Индекс первого пробела (между словами)
    int space_index = 0;
    while (space_index < len && in[space_index] != ' ')
        space_index++;

    // Подсчет каждого символа в каждом слове, по первому слову
    int count1, count2;
    for (int i = 0; i < space_index; ++i)
    {
        count1 = 0;
        count2 = 0;

        // Количество таких же символов в первом слове
        for (int j = 0; j < space_index && count1 <= 2; ++j)
        {
            if (in[j] == in[i])
                count1++;
        }

        // Количество таких же символов во втором слове
        for (int j = space_index + 1; j < len && count2 <= 2; ++j)
        {
            if (in[j] == in[i])
                count2++;
        }

        if (count1 == 1 && count2 == 1)
            out[out_len++] = in[i];
    }
    out[out_len] = '\0';

    // Сортируем строку
    sort_str(out);
}

int main(void)
{
    FILE *fp;
    char str[MAX_LENGTH * 2] = {0}, result[MAX_LENGTH] = {0};

    if ((fp = try_open_file(INPUT_FILE, "r")) == NULL)
        return 1;
    fscanf(fp, "%[^\n]", str);
    fclose(fp);

    // Получение результата в массив result
    process(str, result);

    if ((fp = try_open_file(OUTPUT_FILE, "w")) == NULL)
        return 1;

    for (int i = 0; i < strlen(result); ++i)
        fprintf(fp, "%c ", result[i]);
    fclose(fp);

    return 0;
}
