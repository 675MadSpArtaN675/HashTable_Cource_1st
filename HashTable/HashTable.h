#ifndef _HASH_TALBE
#define _HASH_TABLE

#define TABLE_SIZE 100

typedef struct
{
	char* key;
	int value;
}HashEntry_t;

typedef struct
{
	HashEntry_t** entries;
}HashTable_t;

HashTable_t* createHashTable();

void insert(HashTable_t* table, char* key, int value);
int search(HashTable_t* table, char* key);
void deleteElement(HashTable_t* table, char* key);

void destroyTable(HashTable_t* table);
void printHashTable(HashTable_t* table);

unsigned int hash(char* key);

#endif