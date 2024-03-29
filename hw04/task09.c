/*
9. В порядке возрастания
Ввести три числа и определить, верно ли, что они вводились в порядке возрастания.
Данные на входе:  Три целых числа
Данные на выходе: Одно слово YES или NO

Пример:
Данные на входе: 4 5 17
Данные на выходе: YES
*/
#include <stdio.h>

int main(void)
{
    int a, b, c;
    printf("Введите 3 целых числа через пробел:\n");
    scanf("%d%d%d", &a, &b, &c);

    printf("%s\n", (a < b && b < c) ? "YES" : "NO");

    return 0;
}