/*
D11 ДЗ 3
Количество 1
Дано натуральное число N.
Посчитать количество «1» в двоичной записи числа.
Данные на входе:  Натуральное число
Данные на выходе: Целое число - количество единиц в двоичной записи числа.

Пример №1
Данные на входе:  5
Данные на выходе: 2

Пример №2
Данные на входе:  255
Данные на выходе: 8
*/
#include <stdio.h>

int СountOnes(int n)
{
    if (n == 0)
        return 0;
    return (n % 2) + СountOnes(n / 2);
}

int main(void)
{
    int n;
    //printf("Введите 1 произвольное целое число N:\n");
    scanf("%d", &n);

    printf("%d\n", СountOnes(n));

    return 0;
}
