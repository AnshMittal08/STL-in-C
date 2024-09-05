// set.c
#include "set.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Set creation
Set *set_create(uint32_t size, compare_func cmp, hash_func hash) {
    Set *set = malloc(sizeof(Set));
    set->size = size;
    set->buckets = calloc(size, sizeof(SetEntry *));
    set->compare = cmp;
    set->hash = hash;
    return set;
}

void set_destroy(Set *set) {
    set_clear(set);
    free(set->buckets);
    free(set);
}

// Add element to set
bool set_add(Set *set, void *data) {
    uint32_t index = set->hash(data, set->size);
    SetEntry *entry = set->buckets[index];

    while (entry) {
        if (set->compare(entry->data, data) == 0) {
            return false;  // Element already exists
        }
        entry = entry->next;
    }

    // Create a new entry
    entry = malloc(sizeof(SetEntry));
    entry->data = data;
    entry->next = set->buckets[index];
    set->buckets[index] = entry;
    return true;
}

// Remove element from set
bool set_remove(Set *set, void *data) {
    uint32_t index = set->hash(data, set->size);
    SetEntry *entry = set->buckets[index];
    SetEntry *prev = NULL;

    while (entry) {
        if (set->compare(entry->data, data) == 0) {
            if (prev) {
                prev->next = entry->next;
            } else {
                set->buckets[index] = entry->next;
            }
            free(entry);
            return true;
        }
        prev = entry;
        entry = entry->next;
    }

    return false;  // Element not found
}

// Check if element exists in set
bool set_contains(Set *set, void *data) {
    uint32_t index = set->hash(data, set->size);
    SetEntry *entry = set->buckets[index];

    while (entry) {
        if (set->compare(entry->data, data) == 0) {
            return true;  // Element found
        }
        entry = entry->next;
    }
    return false;
}

// Clear the set
void set_clear(Set *set) {
    for (uint32_t i = 0; i < set->size; i++) {
        SetEntry *entry = set->buckets[i];
        while (entry) {
            SetEntry *temp = entry;
            entry = entry->next;
            free(temp);
        }
        set->buckets[i] = NULL;
    }
}

// Print the set
void set_print(Set *set, void (*print_func)(const void *)) {
    printf("Set Elements:\n");
    for (uint32_t i = 0; i < set->size; i++) {
        SetEntry *entry = set->buckets[i];
        while (entry) {
            print_func(entry->data);
            entry = entry->next;
        }
    }
}
