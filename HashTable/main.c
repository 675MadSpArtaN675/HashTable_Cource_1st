#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "HashTable.h"

void Wait();

void main()
{
    setlocale(LC_ALL, "ru");
    HashTable_t* test_table = createHashTable();

    while (1)
    {
        puts("Выберите действие:\n\t1 - Добавить элемент в таблицу;\n\t2 - Удалить элемент;\n\t3 - Найти элемент по ключу;\n\t4 - Вывести таблицу;\n\t5 - Выход");
        int act;
        scanf("%i", &act);
        getchar();

        switch (act)
        {
        case 1:
        {
            char key[51];
            int value;

            printf("Введите ключ и значение: ");
            scanf("%s %i", &key, &value);
            getchar();

            insert(test_table, key, value);

            Wait();
        }
        break;
        case 2:
        {
            char key[51];

            printf("Введите ключ: ");
            scanf("%s", &key);
            getchar();

            deleteElement(test_table, key);

            Wait();
        }
        break;
        case 3:
        {
            char key[51];

            printf("Введите ключ: ");
            scanf("%s", &key);
            getchar();

            int value = search(test_table, key);

            printf("По ключу %s лежит %i\n", key, value);

            Wait();
        }
        break;
        case 4:
        {
            printHashTable(test_table);

            Wait();
        }
        break;
        case 5:
            return;
        default:
            return;
        }
    }

    destroyTable(test_table);
}

void Wait()
{
    puts("Нажмите Enter для продолжения...");
    getchar();
    system("cls");
}