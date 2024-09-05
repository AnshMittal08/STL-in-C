#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

void printInt(void *element) {
    printf("%d\n", *(int *)element);
}

void printString(void *element) {
    printf("%s\n", (char *)element);
}

int main() {
    Vector vector;
    initVector(&vector);

    // Test with integers
    int *a = malloc(sizeof(int));
    *a = 3;
    int *b = malloc(sizeof(int));
    *b = 1;
    int *c = malloc(sizeof(int));
    *c = 2;
    int *d = malloc(sizeof(int));
    *d = 6;
    int *e = malloc(sizeof(int));
    *e = 4;
    int *f = malloc(sizeof(int));
    *f = 5;

    pushBack(&vector, a);
    pushBack(&vector, b);
    pushBack(&vector, c);
    pushBack(&vector, d);
    pushBack(&vector, e);
    pushBack(&vector, f);

    printf("Original vector:\n");
    printVector(&vector, printInt);

    sortVector(&vector, compareInt);

    printf("Sorted vector:\n");
    printVector(&vector, printInt);

    freeVector(&vector); // Free allocated memory

    return 0;
}
