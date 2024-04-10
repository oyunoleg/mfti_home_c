/*
G20 Практ 2
Проверка на палиндром
Считать предложение из файла .txt и определить можно ли из английских
букв предложения записанного в файле получить одно слово - палиндром.
Ответ напечатать на стандартный поток вывода.
Требуется реализовать логическую функцию и применить ее.

 is_palindrom(string)

Данные на входе: 	Строка из маленьких английских букв и пробелов.
Не более 1000 символов.
Данные на выходе: 	YES или NO

Пример №1
Данные на входе: 	kak za
Данные на выходе: 	YES

Пример №2
Данные на входе: 	abc
Данные на выходе: 	NO

Пример №3
Данные на входе: 	car race
Данные на выходе: 	YES
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1001
const char *INPUT_FILE = "input.txt";

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

void remove_spaces(char *str)
{
    int count = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != ' ')
            str[count++] = str[i];
    }
    str[count] = '\0';
}

void bubble_sort(int size, char *array)
{
    char buf;
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (array[i] > array[j])
            {
                buf = array[i];
                array[i] = array[j];
                array[j] = buf;
            }
}

int is_palindrom(char line[])
{
    // printf("%s\n", line);
    remove_spaces(line);
    const int size = strlen(line);
    char letters[size][2];
    int letters_count = 0;
    int idx = 0;

    bubble_sort(size, line);

    for (int i = 0; i < size; i++)
    {
        idx = -1;
        for (int j = 0; j < letters_count; j++)
        {
            if (line[i] == letters[j][0])
            {
                idx = j;
                letters[idx][1]++;
                break;
            }
        }
        if (idx < 0)
        {
            idx = letters_count++;
            letters[idx][0] = line[i];
            letters[idx][1] = 1;
        }
    }

    int p_length = 0;
    int l_length, m_p = -1;
    for (int i = 0; i < letters_count; i++)
    {
        while (letters[i][1] && (letters[i][1] / 2 > 0))
        {
            line[p_length++] = letters[i][0];
            letters[i][1] -= 2;
        }
        if ((m_p < 0) && (letters[i][1] % 2 == 1))
            m_p = i;
    }
    l_length = p_length;
    if (m_p >= 0)
        line[p_length++] = letters[m_p][0];
    for (int i = l_length - 1; i >= 0; i--)
        line[p_length++] = line[i];
    line[p_length] = '\0';

    // printf("%s\n", line);
    return (size == strlen(line)) ? 1 : 0;
}

int main(void)
{
    char str[MAX_LENGTH] = {0};
    input(str);
    (is_palindrom(str)) ? printf("YES\n") : printf("NO\n");

    return 0;
}
