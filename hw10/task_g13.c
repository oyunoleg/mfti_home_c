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

void changeFileExtension(char *filename, char *new_extension)
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

    // Чтение строки из входного файла в массив
    if ((fp = fopen(INPUT_FILE, "r")) == NULL)
    {
        perror("Error occured while opening input file!");
        return 1;
    }
    fscanf(fp, "%[^\n]", filename);
    fclose(fp);

    // Запись в выходной файл
    if ((fp = fopen(OUTPUT_FILE, "w")) == NULL)
    {
        perror("Error occured while opening output file!");
        return 1;
    }

    // Задаем расширение файла
    changeFileExtension(filename, ".html");

    fprintf(fp, "%s", filename);
    fclose(fp);

    return 0;
}
