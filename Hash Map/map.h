#ifndef SIMPLE_HASH_MAP_H
#define SIMPLE_HASH_MAP_H

#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 16

typedef struct KeyValuePair {
    char* key;
    int value;
    struct KeyValuePair* next;
} KeyValuePair;

typedef struct HashMap {
    KeyValuePair** table;
} HashMap;

// Function prototypes
HashMap* createHashMap();
void freeHashMap(HashMap* map);
unsigned long hash(const char* key);
void put(HashMap* map, const char* key, int value);
int get(HashMap* map, const char* key);
void removeKey(HashMap* map, const char* key);
int size(HashMap* map);
int isEmpty(HashMap* map);

#endif // SIMPLE_HASH_MAP_H