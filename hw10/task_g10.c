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

int main(void)
{
    FILE *fp;
    char str[MAX_LENGTH] = {0};
    char uniques[MAX_LENGTH] = {0};
    int count = 0;

    // Чтение строки из входного файла в массив
    if ((fp = fopen(INPUT_FILE, "r")) == NULL)
    {
        perror("Error occured while opening input file!");
        return 1;
    }
    fscanf(fp, "%[^\n]", str);
    fclose(fp);

    // Поиск самого длинного слова
    char longest_word[MAX_LENGTH] = {0};
    int longest_len = 0;
    char *word = strtok(str, " ");
    while (word != NULL)
    {
        int length = strlen(word);
        if (length > longest_len)
        {
            // Копируем все символы слова в longest_word
            strcpy(longest_word, word);
            longest_len = length;
        }
        word = strtok(NULL, " ");
    }

    // Запись в выходной файл
    if ((fp = fopen(OUTPUT_FILE, "w")) == NULL)
    {
        perror("Error occured while opening output file!");
        return 1;
    }
    fprintf(fp, "%s", longest_word);
    fclose(fp);

    return 0;
}
