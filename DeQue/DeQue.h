#ifndef DEQUE_H
#define DEQUE_H

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct Deque{
    Node *front;
    Node *rear;
}Deque;

Deque* createDeque();
int isEmpty(Deque *deque);
void insertFront(Deque *deque, int data);
void insertRear(Deque *deque, int data);
int deleteFront(Deque *deque);
int deleteRear(Deque *deque);
int getFront(Deque *deque);
int getRear(Deque *deque);
void displayDeque(Deque *deque);
void clearDeque(Deque *deque); 
void insertAt(Deque *deque, int data, int position);
void freeDeque(Deque *deque);

#endif

