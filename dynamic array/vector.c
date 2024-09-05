#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initVector(Vector *vector) {
    vector->capacity = 10;
    vector->size = 0;
    vector->elements = malloc(sizeof(void *) * vector->capacity);
}

void pushBack(Vector *vector, void *element) {
    if (vector->size == vector->capacity) {
        vector->capacity *= 2;
        vector->elements = realloc(vector->elements, sizeof(void *) * vector->capacity);
    }
    vector->elements[vector->size++] = element;
}

void printVector(Vector *vector, void (*printFunc)(void *)) {
    for (size_t i = 0; i < vector->size; i++) {
        printFunc(vector->elements[i]);
    }
}

void sortVector(Vector *vector, int (*compareFunc)(const void *, const void *)) {
    // Use a simple bubble sort algorithm
    for (size_t i = 0; i < vector->size; i++) {
        for (size_t j = i + 1; j < vector->size; j++) {
            if (compareFunc(vector->elements[i], vector->elements[j]) > 0) {
                void *temp = vector->elements[i];
                vector->elements[i] = vector->elements[j];
                vector->elements[j] = temp;
            }
        }
    }
}

void *getElement(Vector *vector, size_t index) {
    if (index < vector->size) {
        return vector->elements[index];
    }
    return NULL; // Or handle the error as needed
}

void removeElement(Vector *vector, size_t index) {
    if (index < vector->size) {
        free(vector->elements[index]); // Free the memory if needed
        for (size_t i = index; i < vector->size - 1; i++) {
            vector->elements[i] = vector->elements[i + 1];
        }
        vector->size--;
    }
}

void freeVector(Vector *vector) {
    for (size_t i = 0; i < vector->size; i++) {
        free(vector->elements[i]); // Free the memory if needed
    }
    free(vector->elements);
}

int compareInt(const void *a, const void *b) {
    int intA = *(int *)a;
    int intB = *(int *)b;
    return (intA > intB) - (intA < intB);
}

int compareString(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}
