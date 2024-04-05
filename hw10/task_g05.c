/*
G5 ДЗ 2
Заменить a на b
В файле .txt дана символьная строка не более 1000 символов.
Необходимо заменить все буквы "а" на буквы "b" и наоборот,
как заглавные, так и строчные. Результат записать в .txt.

Данные на входе:	Строка из маленьких и больших английских букв, знаков препинания и пробелов.
Данные на выходе: 	Строка из маленьких и больших английских букв, знаков препинания и пробелов.

Пример
Данные на входе:	aabbccddABCD
Данные на выходе: 	bbaaccddBACD
*/
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1001
const char *INPUT_FILE = "input.txt";
const char *OUTPUT_FILE = "output.txt";

void replaceChars(char str[])
{
    while (*str != '\0')
    {
        if (*str == 'a')
        {
            *str = 'b';
        }
        else if (*str == 'A')
        {
            *str = 'B';
        }
        else if (*str == 'b')
        {
            *str = 'a';
        }
        else if (*str == 'B')
        {
            *str = 'A';
        }
        str++;
    }
}

int main(void)
{
    FILE *fp;
    char str[MAX_LENGTH * 2] = {0}, result[MAX_LENGTH] = {0};

    // Чтение строки из входного файла в line массив
    if ((fp = fopen(INPUT_FILE, "r")) == NULL)
    {
        perror("Error occured while opening input file!");
        return 1;
    }
    fscanf(fp, "%[^\n]", str);
    fclose(fp);

    // Замена символов
    replaceChars(str);

    // Запись result в выходной файл
    if ((fp = fopen(OUTPUT_FILE, "w")) == NULL)
    {
        perror("Error occured while opening output file!");
        return 1;
    }
    fprintf(fp, "%s", str);
    fclose(fp);

    return 0;
}
