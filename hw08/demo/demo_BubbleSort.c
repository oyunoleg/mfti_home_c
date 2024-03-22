/*
Сортировка пузырьком
*/
#include <stdio.h>

void SwapArr(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Выполняет сортировку массива по возрастанию
void BubbleSort(int *arr, int len)
{
    int noSwap;
    for (int i = len - 1; i >= 0; i--)
    {
        noSwap = 1;
        for (int j = 0; j < i; j++)
        {
            // по убыванию: if (arr[j] < arr[j + 1]) {...}
            if (arr[j] > arr[j + 1]) 
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

    printf("Введите %d целых чисел через пробел:\n", BUFFER_SIZE);
    for (int i = 0; i < BUFFER_SIZE; i++)
        scanf("%d", &buffer[i]);

    BubbleSort(buffer, BUFFER_SIZE);

    for (int i = 0; i < BUFFER_SIZE; i++)
        printf("%d ", buffer[i]);
    printf("\n");

    return 0;
}