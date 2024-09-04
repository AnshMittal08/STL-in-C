#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void printInt(void *element)
{
    printf("%d\n", *(int *)element);
}

void printString(void *element)
{
    printf("%s\n", (char *)element);
}

int main()
{
    List list;
    initList(&list);

    // Test with integers
    int a = 3, b = 1, c = 2, d = 6, e = 4, f = 5;
    addElement(&list, &a);
    addElement(&list, &b);
    addElement(&list, &c);
    addElement(&list, &d);
    addElement(&list, &e);
    addElement(&list, &f);

    printf("Original list:\n");
    printList(&list, printInt);

    sortList(&list, compareInt);

    printf("Sorted list:\n");
    printList(&list, printInt);

    return 0;
}
