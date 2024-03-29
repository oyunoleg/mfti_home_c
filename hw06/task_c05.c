/*
C5 ДЗ
Сумма от 1 до N
Составить функцию, которая определяет сумму всех чисел
от 1 до N и привести пример ее использования.

Пример №1:
Данные на входе:  Одно целое положительное число N
Данные на выходе: Целое число - сумма чисел от 1 до N

Пример №2:
Данные на входе:  100
Данные на выходе: 5050
*/
#include <stdio.h>

int calc(int n)
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += i;
    }
    return res;
}

int main(void)
{
    int n;
    printf("Введите 1 произвольное целое число N:\n");
    scanf("%d", &n);

    printf("Сумма от 1 до %d: %d\n", n, calc(n));

    return 0;
}
