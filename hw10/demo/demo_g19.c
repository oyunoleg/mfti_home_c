/*
G19 Демо 2
Составить палиндром
Разработать функцию дана строка из маленьких английских букв. Составить из символов палиндром максимальной длинны. При составлении палиндрома буквы в палиндроме должны быть расположены в лексикографическом порядке. Записать ответ в файл .txt.

Данные на входе: 	Строка из маленьких английских букв. Не более 1000 символов.
Данные на выходе: 	Строка из маленьких английских букв.

Пример №1
Данные на входе: 	kazaki
Данные на выходе: 	akika

Пример №2
Данные на входе: 	knak
Данные на выходе: 	kak

Пример №3
Данные на входе: 	zzzzbbaaa
Данные на выходе: 	abzzazzba
*/
#include <stdio.h>
#define ALPHABET 26
int main()
{
    FILE *f_in = fopen("input.txt", "r");
    FILE *f_out = fopen("output.txt", "w");

    char str[1002];
    int odd;
    int a[ALPHABET] = {0};

    fgets(str, 1002, f_in);

    for (int i = 0; str[i] != '\n' && str[i]; ++i)
        a[str[i] - 'a']++;

    for (int i = 0; i < ALPHABET; ++i)
        if (a[i] % 2 != 0)
        {
            odd = i;
            break;
        }

    for (int i = 0; i < ALPHABET; ++i)
        if (a[i] > 0)
            for (int j = 0; j < a[i] / 2; ++j)
                fprintf(f_out, "%c", i + 'a');

    fprintf(f_out, "%c", odd + 'a');

    for (int i = ALPHABET - 1; i >= 0; --i)
        if (a[i] > 0)
            for (int j = 0; j < a[i] / 2; ++j)
                fprintf(f_out, "%c", i + 'a');
    fclose(f_in);
    fclose(f_out);
    return 0;
}

#include <stdio.h>
#include <string.h>

const int line_width = 1024;

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

void make_palindrome(int size, char *line)
{
    char letters[size][2];
    int letters_count = 0;
    int idx = 0;

    bubble_sort(strlen(line), line);

    for (int i = 0; i < size; i++)
    {
        idx = -1;
        for (int j = 0; j < letters_count; j++)
            if (line[i] == letters[j][0])
            {
                idx = j;
                letters[idx][1]++;
                break;
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

    make_palindrome(strlen(line), line);

    fp = fopen(output_fn, "w");
    fprintf(fp, "%s", line);
    fclose(fp);

    return 0;
}
