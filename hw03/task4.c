/*
4.Найти среднее арифметическое трех целых чисел
Ввести три числа, найти их среднее арифметическое.
Нужно напечатать среднее арифметическое чисел.
Данные на входе:  Три целых целых числа через пробел.
Данные на выходе: Вещественное число в формате %.2f
*/
#include <stdio.h>

int main(void)
{
    int a, b, c;
    printf("Введите 3 целых числа через пробел:\n");
    scanf("%d%d%d", &a, &b, &c);
    float result = (float)(a + b + c) / 3;
    printf("%.2f\n", result);

    return 0;
}
