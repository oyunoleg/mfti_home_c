/*
G8 ДЗ 3
Числа в массив
В файле .txt дана строка, не более 1000 символов, содержащая буквы,
целые числа и иные символы.
Требуется все числа, которые встречаются в строке, поместить в отдельный целочисленный массив.
Например, если дана строка "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0.
Вывести массив по возрастанию в файл .txt.

Данные на входе: 	Строка из английских букв, цифр и знаков препинания
Данные на выходе: 	Последовательность целых чисел отсортированная по возрастанию

Пример
Данные на входе: 	data 48 call 9 read13 blank0a
Данные на выходе: 	0 9 13 48
*/
#include <stdio.h>
#include <stdlib.h>

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

// Добавляет все числа, которые встречаются в строке, в int-массив.
int parse_numbers(char arr[], int out[])
{
    char *pchar = &arr[0];
    int number, count = 0;
    while (*pchar != '\0')
    {
        // Если встретился символ - цифра 0-9
        if (*pchar >= '0' && *pchar <= '9')
        {
            // Преобразование в число из остатка строки
            // от этой цифры до НЕцифры
            number = atoi(pchar);
            out[count++] = number;
            // Обязательно пропускаем все цифры в number чтобы не повторялись!
            while (number != 0)
            {
                pchar++;
                number /= 10;
            }
        }
        pchar++;
    }
    return count;
}

void sort_array(int size, int arr[])
{
    int temp;
    for (int i = 0; i < size; ++i)
    {
        for (int j = size - 1; j > i; --j)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(void)
{
    FILE *fp;
    char str[MAX_LENGTH] = {0};
    int numbers[MAX_LENGTH] = {0};
    int num_count = 0;

    // Чтение строки из входного файла в line массив
    if ((fp = try_open_file(INPUT_FILE, "r")) == NULL)
        return 1;
    fscanf(fp, "%[^\n]", str);
    fclose(fp);

    // Все числа в int-массив
    num_count = parse_numbers(str, numbers);
    sort_array(num_count, numbers);

    // Запись в выходной файл
    if ((fp = try_open_file(OUTPUT_FILE, "w")) == NULL)
        return 1;

    for (int i = 0; i < num_count; ++i)
        fprintf(fp, "%d ", numbers[i]);
    fclose(fp);

    return 0;
}
