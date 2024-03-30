/*
F13
В заданном интервале
Написать функцию и программу, демонстрирующую работу данной функции,
которая возвращает количество элементов на заданном отрезке [from, to] для массива.
Прототип функции
int count_between(int from, int to, int size, int a[])

Данные на входе:	Функция принимает значения концов отрезка from и to, размер массива, массив целых чисел.
Данные на выходе: 	Функция возвращает целое число - количество чисел в интервале [from, to]

Пример
Данные на входе:	4 6 1 2 3 4 5 6 7 8 9 10
Данные на выходе: 	3

Примечание — Интервал 4 6 числа 4 5 6 к-во 3
*/
#include <stdio.h>

#define SIZE 12

// Возвращает 1 если в начале массива уже имеютсф дубликаты числа с индексом posNum
int hasEqualsBefore(int arr[], int posNum)
{
    for (int i = posNum - 1; i >= 0; --i)
    {
        if (arr[i] == arr[posNum])
        {
            return 1;
        }
    }
    return 0;
}

// Возвращает количество элементов на заданном отрезке без учета дубликатов.
int count_between(int from, int to, int size, int a[])
{

    // Обязательная проверка  параметров:
    if (from > to) {
        int temp = from;
        from = to;
        to = temp;
    }

    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        // Если такое же число еше не встречалось
        if (hasEqualsBefore(a, i) == 0)
        {
            if (a[i] >= from && a[i] <= to)
                count++;
        }
    }
    return count;
}

/*
int main(void)
{
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++)
        scanf("%d", &arr[i]);

    int count = count_between(4, 6, SIZE, arr);
    printf("%d\n", count);

    return 0;
}
*/

