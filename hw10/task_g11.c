/*
G11
Заканчивается на a
В файле .txt дано предложение.
Необходимо определить, сколько слов заканчиваются на букву 'а'.
Ответ записать в файл .txt.

Данные на входе:	Строка из английских букв и пробелов не более 1000 символов.
Данные на выходе: 	Одно целое число

Пример
Данные на входе:	Mama mila ramu
Данные на выходе: 	2
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

// Подсчет - сколько слов заканчиваются на букву 'а'.
int count_words(char str[], char pattern)
{
    int count = 0;
    char *word = strtok(str, " ");
    while (word != NULL)
    {
        if (word[strlen(word) - 1] == pattern)
            count++;
        word = strtok(NULL, " ");
    }
    return count;
}

int main(void)
{
    FILE *fp;
    char str[MAX_LENGTH] = {0};

    if ((fp = try_open_file(INPUT_FILE, "r")) == NULL)
        return 1;
    fscanf(fp, "%[^\n]", str);
    fclose(fp);

    // Подсчет - сколько слов заканчиваются на букву 'а'.
    int count = count_words(str, 'a');

    if ((fp = try_open_file(OUTPUT_FILE, "w")) == NULL)
        return 1;
    fprintf(fp, "%d", count);
    fclose(fp);

    return 0;
}
