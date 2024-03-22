/*
E7 Практик 2
Инверсия половинок
Считать массив из 10 элементов и выполнить инверсию
отдельно для 1-ой и 2-ой половин массива.
Необходимо изменить считанный массив и напечатать его одним циклом.

Данные на входе: 	10 целых элементов массива через пробел.
Данные на выходе: 	10 целых элементов массива через пробел.

Пример №1
Данные на входе: 	4 -5 3 10 -4 -6 8 -10 1 0
Данные на выходе: 	-4 10 3 -5 4 0 1 -10 8 -6

Пример №2
Данные на входе: 	1 2 3 4 5 6 7 8 9 10
Данные на выходе: 	5 4 3 2 1 10 9 8 7 6
*/
#include <stdio.h>

void aPrint(int *arr, int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
}

void reverseArray(int *arr, int len)
{
    for (int i = 0, j = len - 1; i < j; i++, j--)
    {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}

int main()
{
    const int BUFFER_SIZE = 10;
    int buffer[BUFFER_SIZE];
    //printf("Введите %d целых чисел через пробел:\n", BUFFER_SIZE);
    for (int i = 0; i < BUFFER_SIZE; i++)
        scanf("%d", &buffer[i]);

    for (int i = 0; i < 2; i++)
        reverseArray(buffer + i * BUFFER_SIZE / 2, BUFFER_SIZE / 2);

    for (int i = 0; i < BUFFER_SIZE; i++)
        printf("%d ", buffer[i]);
    printf("\n");

    return 0;
}