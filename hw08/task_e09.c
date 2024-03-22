/*
E9
Циклический сдвиг массива вправо.
Считать массив из 10 элементов и выполнить циклический сдвиг ВПРАВО на 1.

Данные на входе:  10 целых чисел через пробел
Данные на выходе: 10 целых чисел через пробел сдвинутых
вправо на 1 элемент циклически

Пример №1
Данные на входе:  4 -5 3 10 -4 -6 8 -10 1 0
Данные на выходе: 0 4 -5 3 10 -4 -6 8 -10 1

Пример №2
Данные на входе:  1 2 3 4 5 6 7 8 9 10
Данные на выходе: 10 1 2 3 4 5 6 7 8 9
*/
#include <stdio.h>

// Выполняет циклический сдвиг массива вараво на 1 элемент.
void ShiftRight(int *arr, int len)
{
    int temp = arr[len - 1];
    for (int i = len - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}

int main()
{
    const int BUFFER_SIZE = 10;
    int buffer[BUFFER_SIZE];
    //printf("Введите %d целых чисел через пробел:\n", BUFFER_SIZE);
    for (int i = 0; i < BUFFER_SIZE; i++)
        scanf("%d", &buffer[i]);

    ShiftRight(buffer, BUFFER_SIZE);

    for (int i = 0; i < BUFFER_SIZE; i++)
        printf("%d ", buffer[i]);
    printf("\n");

    return 0;
}
