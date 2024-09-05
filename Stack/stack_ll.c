#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

struct Node {
    int item;
    struct Node* next;
};

typedef struct Node Node;
Node* head = NULL;
int N = 0;

void push(int item)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item = item;
    newNode->next = head;
    head = newNode;
    N++;
}

int pop()
{
    if (isEmpty()) return INT_MIN;
    int item = head->item;
    Node* temp = head;
    head = head->next;
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

void testStack()
{
    push(3);
    push(4);
    push(9);

    assert(size() == 3);
    assert(pop() == 9);
    assert(size() == 2);
    assert(pop() == 4);
    assert(size() == 1);
    assert(pop() == 3);
    assert(size() == 0);
    assert(isEmpty());
}

int main()
{
    testStack();
    return 0;
}
