/*
E8 Демо 2
Инверсия каждой трети
Считать массив из 12 элементов и выполнить инверсию для каждой трети массива.

Данные на входе: 		12 целых чисел через пробел
Данные на выходе: 	12 целых чисел через пробел

Пример №1
Данные на входе: 		4 -5 3 10 -4 -6 8 -10 1 0 5 7
Данные на выходе: 	10 3 -5 4 -10 8 -6 -4 7 5 0 1

Пример №2
Данные на входе: 		1 2 3 4 5 6 7 8 9 10 11 12
Данные на выходе: 	4 3 2 1 8 7 6 5 12 11 10 9
*/
#include <stdio.h>

void aPrint(int *arr, int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
}

void Reverse(int *array, int num)
{
    for (int i = 0, j = num - 1; i < j; i++, j--)
    {
        int t = array[i];
        array[i] = array[j];
        array[j] = t;
    }
}

int main()
{
    enum
    {
        aSize = 12
    };
    int array[aSize] = {0};
    for (int i = 0; i < aSize; i++)
        scanf("%d", &array[i]);
    for (int i = 0; i < 3; i++)
        Reverse(array + i * aSize / 3, aSize / 3);

    aPrint(array, aSize);
    return 0;
}