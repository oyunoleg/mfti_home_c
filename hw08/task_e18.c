/*
E18
Кратность прежде всего.
В диапазоне натуральных чисел от 2 до N определить,
сколько из них кратны любому из чисел в диапазоне от 2 до 9.

Данные на входе: 	Одно целое число N большее 2 и не превосходящее 10000
Данные на выходе: 	Все числа от 2 до 9 в формате:
2 количество чисел кратных 2
3 количество чисел кратных 3
4 количество чисел кратных 4
5 количество чисел кратных 5
6 количество чисел кратных 6
7 количество чисел кратных 7
8 количество чисел кратных 8
9 количество чисел кратных 9

Пример №1
Данные на входе: 	99
Данные на выходе: 	2 49 3 33 4 24 5 19 6 16 7 14 8 12 9 11
** то есть 2*49=98, 3*33=99, 4*24=96, 5*19=95, 6*16=96, 7*14=98, 8*12=96, 9*11=99


Пример №2
Данные на входе: 	9
Данные на выходе: 	2 4 3 3 4 2 5 1 6 1 7 1 8 1 9 1
** 2*4=8, 3*3=9,  4*2=8,  5*1=5, 6*1=6, 7*1=7, 8*1=8, 9*1=9
*/
#include <stdio.h>

void printResult(int max_number)
{
    /* Массив (8 элементов), который хранит количество чисел:
     - первый элемент - количество чисел кратных 2,
     - и т.д:  2-7 элемент - количество чисел кратных 3-8,
     - последний восьмой - количество чисел кратных 9 */
    int result[8] = {0};

    // Перебираем подряд все числа от 2 до N
    for (int number = 2; number <= max_number; number++)
    {
        // Перебираем числа от 2 до 9 для текущего number для определения кратных.
        // res_index - позиция в массиве result, т.к. 'j' начинается с 2.
        for (int j = 2, r_index = 0; j <= 9; j++, r_index++)
        {
            // Если число i кратно числу j, увеличиваем соотв. элемент в массиве result
            if (number % j == 0)
                result[r_index] = result[r_index] + 1;
        }
    }

    // Выводим из массива все 8 пар чисел с учетом смещения на i+2,
    for (int i = 0, number = 2; i < 8; i++, number++)
        printf("%d %d\n", number, result[i]);
}

int main(void)
{
    int n;
    //printf("Введите одно целое число N (2..10000): ");
    scanf("%d", &n);

    if (n >= 2 && n <= 10000)
    {
        printResult(n);
        return 0;
    }
    else
    {
        //printf("Ошибка: Число N имеет недопустимое значение %d.\n", n);
        return 1;
    }
}
