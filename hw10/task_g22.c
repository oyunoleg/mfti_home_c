/*
G22
Soundex
Известный алгоритм Soundex (https://ru.wikipedia.org/wiki/Soundex)
определяет, похожи ли два английских слова по звучанию.
На вход он принимает слово и заменяет его на некоторый четырёхсимвольный код.
Если коды двух слов совпадают, то слова, как правило, звучат похоже.

Вам требуется реализовать этот алгоритм.
Он работает так:
Первая буква слова сохраняется.
В остальной части слова:

буквы, обозначающие, как правило, гласные звуки: a, e, h, i, o, u, w и y — отбрасываются;
оставшиеся буквы (согласные) заменяются на цифры от 1 до 6,
причём похожим по звучанию буквам соответствуют одинаковые цифры:

1: b, f, p, v
2: c, g, j, k, q, s, x, z
3: d, t
4: l
5: m, n
6: r

Любая последовательность одинаковых цифр сокращается до одной такой цифры.
Итоговая строка обрезается до первых четырёх символов.
Если длина строки меньше требуемой, недостающие символы заменяются знаком 0.

Примеры:
аmmonium → ammnm → a5555 → a5 → a500
implementation → implmnttn → i51455335 → i514535 → i514

Данные на входе: 	Во входном файле .txt находится одно непустое слово,
записанное строчными латинскими буквами. Длина слова не превосходит 20 символов.
Данные на выходе: 	Напечатайте четырёхбуквенный код, соответствующий слову в файл .txt.


Пример №1
Данные на входе: 	ammonium
Данные на выходе: 	a500

Пример №2
Данные на входе: 	implementation
Данные на выходе: 	i514
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 21
const char *INPUT_FILE = "input.txt";
const char *OUTPUT_FILE = "output.txt";

// Чтение строки из входного файла в массив.
int input(char in[])
{
    FILE *fp;
    if ((fp = fopen(INPUT_FILE, "r")) == NULL)
    {
        perror("Error occured while opening input file!");
        return 1;
    }
    fscanf(fp, "%[^\n]", in);
    fclose(fp);
    return 0;
}

// Запись в выходной файл.
int output(char out[])
{
    FILE *fp;
    if ((fp = fopen(OUTPUT_FILE, "w")) == NULL)
    {
        perror("Error occured while opening output file!");
        return 1;
    }
    fprintf(fp, "%s", out);
    fclose(fp);

    return 0;
}

// Возвращает Soundex-код символа.
int soundex_code(char symbol)
{
    switch (tolower(symbol))
    {
    case 'b':
    case 'f':
    case 'p':
    case 'v':
        return 1;
    case 'c':
    case 'g':
    case 'j':
    case 'k':
    case 'q':
    case 's':
    case 'x':
    case 'z':
        return 2;
    case 'd':
    case 't':
        return 3;
    case 'l':
        return 4;
    case 'm':
    case 'n':
        return 5;
    case 'r':
        return 6;
    default:
        return 0;
    }
}

// Приводит строку к формату Soundex - 4 символа.
void normalize_soundex(char str[])
{
    int index = 0;
    while (index < strlen(str) - 1)
    {
        if (index > 0)
        {
            if (str[index] == str[index + 1])
            {
                // Удаляем символ если он равен следующему сдвигом влево на -1
                int i;
                for (i = index; i < strlen(str) - 1; ++i)
                {
                    str[i] = str[i + 1];
                }
                str[i] = '\0'; // Новая длина строки
                index--;       // Смещение назад
            }
        }
        index++;
    }

    // Если строка менее 4 символов, то дополняем ее символами '0'
    for (int i = strlen(str); i < 4; ++i)
    {
        str[i] = '0';
    }

    // Обрезаем строку до 4 символов
    str[4] = '\0';
}

// Преобразование строки по алгоритму Soundex.
void soundex(const char str[], char out[])
{
    // Получаем индекс самого первого символа
    int startPos = -1;
    for (int i = 0; i < strlen(str); ++i)
    {
        if (isalpha(str[i]) && startPos < 0)
        {
            startPos = i;
            break;
        }
    }

    // Если не найдены isalpha символов, то выходим.
    if (startPos < 0)
        return;

    // Первая буква слова сохраняется.
    int count = 0;
    out[count++] = tolower(str[startPos]);

    // Добавляем числовые коды остальных символов (только согласные)
    for (int i = startPos + 1; i < strlen(str); ++i)
    {
        int code = soundex_code(str[i]);
        if (code != 0)
            out[count++] = code + '0';
    }
    out[count] = '\0';
    normalize_soundex(out);
}

int main(void)
{
    char str[MAX_LENGTH] = {0};
    char result[MAX_LENGTH] = {0};
    input(str);
    soundex(str, result);
    output(result);

    return 0;
}
