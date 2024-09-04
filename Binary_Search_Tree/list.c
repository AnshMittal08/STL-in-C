#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initList(List *list)
{
    list->capacity = 10;
    list->size = 0;
    list->elements = malloc(sizeof(void *) * list->capacity);
}

void addElement(List *list, void *element)
{
    if (list->size == list->capacity)
    {
        list->capacity *= 2;
        list->elements = realloc(list->elements, sizeof(void *) * list->capacity);
    }
    list->elements[list->size++] = element;
}

void printList(List *list, void (*printFunc)(void *))
{
    for (size_t i = 0; i < list->size; i++)
    {
        printFunc(list->elements[i]);
    }
}

void sortList(List *list, int (*compareFunc)(const void *, const void *))
{
    // Use a simple bubble sort algorithm
    for (size_t i = 0; i < list->size; i++)
    {
        for (size_t j = i + 1; j < list->size; j++)
        {
            if (compareFunc(list->elements[i], list->elements[j]) > 0)
            {
                void *temp = list->elements[i];
                list->elements[i] = list->elements[j];
                list->elements[j] = temp;
            }
        }
    }
}

int compareInt(const void *a, const void *b)
{
    int intA = *(int *)a;
    int intB = *(int *)b;
    
    return (intA > intB) - (intA < intB);
}

int compareString(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char **)b);
}
