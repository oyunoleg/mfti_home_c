/*
E6
Среднее арифметическое массива
Считать массив из 12 элементов и подсчитать
среднее арифметическое элементов массива.

Данные на входе: 	12 целых чисел через пробел
Данные на выходе: 	Среднее арифметическое в формате "%.2f"

Пример №1
Данные на входе: 	4 -5 3 10 -4 -6 8 -10 1 0 5 7
Данные на выходе: 	1.08

Пример №2
Данные на входе: 	1 2 3 4 5 6 7 8 9 10 11 12
Данные на выходе: 	6.50
*/
#include <stdio.h>

// Возвращает среднее арифметическое элементов массива.
float Average(int *arr, int len)
{
    float sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += arr[i];
    }
    return sum / (len == 0 ? 1 : len);
}

int main(int argc, char **argv)
{
    const int BUFFER_SIZE = 12;
    int buffer[BUFFER_SIZE];
    //printf("Введите %d целых чисел через пробел:\n", BUFFER_SIZE);
    for (int i = 0; i < BUFFER_SIZE; i++)
        scanf("%d", &buffer[i]);

    float res = Average(buffer, BUFFER_SIZE);
    printf("%.2f\n", res);

    return 0;
}
