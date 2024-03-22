/*
E12
По убыванию и по возрастанию
Считать массив из 10 элементов и отсортировать первую половину
по возрастанию, а вторую – по убыванию.

Данные на входе:  10 целых чисел через пробел
Данные на выходе: Исходный массив. Первая часть отсортирована по возрастанию, вторая половина по убыванию.

Пример №1
Данные на входе:  14 25 13 30 76 58 32 11 41 97
Данные на выходе: 13 14 25 30 76 97 58 41 32 11

Пример №2
Данные на входе:  5 4 3 2 1 6 7 8 9 10
Данные на выходе: 1 2 3 4 5 10 9 8 7 6
*/
#include <stdio.h>

void SwapArr(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Выполняет сортировку массива по возрастанию либо по убыванию (если descending  >= 1)
void BubbleSort(int *arr, int len, int descending)
{
    int noSwap;
    for (int i = len - 1; i >= 0; i--)
    {
        noSwap = 1;
        for (int j = 0; j < i; j++)
        {
            if ((arr[j] > arr[j + 1] && descending <= 0)    // если по возрастанию
                || (arr[j] < arr[j + 1] && descending > 0)) // либо по убыванию
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

    // printf("Введите %d целых чисел через пробел:\n", BUFFER_SIZE);
    for (int i = 0; i < BUFFER_SIZE; i++)
        scanf("%d", &buffer[i]);

    // Сортировка первой половины массива по возрастанию (просто половиним размер массива)
    BubbleSort(buffer, BUFFER_SIZE / 2, 0);

    // Сортировка второй половины массива по убыванию (смешаем указатель на 1й элемент на +5)
    BubbleSort(buffer + BUFFER_SIZE / 2, BUFFER_SIZE / 2, 1);

    for (int i = 0; i < BUFFER_SIZE; i++)
        printf("%d ", buffer[i]);
    printf("\n");

    return 0;
}