#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    void **elements;
    size_t size;
    size_t capacity;
} Vector;

void initVector(Vector *vector);
void pushBack(Vector *vector, void *element);
void printVector(Vector *vector, void (*printFunc)(void *));
void sortVector(Vector *vector, int (*compareFunc)(const void *, const void *));
void *getElement(Vector *vector, size_t index);
void removeElement(Vector *vector, size_t index);
void freeVector(Vector *vector);

int compareInt(const void *a, const void *b);
int compareString(const void *a, const void *b);

#endif
