/*
E20 ДЗ *
Переставить цифры
Переставить цифры в числе так, чтобы получилось максимальное число.
Данные на входе:  Одно целое не отрицательное число
Данные на выходе: Целое неотрицательное число

Пример №1
Данные на входе:  1229
Данные на выходе: 9221

Пример №2
Данные на входе:  19
Данные на выходе: 91
*/
#include <stdio.h>

void SwapArr(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Выполняет сортировку массива по убыванию
void BubbleSortDesc(int *arr, int len)
{
    int noSwap;
    for (int i = len - 1; i >= 0; i--)
    {
        noSwap = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                SwapArr(arr, j, j + 1);
                noSwap = 0;
            }
        }
        if (noSwap)
            break;
    }
}

void printLikeMax(int n)
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

    // Вывод переставленных цифр из отсортированного массива
    BubbleSortDesc(digits, len);
    for (int i = 0; i < len; i++)
        printf("%d", digits[i]);
     printf("\n");    
}

int main()
{
    int n;
    //printf("Введите одно целое неотрицательное число:\n");
    scanf("%d", &n);

    printLikeMax(n);
   
    return 0;
}
