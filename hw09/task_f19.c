/*
F19 ДЗ 6
Больше среднего
Написать функцию и программу, демонстрирующую работу данной функции.
Определить количество положительных элементов квадратной матрицы,
превышающих по величине среднее арифметическое всех элементов главной диагонали.
Реализовать функцию среднее арифметическое главной диагонали.

Данные на входе: 	5 строк по 5 целых чисел через пробел
Данные на выходе: 	Одно целое число

Пример
Данные на входе: 	1 1 1 1 1 2 2 2 2 2 3 3 3 3 3 4 4 4 4 4 5 5 5 5 5
Данные на выходе: 	10
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

    return sum / SIZE;
}

int countOverTraceAverage(int matrix[SIZE][SIZE])
{
    int count = 0;
    int averageOfTrace = avgOfMatrixTrace(matrix);

    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if (matrix[i][j] > 0 && matrix[i][j] > averageOfTrace)
                count++;
        }
    }

    return count;
}

int main(void)
{
    int matrix[SIZE][SIZE];

    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
            scanf("%d", &matrix[i][j]);
    }

    int sum = countOverTraceAverage(matrix);
    printf("%d\n", sum);

    return 0;
}
