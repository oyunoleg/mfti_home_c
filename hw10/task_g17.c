/*
G17
Пары соседних символов
В файле .txt записаны символы. Необходимо разработать функцию, которая
меняет местами пары соседних символов не обращая внимание на символы пробел.
Если количество символов нечетно (пробелы не считаем), то последний символ не меняем.
Результат записать в файл .txt.

Данные на входе: 	Строка из английских букв, пробелов и знаков препинания.
Не более 1000 символов.
Данные на выходе: 	Строка из английских букв, пробелов и знаков препинания.

Пример №1
Данные на входе: 	Hello world!
Данные на выходе: 	eHllw orodl!

Пример №2
Данные на входе: 	abc def
Данные на выходе: 	bad cfe
*/
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1001
const char *INPUT_FILE = "input.txt";
const char *OUTPUT_FILE = "output.txt";

// Чтение строки из входного файла в массив.
int input(char in[])
{
    FILE *fp;
    if ((fp = fopen(INPUT_FILE, "r")) == NULL)
    {
        perror("Error occured while opening input file!");
        return 1;
    }
    fscanf(fp, "%[^\n]", in);
    fclose(fp);
    return 0;
}

// Запись в выходной файл.
int output(char out[])
{
    FILE *fp;
    if ((fp = fopen(OUTPUT_FILE, "w")) == NULL)
    {
        perror("Error occured while opening output file!");
        return 1;
    }
    fprintf(fp, "%s", out);
    fclose(fp);

    return 0;
}

// Меняет местами два соседних символа.
void shrinkSpaces(char str[])
{
    int len = strlen(str);
    char space_char = ' ', temp;
    for (int i = 0; i < len; ++i)
    {
        // Пропускаем все пробелы
        if (str[i] == space_char)
            continue;

        // Поиск следующего не пробельного
        for (int j = i + 1; j < len; ++j)
        {
            if (str[j] != space_char)
            {
                // Меняем местами
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
                // Смещение индекса вперед
                i = j;
                break;
            }
        }
    }
}

int main(void)
{
    char str[MAX_SIZE] = {0};
    input(str);
    shrinkSpaces(str);
    output(str);

    return 0;
}
