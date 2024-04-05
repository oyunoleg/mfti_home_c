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

int main(void)
{
    FILE *fp;
    char str[MAX_LENGTH] = {0};

    // Чтение строки из входного файла в массив
    if ((fp = fopen(INPUT_FILE, "r")) == NULL)
    {
        perror("Error occured while opening input file!");
        return 1;
    }
    fscanf(fp, "%[^\n]", str);
    fclose(fp);

    // Запись в выходной файл
    if ((fp = fopen(OUTPUT_FILE, "w")) == NULL)
    {
        perror("Error occured while opening output file!");
        return 1;
    }

    char surname[MAX_LENGTH] = {0}, name[MAX_LENGTH] = {0};
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
    fprintf(fp, "Hello, %s %s!", name, surname);
    fclose(fp);

    return 0;
}
