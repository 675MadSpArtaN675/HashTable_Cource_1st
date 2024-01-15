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
        puts("�������� ��������:\n\t1 - �������� ������� � �������;\n\t2 - ������� �������;\n\t3 - ����� ������� �� �����;\n\t4 - ������� �������;\n\t5 - �����");
        int act;
        scanf("%i", &act);
        getchar();

        switch (act)
        {
        case 1:
        {
            char key[51];
            int value;

            printf("������� ���� � ��������: ");
            scanf("%s %i", &key, &value);
            getchar();

            insert(test_table, key, value);

            Wait();
        }
        break;
        case 2:
        {
            char key[51];

            printf("������� ����: ");
            scanf("%s", &key);
            getchar();

            deleteElement(test_table, key);

            Wait();
        }
        break;
        case 3:
        {
            char key[51];

            printf("������� ����: ");
            scanf("%s", &key);
            getchar();

            int value = search(test_table, key);

            printf("�� ����� %s ����� %i\n", key, value);

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
    puts("������� Enter ��� �����������...");
    getchar();
    system("cls");
}