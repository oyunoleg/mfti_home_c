/*
3. Найти максимальную цифру
Дано трехзначное число, напечатать максимальную цифру
Данные на входе:  Целое положительное трехзначное число
Данные на выходе: Одна цифра

Пример:
Данные на входе: 435  
Данные на выходе: 5
*/
#include <stdio.h>

int main(void)
{
    int n;
    printf("Введите произвольное трехзначное целое число:\n");
    scanf("%d", &n);        // 435
    int a = (n / 100) % 10; // 4
    int b = (n / 10) % 10;  // 3
    int c = n % 10;         // 5

    int max = (a > b) ? a : b;
    max = (max > c) ? max : c;
    printf("max: %d\n", max);

    return 0;
}