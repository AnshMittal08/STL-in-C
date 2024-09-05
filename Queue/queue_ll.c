#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include "queue.h"

struct Node {
    int item;
    struct Node* next;
};

typedef struct Node Node;
static Node* head = NULL;
static Node* tail = NULL;
static int N = 0;

void initQueue()
{
    head = NULL;
    tail = NULL;
    N = 0;
}

void enqueue(int item)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item = item;
    newNode->next = NULL;

    if (isEmpty())
    {
        head = newNode;
    }
    else
    {
        tail->next = newNode;
    }
    tail = newNode;
    N++;
}

int dequeue()
{
    if (isEmpty()) return INT_MIN;
    int item = head->item;
    Node* temp = head;
    head = head->next;
    if (head == NULL)
    {
        tail = NULL;
    }
    free(temp);
    N--;
    return item;
}

int size()
{
    return N;
}

bool isEmpty()
{
    return N == 0;
}

void testQueue()
{
    enqueue(3);
    enqueue(4);
    enqueue(9);

    assert(size() == 3);
    assert(dequeue() == 3);
    assert(size() == 2);
    assert(dequeue() == 4);
    assert(size() == 1);
    assert(dequeue() == 9);
    assert(size() == 0);
    assert(isEmpty());
}
