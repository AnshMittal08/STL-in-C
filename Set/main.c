// main.c
#include "set.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Integer comparison function
int compare_int(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// String comparison function
int compare_string(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

// Integer hash function
uint32_t hash_int(const void *a, uint32_t size) {
    return (*(int *)a) % size;
}

// String hash function
uint32_t hash_string(const void *key, uint32_t size) {
    const char *str = (const char *)key;
    uint32_t hash = 0;
    while (*str) {
        hash = (hash * 31) + *str++;
    }
    return hash % size;
}

// Print function for integers
void print_int(const void *a) {
    printf("%d\n", *(int *)a);
}

// Print function for strings
void print_string(const void *a) {
    printf("%s\n", (const char *)a);
}

int main() {
    Set *intSet = set_create(10, compare_int, hash_int);
    int a = 5, b = 10, c = 15;
    set_add(intSet, &a);
    set_add(intSet, &b);
    set_add(intSet, &c);
    set_print(intSet, print_int);
    set_destroy(intSet);

    Set *stringSet = set_create(10, compare_string, hash_string);
    set_add(stringSet, "apple");
    set_add(stringSet, "banana");
    set_add(stringSet, "cherry");
    set_print(stringSet, print_string);
    set_destroy(stringSet);

    return 0;
}
