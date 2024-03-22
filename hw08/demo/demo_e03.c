/*
E3 Практик 1 решено на лекции
Максимум и минимум
Считать массив из 10 элементов и найти в нем
максимальный и минимальный элементы и их номера.

Данные на входе:  10 целых чисел через пробел
Данные на выходе: 4 целых числа через пробел:
номер максимума, максимум, номер минимума, минимум.

Пример №1
Данные на входе:  4 -5 3 10 -4 -6 8 -10 1 0
Данные на выходе: 4 10 8 -10

Пример №2
Данные на входе:  1 2 3 4 5 6 7 8 9 10
Данные на выходе: 10 10 1 1
*/
// Эта программа определяет МАКСИМАЛЬНЫЙ и минимальный элементы массива
#include <stdio.h>  //объявление библиотеки ввода-вывода
#include <string.h> //объявление библиотеки обработки строк
#include <math.h>   //объявление математической библиотеки

int Input(int arr[], int n) // описание функции ввода
{
    int i;
    for (i = 0; i < n; i++) // ввод массива
        scanf("%d", &arr[i]);
    return i;
}

int Min(int arr[], int len) // описание функции Min
{
    int min = arr[0], i;
    for (i = 1; i < len; i++)
        if (min > arr[i])
            min = arr[i];
    return min; // возврат результата
}

int Max(int arr[], int len) // описание функции Max
{
    int max = arr[0], i;
    for (i = 1; i < len; i++)
        if (max < arr[i])
            max = arr[i];
    return max; // возврат результата
}

int PosMin(int *arr, int len) // описание функции PosMin
{
    int min = arr[0], i, p_m = 1;
    for (i = 1; i < len; i++)
        if (min > arr[i])
        {
            min = arr[i];
            p_m = i + 1;
        }
    return p_m; // возврат результата
}

int PosMax(int *arr, int len) // описание функции PosMax
{
    int max = arr[0], i, p_M = 1;
    for (i = 1; i < len; i++)
        if (max < arr[i])
        {
            max = arr[i];
            p_M = i + 1;
        }
    return p_M; // возврат результата
}

int main(int argc, char **argv)
{
    enum
    {
        BUFFER_SIZE = 10
    };                                          // указание количества элементов массива
    int buffer[BUFFER_SIZE];                    // объявление массива
    Input(buffer, BUFFER_SIZE);                 // вызов функции Input
    printf("%d ", PosMax(buffer, BUFFER_SIZE)); // вывод в консоль
    printf("%d ", Max(buffer, BUFFER_SIZE));    // вывод в консоль
    printf("%d ", PosMin(buffer, BUFFER_SIZE)); // вывод в консоль
    printf("%d ", Min(buffer, BUFFER_SIZE));    // вывод в консоль
    return 0;                                   // завершить программу успешно
}
