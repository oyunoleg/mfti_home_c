/*
F1 
Сортировка по возрастанию
Написать функцию и программу, демонстрирующую работу данной функции, которая сортирует массив по возрастанию. 
Строго согласно прототипу. Имя функции и все аргументы должны быть:
void sort_array(int size, int a[])

Данные на входе: 		Функция принимает на вход, первый аргумент - размер массива, второй аргумент - адрес нулевого элемента. 
Данные на выходе: 	Функция ничего не возвращает. Производит сортировку переданного ей массива по возрастанию. 

Пример №1
Данные на входе: 	20 19 4 3 2 1 18 17 13 12 11 16 15 14 10 9 8 7 6 5. 
Данные на выходе: 	1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20. 

Пример №2
Данные на входе: 	5 4 3 2 1. 
Данные на выходе: 	1 2 3 4 5 
*/
#include <stdio.h>

int Input(int arr[], int n)
{
    int i, num;
    while (scanf("%d", &num) == 1)
        arr[i++] = num;
    return i;
}

int isDigit(char c) // проверяем является ли символ цифрой
{
    return ((c >= '0') && (c <= '9'));
}

int InputGet(int arr[], int n)
{
    int i;
    char c;
    while ((c = getchar()) != '\n')
    {
        if (isDigit(c))
        {
            int number = 0;
            do
            {
                number = number * 10 + c - '0';
                c = getchar();
            } while (isDigit(c));
            arr[i++] = number;
            if (c == '\n')
                break;
        }
    }
    return i;
}

void BubbleSort(int arr[], int n)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    for (i = 0; i < n; ++i)
    {
        for (j = i; j < n; ++j)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void Print(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    enum
    {
        BUFFER_SIZE = 20
    };
    int buffer[BUFFER_SIZE];
    int size = InputGet(buffer, BUFFER_SIZE);
    printf("size =%d\n", size);
    BubbleSort(buffer, size);
    Print(buffer, size);
    return 0;
}
