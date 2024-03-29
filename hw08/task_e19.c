/*
E19 ДЗ *
Цифры по порядку
Вывести в порядке следования цифры, входящие в десятичную
запись натурального числа N.

Данные на входе:  Одно натуральное число N
Данные на выходе: Цифры через пробел

Пример
Данные на входе:  54412
Данные на выходе: 5 4 4 1 2
*/
#include <stdio.h>

void PrintDigits(int n)
{
    int len = 0, index = 0, temp = n;

    // Вычисляем длину числа n
    while (temp != 0)
    {
        len++;
        temp /= 10;
    }
    // Массив с цифрами в обратном порядке
    int digits[len];

    // Извлекаем все цифры в массив
    while (n != 0)
    {
        digits[index] = n % 10;
        index++;
        n /= 10;
    }

    // Вывод цифр из массива в прямом порядке
    for (int i = len - 1; i >= 0; i--)
        printf("%d ", digits[i]);
}

int main()
{
    int n;
    //printf("Введите одно целое число:\n");
    scanf("%d", &n);

    PrintDigits(n);
    printf("\n");

    return 0;
}