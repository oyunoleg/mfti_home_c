/*
G13
Изменить расширение
В файле .txt записан полный адрес файла (возможно, без расширения).
Необходимо изменить его расширение на ".html" и записать результат в файл .txt.

Данные на входе: 	Строка состоящая из символов: a-z, A-Z, 0-9, /
Данные на выходе: 	Исходная строка с измененным расширением.

Пример №1
Данные на входе: 	/DOC.TXT/qqq
Данные на выходе: 	/DOC.TXT/qqq.html

Пример №2
Данные на входе: 	/DOC.TXT/qqq.com
Данные на выходе: 	/DOC.TXT/qqq.html
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

void change_file_extension(char *filename, char *new_extension)
{
    int dot_index = -1;

    // Ищем позицию точки только у файла
    for (int i = strlen(filename) - 1; i >= 0; i--)
    {
        // Прерываем цикл, если уже не файл
        if (filename[i] == '/')
            break;

        if (filename[i] == '.')
        {
            dot_index = i;
            break;
        }
    }
    // Если у файла нет точки
    if (dot_index < 0)
        dot_index = strlen(filename);

    // Заменяем расширение файла
    strcpy(filename + dot_index, new_extension);
}

int main(void)
{
    FILE *fp;
    char filename[MAX_LENGTH] = {0};

    if ((fp = try_open_file(INPUT_FILE, "r")) == NULL)
        return 1;
    fscanf(fp, "%[^\n]", filename);
    fclose(fp);

    if ((fp = try_open_file(OUTPUT_FILE, "w")) == NULL)
        return 1;

    // Задаем расширение файла
    change_file_extension(filename, ".html");

    fprintf(fp, "%s", filename);
    fclose(fp);

    return 0;
}
