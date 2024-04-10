/*
G14
Hello name
В файле .txt в одной строке фамилию, имя и отчество.
Сформировать файл приветствие .txt, где останутся имя и фамилия
Данные на входе: 	Строка состоящая из английских букв и пробелов не более 100 символов.
  Формат: Фамилия Имя Отчество
Данные на выходе: 	Строка состоящая из английских букв и пробелов

Пример
Данные на входе: 	Pupkin Vasiliy Ivanovich
Данные на выходе: 	Hello, Vasiliy Pupkin!
*/
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 101
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

void parse_name(char str[], char surname[], char name[])
{
    int count = 0;
    char *word = strtok(str, " ");
    while (count < 2)
    {
        if (word == NULL)
            break;
        if (count == 0)
            strcpy(surname, word);
        else if (count == 1)
            strcpy(name, word);
        count++;
        word = strtok(NULL, " ");
    }
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

    char surname[MAX_LENGTH] = {0}, name[MAX_LENGTH] = {0};
    parse_name(str, surname, name);

    fprintf(fp, "Hello, %s %s!", name, surname);
    fclose(fp);

    return 0;
}
