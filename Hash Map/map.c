#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

// Function to create a new hash map
HashMap* createHashMap() {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->table = (KeyValuePair**)calloc(TABLE_SIZE, sizeof(KeyValuePair*));
    return map;
}

// Hash function to compute the index for a given key
unsigned long hash(const char* key) {
    unsigned long hash = 5381;
    int c;
    while ((c = *key++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % TABLE_SIZE;
}

// Function to add a key-value pair to the hash map
void put(HashMap* map, const char* key, int value) {
    unsigned long index = hash(key);
    KeyValuePair* newPair = (KeyValuePair*)malloc(sizeof(KeyValuePair));
    newPair->key = strdup(key);
    newPair->value = value;
    newPair->next = map->table[index];
    map->table[index] = newPair;
}

// Function to get the value associated with a key
int get(HashMap* map, const char* key) {
    unsigned long index = hash(key);
    KeyValuePair* pair = map->table[index];

    while (pair) {
        if (strcmp(pair->key, key) == 0) {
            return pair->value; // Found the key
        }
        pair = pair->next;
    }
    return -1; // Key not found, return -1 as error value
}

// Function to remove a key-value pair from the hash map
void removeKey(HashMap* map, const char* key) {
    unsigned long index = hash(key);
    KeyValuePair* pair = map->table[index];
    KeyValuePair* prev = NULL;

    while (pair) {
        if (strcmp(pair->key, key) == 0) {
            if (prev) {
                prev->next = pair->next;
            } else {
                map->table[index] = pair->next;
            }
            free(pair->key);
            free(pair);
            return;
        }
        prev = pair;
        pair = pair->next;
    }
}

// Function to check if the map is empty
int isEmpty(HashMap* map) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (map->table[i]) {
            return 0; // Found a key, map is not empty
        }
    }
    return 1; // Map is empty
}

// Function to free the hash map and its contents
void freeHashMap(HashMap* map) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        KeyValuePair* pair = map->table[i];
        while (pair) {
            KeyValuePair* temp = pair;
            pair = pair->next;
            free(temp->key);
            free(temp);
        }
    }
    free(map->table);
    free(map);
}