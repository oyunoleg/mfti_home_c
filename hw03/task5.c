/*
5.Найти произведение цифр
На вход подается произвольное трехзначное число.
Нужно напечатать произведение цифр.
Данные на входе:  Трехзначное целое положительное число
Данные на выходе: Одно целое число
*/
#include <stdio.h>

int main(void)
{
    int n, res;
    printf("Введите произвольное трехзначное целое число:\n");
    scanf("%d", &n);       // 435
    res = n % 10;          // 5
    res *= (n / 10) % 10;  // 5*3=15
    res *= (n / 100) % 10; // 15*4=60
    printf("%d\n", res);   // 60

    return 0;
}
