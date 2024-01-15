#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "HashTable.h"

HashTable_t* createHashTable()
{
    HashTable_t* table = (HashTable_t*)malloc(sizeof(HashTable_t));
    table->entries = (HashEntry_t**)calloc(TABLE_SIZE, sizeof(HashEntry_t*));
    return table;
}

void insert(HashTable_t* table, char* key, int value)
{
    HashEntry_t** entries = table->entries;
    HashEntry_t* item = (HashEntry_t*)malloc(sizeof(HashEntry_t*));

    int key_hash = hash(key);
    
    item->key = (char*)calloc(strlen(key) + 1, sizeof(char));
    strcpy(item->key, key);

    item->value = value;

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        HashEntry_t* element = entries[i];

        if (element == NULL || hash(element->key) == key_hash)
        {
            entries[i] = item;
            break;
        }
    }
}

int search(HashTable_t* table, char* key)
{
    HashEntry_t** entries = table->entries;
    int key_hash = hash(key);

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (entries[i] == NULL)
            return -1;

        int key_tb = hash(entries[i]->key);

        if (key_tb == key_hash)
            return entries[i]->value;
    }
}

void deleteElement(HashTable_t* table, char* key)
{
    HashEntry_t** entries = table->entries;
    int key_hash = hash(key);

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (entries[i] == NULL)
            return;

        int key_tb = hash(entries[i]->key);

        if (key_tb == key_hash)
        {
            free(entries[i]->key);
            entries[i] = NULL;
            return;
        }
    }
}

void destroyTable(HashTable_t* table)
{
    HashEntry_t** entries = table->entries;

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (entries[i] == NULL)
            continue;

        free(entries[i]->key);
    }

    free(entries);
    free(table);
}

void printHashTable(HashTable_t* table)
{
    HashEntry_t** entries = table->entries;

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (entries[i] == NULL)
            continue;
        printf("Ключ: %s, Значение: %i;\n", entries[i]->key, entries[i]->value);
    }
}

unsigned int hash(char* key)
{
    int r = 0;
    for (int i = 0; i < strlen(key); i++)
    {
        int h = key[i];
        r += h;
    }

    return r;
}