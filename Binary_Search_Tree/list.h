#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    void **elements;
    size_t size;
    size_t capacity;
} List;

void initList(List *list);
void addElement(List *list, void *element);
void printList(List *list, void (*printFunc)(void *));
void sortList(List *list, int (*compareFunc)(const void *, const void *));
int compareInt(const void *a, const void *b);
int compareString(const void *a, const void *b);

#endif
