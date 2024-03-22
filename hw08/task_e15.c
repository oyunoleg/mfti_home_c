/*
E15 Практик 3
Положительные и отрицательные
Считать 10 чисел в диапазоне от -500 до 500 и разложить
по двум массивам: в одни помещать только положительные,
во второй - только отрицательные.
Числа, равные нулю, игнорировать.
Вывести на экран все элементы обоих массивов.

Данные на входе:  10 целых чисел через пробел.
Данные на выходе: Сперва положительные числа, потом отрицательыне числа,
через пробел.

Пример
Данные на входе:  5 -4 0 1 4 -3 -3 3 0 2
Данные на выходе: 5 1 4 3 2 -4 -3 -3
*/
#include <stdio.h>

const int LIMIT = 500; // Ограничение чисел по условию

int Positives(int in[], int out[], int len)
{
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (in[i] > 0 && in[i] <= LIMIT)
        {
            out[count] = in[i];
            count++;
        }
    }
    return count;
}

int Negatives(int in[], int out[], int len)
{
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (in[i] < 0 && in[i] >= -LIMIT)
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

    int positives[BUFFER_SIZE];
    int count = Positives(buffer, positives, BUFFER_SIZE);
    for (int i = 0; i < count; i++)
        printf("%d ", positives[i]);

    int negatives[BUFFER_SIZE];
    count = Negatives(buffer, negatives, BUFFER_SIZE);    
    for (int i = 0; i < count; i++)
        printf("%d ", negatives[i]);
    printf("\n");

    return 0;
}
