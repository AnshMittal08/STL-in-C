#ifndef DOUBLY_LIST_H
#define DOUBLY_LIST_H

#include <stddef.h>

// Define the Node structure
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

// Define the DoublyList structure
typedef struct {
    Node *head;
    Node *tail;
} DoublyList;

// Function prototypes
void initList(DoublyList *list);
void append(DoublyList *list, int data);
void prepend(DoublyList *list, int data);
void insertAt(DoublyList *list, int index, int data);
void deleteNode(DoublyList *list, Node *node);
void printList(DoublyList *list);
void freeList(DoublyList *list);


#endif
