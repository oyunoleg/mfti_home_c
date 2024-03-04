/*
4. Найти сумму максимума и минимума
Напечатать сумму максимума и минимума.
Данные на входе:  Пять целых чисел через пробел
Данные на выходе:  Одно целое число - сумма максимума и минимума

Пример:
Данные на входе: 4 15 9 56 4  
Данные на выходе: 60
*/
#include <stdio.h>

int main(void)
{
    int a, b, c, d, e;
    printf("Введите 5 целых чисел через пробел:\n");
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);

    int min = (a < b) ? a : b;
    min = (c < min) ? c : min;
    min = (d < min) ? d : min;
    min = (e < min) ? e : min;

    int max = (a > b) ? a : b;
    max = (max > c) ? max : c;
    max = (max > d) ? max : d;
    max = (max > e) ? max : e;
    printf("%d + %d = %d\n", min, max, min + max);

    return 0;
}
