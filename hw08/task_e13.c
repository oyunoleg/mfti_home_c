/*
E13 ДЗ 5
Вторая с конца ноль
Считать массив из 10 элементов и отобрать в другой массив
все числа, у которых вторая с конца цифра (число десятков) – ноль.

Данные на входе:  10 целых чисел через пробел.
Данные на выходе: Целые числа через пробел, у которых вторая с конца цифра - ноль

Пример
Данные на входе:  40 105 203 1 14 1000 22 33 44 55
Данные на выходе: 105 203 1 1000
*/
#include <stdio.h>

// Выполняет добавление чисел в массив out,
// у которых вторая с конца цифра - ноль,
int Positives(int in[], int out[], int len)
{
    int count = 0, tens;
    for (int i = 0; i < len; i++)
    {
        tens = (in[i] / 10) % 10;
        if (tens == 0)
        {
            out[count] = in[i];
            count++;
        }
    }
    return count;
}

int main()
{
    const int BUFFER_SIZE = 10;
    int buffer[BUFFER_SIZE];

    //printf("Введите %d целых чисел через пробел:\n", BUFFER_SIZE);
    for (int i = 0; i < BUFFER_SIZE; i++)
        scanf("%d", &buffer[i]);

    int result[BUFFER_SIZE];
    int count = Positives(buffer, result, BUFFER_SIZE);

    for (int i = 0; i < count; i++)
        printf("%d ", result[i]);
    printf("\n");

    return 0;
}
