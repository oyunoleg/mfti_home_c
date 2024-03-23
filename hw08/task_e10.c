/*
E10 ДЗ 3
Циклический сдвиг массива вправо на 4
Считать массив из 12 элементов и выполнить циклический
сдвиг ВПРАВО на 4 элемента.

Данные на входе:  12 целых чисел через пробел
Данные на выходе: 12 целых чисел через пробел

Пример №1
Данные на входе:  4 -5 3 10 -4 -6 8 -10 1 0 5 7
Данные на выходе: 1 0 5 7 4 -5 3 10 -4 -6 8 -10

Пример №2
Данные на входе:  1 2 3 4 5 6 7 8 9 10 11 12
Данные на выходе: 9 10 11 12 1 2 3 4 5 6 7 8
*/
#include <stdio.h>

// Выполняет циклический сдвиг массива вправо на N.
void ShiftRight(int *arr, int len, int n)
{
    int temp[n];

    // Скопируем N последних  элемента 
    for (int i = (len - n), j = 0; i < len; i++, j++)
        temp[j] = arr[i];
    
    // Переместим вправо 
    for (int i = len - 1; i >= 0; i--)
        arr[i] = arr[i - n];    

    // заполнм первые N элементов из временного массива
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];    
}

int main(int argc, char **argv)
{
    const int BUFFER_SIZE = 12;
    int buffer[BUFFER_SIZE];
    //printf("Введите %d целых чисел через пробел:\n", BUFFER_SIZE);
    for (int i = 0; i < BUFFER_SIZE; i++)
        scanf("%d", &buffer[i]);

    ShiftRight(buffer, BUFFER_SIZE, 4);

    for (int i = 0; i < BUFFER_SIZE; i++)
        printf("%d ", buffer[i]);
    printf("\n");

    return 0;
}
