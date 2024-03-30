/*
F15
Больше по модулю
Написать функцию и программу, демонстрирующую работу данной функции,
которая определяет в массиве, состоящем из положительных и отрицательных чисел,
сколько элементов превосходят по модулю максимальный элемент.
Прототип функции
int count_bigger_abs(int n, int a[]);

Данные на входе:	Функция получает размер массива и массив целых чисел
Данные на выходе: 	Функция возвращает целое число раное количеству элементов
превосходящих по модулю максимальный элемент.

Пример
Данные на входе: 	1 -20 3 4 -50 6 7 8 9 10
Данные на выходе: 	2
*/
#include <stdio.h>

#define SIZE 10

int maxArray(int size, int arr[])
{
    int max = arr[0];
    for (int i = 1; i < size; ++i)
    {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}

int count_bigger_abs(int n, int a[])
{
    int count = 0, value;
    int max = maxArray(n, a);

    for (int i = 0; i < n; ++i)
    {
        value = a[i] < 0 ? -a[i] : a[i];
        if (value > max)
            count++;
    }
    return count;
}

int main0(void)
{
    int arr[SIZE] = {1, -20, 3, 4, -50, 6, 7, 8, 9, 10};

    // for (int i = 0; i < SIZE; i++)
    //   scanf("%d", &arr[i]);

    int count = count_bigger_abs(SIZE, arr);
    printf("%d\n", count);

    return 0;
}
