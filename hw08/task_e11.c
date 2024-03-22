/*
E11 ДЗ 4
Отсортировать по последней цифре.
Считать массив из 10 элементов и отсортировать его по последней цифре.

Данные на входе:  10 целых чисел через пробел
Данные на выходе: Этот же массив отсортированный по последней цифре

Пример №1
Данные на входе:  14 25 13 30 76 58 32 11 41 97
Данные на выходе: 30 11 41 32 13 14 25 76 97 58

Пример №2
Данные на входе:  109 118 100 51 62 73 1007 16 4 555
Данные на выходе: 100 51 62 73 4 555 16 1007 118 109
*/
#include <stdio.h>

void SwapArr(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Выполняет сортировку массива по последней цифре каждого числа в массиве
void SortByLastDigit(int *arr, int len)
{
    int noSwap;
    for (int i = len - 1; i >= 0; i--)
    {
        noSwap = 1;
        for (int j = 0; j < i; j++)
        {
            // Сравниваем оба числа по последней цифре
            if (arr[j] % 10 > arr[j + 1] % 10)
            {
                SwapArr(arr, j, j + 1);
                noSwap = 0;
            }
        }
        if (noSwap)
            break;
    }
}

int main()
{
    const int BUFFER_SIZE = 10;
    int buffer[BUFFER_SIZE];

    //printf("Введите %d целых чисел через пробел:\n", BUFFER_SIZE);
    for (int i = 0; i < BUFFER_SIZE; i++)
        scanf("%d", &buffer[i]);

    SortByLastDigit(buffer, BUFFER_SIZE);

    for (int i = 0; i < BUFFER_SIZE; i++)
        printf("%d ", buffer[i]);
    printf("\n");

    return 0;
}
