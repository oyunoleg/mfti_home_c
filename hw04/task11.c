/*
11. Существует ли треугольник
Даны стороны треугольника a, b, c.
Определить - существует ли такой треугольник.
Для того чтобы треугольник существовал, сумма длин
любых двух сторон должна быть больше длины третьей стороны.
Данные на входе:  Три целых числа. Стороны треугольника a, b, c.
Данные на выходе: YES или NO

Пример:
Данные на входе:  3 2 4
Данные на выходе: YES
*/
#include <stdio.h>

int main(void)
{
    int a, b, c;
    printf("Введите 3 целых числа через пробел:\n");
    scanf("%d%d%d", &a, &b, &c);

    printf("%s\n",
           (a + b > c && b + c > a && c + a > b) ? "YES" : "NO");

    return 0;
}