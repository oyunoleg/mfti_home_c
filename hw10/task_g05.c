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

void replace_chars(char str[])
{
    for (int i = 0; i < strlen(str) && str[i] != '\0'; i++)
    {
        if (str[i] == 'a' || str[i] == 'b')
        {
            str[i] = (str[i] == 'a') ? 'b' : 'a';
        }
        else if (str[i] == 'A' || str[i] == 'B')
        {
            str[i] = (str[i] == 'A') ? 'B' : 'A';
        }
    }
}

int main(void)
{
    FILE *fp;
    char str[MAX_LENGTH * 2] = {0}, result[MAX_LENGTH] = {0};

    if ((fp = try_open_file(INPUT_FILE, "r")) == NULL)
        return 1;

    fscanf(fp, "%[^\n]", str);
    fclose(fp);

    // Замена символов
    replace_chars(str);

    if ((fp = try_open_file(OUTPUT_FILE, "w")) == NULL)
        return 1;
    fprintf(fp, "%s", str);
    fclose(fp);

    return 0;
}
