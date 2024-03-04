/*
7. Наибольшее из пяти чисел
Ввести пять чисел и вывести наибольшее из них
Нужно напечатать наибольшее число
Данные на входе: Пять целых чисел разделенных пробелом
Данные на выходе:  Одно целое число

Пример:
Данные на входе:  4 15 9 56 4
Данные на выходе: 56
*/
#include <stdio.h>

int main(void)
{
    int a, b, c, d, e;
    printf("Введите 5 целых чисел через пробел:\n");
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);

    int max = (a > b) ? a : b;
    max = (max > c) ? max : c;
    max = (max > d) ? max : d;
    max = (max > e) ? max : e;
    printf("max: %d\n", max);

    return 0;
}
