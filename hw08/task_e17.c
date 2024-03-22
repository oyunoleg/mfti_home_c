/*
 E17
Только один раз
Дан массив из 10 элементов.
В массиве найти элементы, которые в нем встречаются только один раз, и вывести их на экран.

Данные на входе:  10 целых чисел через пробел
Данные на выходе: Элементы которые встречаются только один раз через пробел

Пример
Данные на входе:  5 -4 0 1 4 -3 -3 3 0 2
Данные на выходе: 5 -4 1 4 3 2
*/
#include <stdio.h>

// Выполняет добавление чисел в массив out[],
// которые встречаются только один раз в массиве in[].
int Uniques(int in[], int out[], int len)
{
    int uniqueCount = 0; // Количество всех уникальных чисел
    int isUnique;        // Флаг: 1 для уникального числа иначе 0

    for (int i = 0; i < len; i++)
    {
        isUnique = 1;

        // Если число не уникально, то обнуляем его isUnique и прерываем
        for (int j = 0; j < len; j++)
        {
            if (i != j && in[i] == in[j])
            {
                isUnique = 0;
                break;
            }
        }

        // Добавляем в out массив только унмкальное число
        if (isUnique == 1)
            out[uniqueCount++] = in[i];
    }

    return uniqueCount;
}

int main()
{
    const int BUFFER_SIZE = 10;
    int buffer[BUFFER_SIZE];

    //printf("Введите %d целых чисел через пробел:\n", BUFFER_SIZE);
    for (int i = 0; i < BUFFER_SIZE; i++)
        scanf("%d", &buffer[i]);

    int out[BUFFER_SIZE];
    int count = Uniques(buffer, out, BUFFER_SIZE);
    for (int i = 0; i < count; i++)
        printf("%d ", out[i]);
    printf("\n");

    return 0;
}
