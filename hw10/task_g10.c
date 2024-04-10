/*
G10
Самое длинное слово
В файле .txt дана строка слов, разделенных пробелами.
Найти самое длинное слово и вывести его в файл .txt.
Случай, когда самых длинных слов может быть несколько, не обрабатывать.

Данные на входе: 	Строка из английских букв и пробелов. Не более 1000 символов.
Данные на выходе: 	Одно слово из английских букв.

Пример
Данные на входе: 	Hello beautiful world
Данные на выходе: 	beautiful
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

// Поиск самого длинного слова
void search_longest(char str[], char out[])
{
    char longest_word[MAX_LENGTH] = {0};
    int longest_len = 0;
    char *word = strtok(str, " ");
    while (word != NULL)
    {
        int length = strlen(word);
        if (length > longest_len)
        {
            strcpy(longest_word, word);
            longest_len = length;
        }
        word = strtok(NULL, " ");
    }
    strcpy(out, longest_word);
}

int main(void)
{
    FILE *fp;
    char str[MAX_LENGTH] = {0};
    char uniques[MAX_LENGTH] = {0};
    int count = 0;

    if ((fp = try_open_file(INPUT_FILE, "r")) == NULL)
        return 1;
    fscanf(fp, "%[^\n]", str);
    fclose(fp);

    // Поиск самого длинного слова
    char longest_word[MAX_LENGTH] = {0};
    search_longest(str, longest_word);

    if ((fp = try_open_file(OUTPUT_FILE, "w")) == NULL)
        return 1;
    fprintf(fp, "%s", longest_word);
    fclose(fp);

    return 0;
}
