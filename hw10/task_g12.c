/*
G12
Разобрать на слова
В файле .txt дано предложение требуется разобрать его на отдельные слова.
Напечатать каждое слово на отдельной строке в файл .txt.

Данные на входе: 	Одна строка из английских букв и пробелов не более 1000 символов.
Данные на выходе: 	Каждое слово на отдельной строке

Пример
Данные на входе: 	Mama mila ramu
Данные на выходе: 	Mama mila ramu
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



int main(void)
{
    FILE *fp;
    char str[MAX_LENGTH] = {0};

    if ((fp = try_open_file(INPUT_FILE, "r")) == NULL)
        return 1;
    fscanf(fp, "%[^\n]", str);
    fclose(fp);

    if ((fp = try_open_file(OUTPUT_FILE, "w")) == NULL)
        return 1;
    
    char *word = strtok(str, " ");
    while (word != NULL)
    {
        fprintf(fp, "%s\n", word);
        word = strtok(NULL, " ");
    }
    fclose(fp);

    return 0;
}
