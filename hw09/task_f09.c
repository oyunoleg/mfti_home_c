/*
F9
Поменять местами
Написать функцию и программу, демонстрирующую работу данной функции,
которая в массиве находит максимальный из отрицательных элементов
и меняет его местами с последним элементом массива.
Гарантируется, что в массиве только один такой элемент или же такой элемент отсутствует.
Если отрицательных элементов нет - массив не менять.

Прототип функции:
void swap_negmax_last(int size, int a[])

Данные на входе: 		Функция принимает на вход размер массива и указатель на начало массива. Массив состоит из целых чисел.

Пример
Данные на входе: 	1 -2 -3 -4 5 6 7 8 9 10
Данные на выходе: 	1 10 -3 -4 5 6 7 8 9 -2
*/
#include <stdio.h>
#include <limits.h>

#define SIZE 10

void swap_negmax_last(int size, int a[])
{
    int maxNegative = INT_MIN, maxNegativePos = -1;

    for (int i = 0; i < size; ++i)
    {
        // Для всех отрицательных чисел в массиве
        if (a[i] < 0)
        {
            // находим максимальное число и его индекс
            if (maxNegative < a[i])
            {
                maxNegative = a[i];
                maxNegativePos = i;
            }
        }
    }

    // Если найдено мвксимальное число то меняем его с последним элементом
    if (maxNegativePos >= 0)
    {
        int temp = a[size - 1];
        a[size - 1] = a[maxNegativePos];
        a[maxNegativePos] = temp;
    }
}

int main(void)
{
    int arr[SIZE] = {1, -2, -3, -4, 5, 6, 7, 8, 9, 10};
    // for (int i = 0; i < SIZE; i++)
    //     scanf("%d", &arr[i]);

    swap_negmax_last(SIZE, arr);

    for (int i = 0; i < SIZE; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
