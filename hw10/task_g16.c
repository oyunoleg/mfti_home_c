/*
G16 Практ 3
Ling заменить на Cao
В файле .txt дано предложение. Необходимо заменить все имена "Ling" на "Cao"
и результат записать в файл .txt.

Данные на входе:  Строка из английских букв, пробелов и знаков препинания.
  Не более 1000 символов.
Данные на выходе: Строка из английских букв, пробелов и знаков препинания.


Пример
Данные на входе:  Ling, Ling, Ling and Ling!!!
Данные на выходе: Cao, Cao, Cao and Cao!!!
*/
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1001
const char *INPUT_FILE = "input.txt";
const char *OUTPUT_FILE = "output.txt";

void input(char *strIn)
{
    FILE *in;
    in = fopen(INPUT_FILE, "r");

    while (fscanf(in, "%[^\n]", strIn) == 1)
        ;

    fclose(in);
}

void change_name(char in[], char out[])
{
    // Зачищаем буфер, поскольку далее есть его чтение
    for (int i = 0; i < MAX_LENGTH; ++i)
        out[i] = 0;

    int count = 0;
    for (int i = 0; i < strlen(in) && in[i] != '\0'; i++)
    {
        if (!memcmp(in + i, "Ling", 4))
        {
            strcat(out, "Cao");
            count += 3;
            i += 4;
        }
        out[count++] = in[i];
    }
}

void output(char *strOut)
{
    FILE *out;
    out = fopen(OUTPUT_FILE, "w");
    fprintf(out, "%s", strOut);
    fclose(out);
}

int main(int argc, char **argv)
{
    char str[MAX_LENGTH] = {0}, strFinal[MAX_LENGTH] = {0};
    input(str);
    change_name(str, strFinal);
    output(strFinal);
    return 0;
}
