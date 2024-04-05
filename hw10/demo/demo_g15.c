/*
G15 Демо 3
Cao заменить на Ling
В файле .txt дано предложение. Необходимо заменить все имена "Cao" на "Ling"
и записать результат в файл .txt.

Данные на входе:   Строка из английский букв, знаков препинания и пробелов. Не более 1000 символов.
Данные на выходе:  Строка из английский букв, знаков препинания и пробелов.

Пример
Данные на входе:  Cao, Cao, Cao and Cao!!!
Данные на выходе: Ling, Ling, Ling and Ling!!!
*/

#include <stdio.h>
#include <string.h>

#define SIZE 10001

void input(char *strIn)
{
    FILE *in;

    in = fopen("input.txt", "r");

    while (fscanf(in, "%[^\n]", strIn) == 1)
        ;

    fclose(in);
}

void changeName(char *strExt, char *buffer)
{
    int count = 0;

    for (int i = 0; i < strlen(strExt); i++)
    {
        if (!memcmp(strExt + i, "Cao", 3))
        {
            strcat(buffer, "Ling");
            count += 4;
            i += 3;
        }
        buffer[count++] = strExt[i];
    }
}
void output(char *strOut)
{
    FILE *out;
    out = fopen("output.txt", "w");
    fprintf(out, "%s", strOut);
    fclose(out);
}

int main(int argc, char **argv)
{
    char str[SIZE] = {0}, strFinal[SIZE] = {0};
    input(str);
    changeName(str, strFinal);
    output(strFinal);
    return 0;
}
