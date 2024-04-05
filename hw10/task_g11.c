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

    // Подсчет - сколько слов заканчиваются на букву 'а'.
    int count = 0;
    char *word = strtok(str, " ");
    while (word != NULL)
    {
        if (word[strlen(word) - 1] == 'a')
            count++;
        word = strtok(NULL, " ");
    }

    // Запись в выходной файл
    if ((fp = fopen(OUTPUT_FILE, "w")) == NULL)
    {
        perror("Error occured while opening output file!");
        return 1;
    }
    fprintf(fp, "%d", count);
    fclose(fp);

    return 0;
}
