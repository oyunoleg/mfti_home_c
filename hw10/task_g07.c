/*
G7 Практ 2
Количество букв
В файле .txt считать символьную строку, не более 10 000 символов.
Посчитать количество строчных (маленьких) и прописных (больших) букв в введенной строке.
Учитывать только английские буквы. Результат записать в файл .txt.

Данные на входе: 	Строка состоящая из английских букв, цифр, пробелов и знаков препинания.
Данные на выходе: 	Два целых числа. Количество строчных букв и количество заглавных букв.

Пример №1
Данные на входе: 	aabbAB
Данные на выходе: 	4 2

Пример №2
Данные на входе: 	HELLO WORLD
Данные на выходе: 	0 10
*/
#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 100001
const char *INPUT_FILE = "input.txt";
const char *OUTPUT_FILE = "output.txt";

int main(void)
{
    FILE *fp;
    char str[MAX_LENGTH] = {0};

    // Чтение строки из входного файла в line массив
    if ((fp = fopen(INPUT_FILE, "r")) == NULL)
    {
        perror("Error occured while opening input file!");
        return 1;
    }
    fscanf(fp, "%[^\n]", str);
    fclose(fp);

    // Количество строчных букв и количество заглавных букв.
    int lower_count = 0, upper_count = 0;
    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (isalpha(str[i]) != 0)
        {
            (islower(str[i]) != 0) ? lower_count++ : upper_count++;
        }
    }

    // Запись в выходной файл
    if ((fp = fopen(OUTPUT_FILE, "w")) == NULL)
    {
        perror("Error occured while opening output file!");
        return 1;
    }
    fprintf(fp, "%d %d", lower_count, upper_count);
    fclose(fp);

    return 0;
}
