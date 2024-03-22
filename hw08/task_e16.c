/*
E16 Д3 6
Чаще других
Дан массив из 10 элементов. Определить, какое число в массиве
встречается чаще всего. Гарантируется, что такое число ровно 1.

Данные на входе:  10 целых числе через пробел
Данные на выходе: Одно число, которое встречается чаще других.

Пример
Данные на входе:  4 1 2 1 11 2 34 11 0 11
Данные на выходе: 11
*/
#include <stdio.h>

// Возвращает число в массиве встречается чаще других.
int mostFrequent(int arr[], int len)
{
    int maxCount = 0;     // Максимальное количество вхождений
    int mostFrequent = 1; // Наиболее часто встречающееся число
    int count;            // Счетчик вхождений текущего элемента

    for (int i = 0; i < len; i++)
    {
        count = 1; // Начинаем подсчет с 1, так как текущий элемент уже встречается
        for (int j = i + 1; j < len; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }

        // Если текущее число встречается чаще, обновляем значения
        if (count > maxCount)
        {
            maxCount = count;
            mostFrequent = arr[i];
        }
    }

    return mostFrequent;
}

int main()
{
    const int BUFFER_SIZE = 10;
    int buffer[BUFFER_SIZE];

    //printf("Введите %d целых чисел через пробел:\n", BUFFER_SIZE);
    for (int i = 0; i < BUFFER_SIZE; i++)
        scanf("%d", &buffer[i]);

    int count = mostFrequent(buffer, BUFFER_SIZE);
    printf("%d\n", count);

    return 0;
}
