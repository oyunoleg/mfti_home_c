/*
F14
Сумма в интервале
Написать функцию и программу, демонстрирующую работу данной функции,
которая возвращает сумму элементов в заданном отрезке [from, to] для массива.
Прототип функции
int sum_between_ab(int from, int to, int size, int a[])

Данные на входе: 	Функция принимает концы отрезка from и to, размер массива, массив целых чисел
Функция возвращает сумму элементов в интервале [from, to]

Пример №1
Данные на входе: 	4 6 1 2 3 4 5 6 7 8 9 10
Данные на выходе: 	15

Пример №2
Данные на входе: 	6 4 1 2 3 4 5 6 7 8 9 10
Данные на выходе: 	15

Примечание — Интервал 4 6 числа 4 5 6 к-во 3 сумма 15
*/
#include <stdio.h>

#define SIZE 12

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

int sum_between_ab(int from, int to, int size, int a[])
{

    // Обязательная проверка  параметров:
    if (from > to) {
        int temp = from;
        from = to;
        to = temp;
    }

    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        // Если такое же число еше не встречалось
        if (hasEqualsBefore(a, i) == 0)
        {
            if (a[i] >= from && a[i] <= to)
                sum += a[i];
        }
    }
    return sum;
}

/*
int main(void)
{
    int arr[SIZE] = {60, 50, 89, 71, 6, 40, 61, 75, 53, 64, 79, 97};

    //for (int i = 0; i < SIZE; i++)
    //   scanf("%d", &arr[i]);

    int sum = sum_between_ab(59, 51, SIZE, arr);
    printf("%d\n", sum);

    return 0;
}
*/

