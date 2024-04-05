/*
G6 Демо 2
Проверка на палиндром
В файле .txt символьная строка не более 1000 символов. 
Необходимо проверить, является ли она палиндромом (палиндром читается одинаково в обоих направлениях). 
Реализовать логическую функцию is_palindrom(str) и записать ответ в файл .txt.

Данные на входе: 		Строка из заглавных английских букв
Данные на выходе: 	YES или NO

Пример №1
Данные на входе: 	ABCDEF
Данные на выходе: 	NO

Пример №2
Данные на входе: 	KAZAK
Данные на выходе: 	YES
*/
#include <stdio.h>
#include <string.h>

const int line_width = 1024;

int is_palindrome(char *line)
{
    int len = strlen(line);
    for (int i = 0; i < len / 2; i++)
        if (line[i] != line[len - i - 1])
            return 0;
    return 1;
}

int main(void)
{
    char *input_fn = "input.txt";
    char *output_fn = "output.txt";
    char line[line_width];
    FILE *fp;

    fp = fopen(input_fn, "r");
    fscanf(fp, "%[^\n]", line);
    fclose(fp);

    fp = fopen(output_fn, "w");
    fprintf(fp, "%s", is_palindrome(line) ? "YES" : "NO");
    fclose(fp);
    return 0;
}
