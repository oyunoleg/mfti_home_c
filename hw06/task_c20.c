/*
C20 Задача со *
Скобки
Проверить строку состоящую из скобок "(" и ")" на корректность.

Данные на входе:  На вход подается строка состоящая из символов '(', ')'
и заканчивающаяся символом '.'. Размер строки не более 1000 символов.
Данные на выходе: Необходимо напечатать слово YES если скобки расставлены верно
и NO в противном случае.

Пример №1:
Данные на входе:  (()()).
Данные на выходе: YES

Пример №2:
Данные на входе:  ()(.
Данные на выходе: NO


*/
#include <stdio.h>

int main(void)
{
    const int LIMIT = 1000;
    int count = 0, len = 0;
    char c;
    puts("Введите строку, состоящую из '(', ')',\nсимвол точки - выход:");
    do
    {
        c = getchar();
        if (c == '(')
            count++;
        else if (c == ')' && count > 0)
            count--; // если пара скобок, то счетчик уменьшаем
        len++;
    } while (c != '.');

    if (len > LIMIT)
    {
        printf("Слишком длинная строка: %d симв.!\n", len);
        printf("Размер строки должен быть не более %d.\n", LIMIT);
        return 1;
    }

    printf("\n%s\n", (count == 0 && len >= 2) ? "YES" : "NO");

    return 0;
}
