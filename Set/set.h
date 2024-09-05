// set.h
#ifndef SET_H
#define SET_H

#include <stdbool.h>
#include <stdint.h>

// Function pointer type for comparison function
typedef int (*compare_func)(const void *, const void *);

// Function pointer type for hash function
typedef uint32_t (*hash_func)(const void *, uint32_t);

typedef struct SetEntry {
    void *data;
    struct SetEntry *next;
} SetEntry;

typedef struct Set {
    uint32_t size;
    SetEntry **buckets;
    compare_func compare;
    hash_func hash;
} Set;

Set *set_create(uint32_t size, compare_func cmp, hash_func hash);
void set_destroy(Set *set);
bool set_add(Set *set, void *data);
bool set_remove(Set *set, void *data);
bool set_contains(Set *set, void *data);
void set_clear(Set *set);
void set_print(Set *set, void (*print_func)(const void *));

#endif
