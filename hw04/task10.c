/*
10. Какое время года
Ввести номер месяца и вывести название времени года.
Данные на входе: Целое число от 1 до 12 - номер месяца.
Данные на выходе:  Время года на английском: winter, spring, summer, autumn
 (используйте switch)

Пример №1:
Данные на входе: 4
Данные на выходе: spring

Пример №2:
Данные на входе: 1
Данные на выходе: winter
*/
#include <stdio.h>

int main(void)
{
    int num;
    printf("Введите целое число от 1 до 12 - номер месяца:\n");
    scanf("%d", &num);

    switch (num)
    {
    case 1:
    case 2:
    case 12: // December
        printf("winter\n");
        break;

    case 3:
    case 4:
    case 5:
        printf("spring\n");
        break;

    case 6:
    case 7:
    case 8:
        printf("summer\n");
        break;

    case 9:
    case 10:
    case 11:
        printf("autumn\n");
        break;

    default:
        printf("Ошибка ввода номера месяца\n");
    }

    return 0;
}