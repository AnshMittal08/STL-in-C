#include "doubly_list.h"
#include <stdio.h>
#include <stdlib.h>

// Initialize the list
void initList(DoublyList *list) {
    list->head = NULL;
    list->tail = NULL;
}

// Append a node to the end of the list
void append(DoublyList *list, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (list->head == NULL) {
        newNode->prev = NULL;
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

// Prepend a node to the start of the list
void prepend(DoublyList *list, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    
    if (list->head == NULL) {
        newNode->next = NULL;
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
}

// Insert a node at a specific position
void insertAt(DoublyList *list, int index, int data) {
    if (index < 0) {
        printf("Index out of bounds.\n");
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (index == 0) {
        prepend(list, data);
        return;
    }

    Node *current = list->head;
    for (int i = 0; i < index - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Index out of bounds.\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    newNode->prev = current;
    
    if (current->next != NULL) {
        current->next->prev = newNode;
    } else {
        list->tail = newNode;
    }
    
    current->next = newNode;
}

// Delete a specific node from the list
void deleteNode(DoublyList *list, Node *node) {
    if (node == NULL) return;

    if (node->prev) {
        node->prev->next = node->next;
    } else {
        list->head = node->next; // Node is head
    }

    if (node->next) {
        node->next->prev = node->prev;
    } else {
        list->tail = node->prev; // Node is tail
    }

    free(node);
}

// Print the list from head to tail
void printList(DoublyList *list) {
    Node *current = list->head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Free the list and its nodes
void freeList(DoublyList *list) {
    Node *current = list->head;
    Node *next;

    while (current) {
        next = current->next;
        free(current);
        current = next;
    }

    list->head = NULL;
    list->tail = NULL;
}
