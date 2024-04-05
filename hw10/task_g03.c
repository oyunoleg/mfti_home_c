/*
G3 Практ 1
Последний номер символа
В файле .txt дана строка из 1000 символов. 
Показать номера символов, совпадающих
с последним символом строки. Результат записать в файл .txt

Данные на входе: 	Строка не более 1000 символов
Данные на выходе: 	Целые числа через пробел - номера символа,
который совпадает с последним символом строки.

Пример
Данные на входе: 	aabbcdb
Данные на выходе: 	2 3
*/
#include <stdio.h>
#include <string.h>

#define LINE_WIDTH 1001
const char *INPUT_FILE = "input.txt";
const char *OUTPUT_FILE = "output.txt";

int main(void)
{

    FILE *f_in, *f_out;
    char line[LINE_WIDTH] = {0};
    char c, last_char;
    int count = 0;

    // Открытие входного файла для чтения
    if ((f_in = fopen(INPUT_FILE, "r")) == NULL)
    {
        perror("Error occured while opening input file!");
        fprintf(stderr, "Failed to open file: '%s'.\n", INPUT_FILE);
        return 1;
    }

    // Чтение первой строки из входного файла
    while (((c = getc(f_in)) != EOF) && (c != '\n'))
    {
        line[count++] = c;
        last_char = c;
    }
    line[count] = '\0';
    fclose(f_in);

    // Открытие выходного файла для записи
    if ((f_out = fopen(OUTPUT_FILE, "w")) == NULL)
    {
        perror("Error occured while opening output file!");
        fprintf(stderr, "Failed to open file: '%s'.\n", OUTPUT_FILE);
        return 1;
    }

    // Запись в выходной файл
    for (int i = 0; i < count - 1; ++i)
    {
        if (line[i] == last_char)
            fprintf(f_out, "%d ", i);
    }
    fclose(f_out);

    return 0;
}

