/*
E1 ДЗ 1
Среднее арифметическое чисел
Ввести c клавиатуры массив из 5 элементов, найти среднее арифметическое
всех элементов массива.

Данные на входе:  5 целых ненулевых чисел через пробел
Данные на выходе: Одно число в формате "%.3f"

Пример №1
Данные на входе:  4 15 3 10 14
Данные на выходе: 9.200

Пример №2
Данные на входе:  1 2 3 4 5
Данные на выходе: 3.000
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
    return sum / len;
}

int main(int argc, char **argv)
{
    const int BUFFER_SIZE = 5;
    int buffer[BUFFER_SIZE];
    //printf("Введите %d целых чисел через пробел:\n", BUFFER_SIZE);
    for (int i = 0; i < BUFFER_SIZE; i++)
        scanf("%d", &buffer[i]);

    float avg = Average(buffer, BUFFER_SIZE);
    printf("%.3f\n", avg);
    return 0;
}
