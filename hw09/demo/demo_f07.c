/*
F7 Демо 2
Упаковать 0 и 1
Написать функцию и программу, демонстрирующую работу данной функции,
которая сжимает серии массива, состоящего из единиц и нулей
по следующему принципу: например, массив [0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1]
преобразуется в [4,7,2,4] (т.к. начинается с нуля, то сразу записывается количество элементов первой серии); а массив [1,1,1,0,0,0,0,0,0,0] преобразуется в [0,3,7] (т.к. первая серия - это единицы, то первый элемент преобразованного массива 0).
<p> </p>
Необходимо реализовать только одну функцию, всю программу загружать не надо. Прототип функции:
 int compression(int a[], int b[], int N)

Данные на входе: 		Функция принимает исходный массив a[] и сжимает в массив b[], N - число элементов в массиве a[].
Данные на выходе: 	Функция возвращает число элементов сжатого массива b[]


Пример №1
Данные на входе: 		1 1 0 0 1 1 1 0 1 1 0 0 1 0 1 0 0 1 0 0 0 0 1 1 1 1 0 1 0 0 0 0 1 1 1 0 1 1 0 1 0 0 0 1 1 0 0 1 0 0 0 1 0 0 1 1 1 0 1 0 0 0 0 0 0 1 0 1 0 0 1 1 0 1 0 0 0 0 1 0 0 1 1 0 1 0 0 0 1 0 1 1 1 1 1 1 0 1 0 0
Данные на выходе: 	[0,2,2,3,1,2,2,1,1,1,2,1,4,4,1,1,4,3,1,2,1,1,3,2,2,1,3,1,2,3,1,1,6,1,1,1,2,2,1,1,4,1,2,2,1,1,3,1,1,6,1,1,2]

Пример №2
Данные на входе: 		0 0 1 0 0 1 1 0 0 1 1 0 1 0 0 1 1 0 1 0 1 1 1 1 0 1 1 1 1 0 0 0 0 1 1 0 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 1 0 0 0 0 1 0 1 0 0 0 1 0 1 1 1 1 1 0 1 0 1 1 1 0 0 0 1 0 1 1 1 1 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1
Данные на выходе: 	[2,1,2,2,2,2,1,1,2,2,1,1,1,4,1,4,4,2,2,1,1,1,1,3,1,1,1,2,1,3,4,1,1,1,3,1,1,5,1,1,1,3,3,1,1,4,1,3,2,4,1,1,1,2]
*/
#include <stdio.h>

int Input(int arr[], int n)
{
    int i, num;
    while (scanf("%d", &num) == 1)
        arr[i++] = num;
    return i;
}

int countZeroOne(int len, int *arr, int *out)
{
    int countNumbers = 1, countOut = 0;
    if (arr[0] == 1)
        out[countOut++] = 0;
    for (int i = 0; i < len - 1; i++)
    {
        if (arr[i] == arr[i + 1])
            countNumbers++;
        else
        {
            out[countOut++] = countNumbers;
            countNumbers = 1;
        }
    }
    out[countOut++] = countNumbers;
    return countOut;
}

void PrintZeroOne(int len, int *out)
{
    printf("[%d", out[0]);
    for (int i = 1; i < len; i++)
        printf(",%d", out[i]);
    printf("]");
}

int main()
{
    enum
    {
        SIZE = 100
    };
    int in[SIZE];
    int out[SIZE];
    Input(in, SIZE);
    int count = countZeroOne(SIZE, in, out);
    PrintZeroOne(count, out);
    return 0;
}
