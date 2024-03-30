/*
F17
След матрицы
Написать функцию и программу, демонстрирующую работу данной функции,
которая находит след матрицы в двумерном массиве.
Показать пример ее работы на матрице из 5 на 5 элементов.
След матрицы - это сумма элементов на главной диагонали.

Данные на входе: 	25 целых чисел через пробел.
Данные на выходе: 	Одно целое число.

Пример
Данные на входе:
1 1 1 1 1
2 2 2 2 2
3 3 3 3 3
4 4 4 4 4
5 5 5 5 5
Данные на выходе: 	15
*/
#include <stdio.h>

#define SIZE 5

int avgOfMatrixTrace(int matrix[SIZE][SIZE])
{
    int sum = 0;
    for (int i = 0; i < SIZE; ++i)
    {
        sum += matrix[i][i];
    }

    return sum;
}

int main(void)
{
    int matrix[SIZE][SIZE];

    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
            scanf("%d", &matrix[i][j]);
    }

    int sum = avgOfMatrixTrace(matrix);
    printf("%d\n", sum);

    return 0;
}
