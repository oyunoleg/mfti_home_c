/*
E5
Сумма положительных элементов
Считать массив из 10 элементов и подсчитать сумму
положительных элементов массива.

Данные на входе:  10 целых чисел через пробел
Данные на выходе: Одно целое число - сумма положительных элементов массива

Пример №1
Данные на входе:  4 -5 3 10 -4 -6 8 -10 1 0
Данные на выходе: 26

Пример №2
Данные на входе:  1 -2 3 -4 5 -6 7 -8 9 0
Данные на выходе: 25
*/
#include <stdio.h>

// Возвращает сумму положительных элементов массива.
int sum_positive(int *arr, int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] > 0)
            sum += arr[i];
    }
    return sum;
}

int main(int argc, char **argv)
{
    const int BUFFER_SIZE = 10;
    int buffer[BUFFER_SIZE];
    //printf("Введите %d целых чисел через пробел:\n", BUFFER_SIZE);
    for (int i = 0; i < BUFFER_SIZE; i++)
        scanf("%d", &buffer[i]);

    int res = sum_positive(buffer, BUFFER_SIZE);
    printf("%d\n", res);
    return 0;
}
