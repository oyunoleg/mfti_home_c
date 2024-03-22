/*
E2
Найти минимум
Ввести c клавиатуры массив из 5 элементов, найти минимальный из них.

Данные на входе:  5 целых чисел через пробел
Данные на выходе: Одно единственное целое число

Пример №1
Данные на входе:  4 15 3 10 14
Данные на выходе: 3

Пример №2
Данные на входе:  1 2 3 4 -5
Данные на выходе: -5
*/
#include <stdio.h>

// Возвращает минимальное число из элементов массива.
int sum_positive(int *arr, int len)
{
    int min = arr[0];
    for (int i = 1; i < len; i++)
    {
        if (min > arr[i])
            min = arr[i];
    }
    return min;
}

int main(int argc, char **argv)
{
    const int BUFFER_SIZE = 5;
    int buffer[BUFFER_SIZE];
    // printf("Введите %d целых чисел через пробел:\n", BUFFER_SIZE);
    for (int i = 0; i < BUFFER_SIZE; i++)
        scanf("%d", &buffer[i]);

    int res = sum_positive(buffer, BUFFER_SIZE);
    printf("%d\n", res);
    return 0;
}
