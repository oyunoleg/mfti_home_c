/*
G18
Удалить пробелы из текста
В файле .txt необходимо удалить все лишние пробелы (в начале предложения и сдвоенн/ые пробелы).
Для решения задачи разработать функцию.
Результат записать в .txt.

Данные на входе: 	Строка из английских букв, знаков препинания и пробелов.
Не более 1000 символов.
Данные на выходе: 	Строка из английских букв, знаков препинания и пробелов.


Пример
Данные на входе: 	 Hello  world!
Данные на выходе: 	Hello world!
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

// Сдвигает все элементы на одну позицию влево, удаляя пробел
void remove_spaces(char str[], int spacePosition)
{
    if (str[spacePosition] != ' ')
        return;

    int size = strlen(str), i;
    for (i = spacePosition; i < size - 1; i++)
    {
        str[i] = str[i + 1];
    }
    // Уменьшаем размер строки на 1 после сдвига влево
    str[i] = '\0';
}

// Убирает лишние пробелы.
void shrink_spaces(char str[])
{
    char space_char = ' ';
    int index = 0, len = strlen(str);
    while (index < len - 1)
    {
        if (str[index] == space_char)
        {
            if (str[index + 1] == space_char || index == 0)
            {
                // Удаляем двойные и лидирующие пробелы
                remove_spaces(str, index);
                index--;
            }
        }
        index++;
    }
}

int main(void)
{
    char str[MAX_SIZE] = {0};
    input(str);
    shrink_spaces(str);
    output(str);

    return 0;
}
