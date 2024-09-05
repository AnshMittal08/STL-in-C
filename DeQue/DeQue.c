#include "DeQue.h"

Deque* createDeque()
{
    Deque *deque = (Deque*)malloc(sizeof(Deque));
    deque->front = deque->rear = NULL;
    return deque;
}

int isEmpty(Deque *deque)
{
    return (deque->front == NULL);
}

void insertFront(Deque *deque, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = deque->front;

    if(isEmpty(deque))
    {
        deque->rear = newNode;
    }else{
        deque->front = newNode;
    }

    deque->front = newNode;
}

void insertRear(Deque *deque, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = deque->rear;

    if(isEmpty(deque)){
        deque->front = newNode;
    }else{
        deque->rear->next = newNode;
    }

    deque->rear = newNode;
}

void insertAt(Deque *deque, int data, int position)
{
    if(position <= 0 || isEmpty(deque))
    {
        insertFront(deque, data);
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    Node *current = deque->front;
    int i = 0;

    while (current != NULL && i < position - 1)
    {
        current = current->next;
        i++;
    }

    if(current == NULL || current->next == NULL)
    {
        insertRear(deque, data);
        return;
    }
    
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

int deleteFront(Deque *deque)
{
    if(isEmpty(deque))
    {
        printf("Deque is empty, cannot perform delete operation");
        return -1;
    }

    Node *temp = deque->front;
    int data = temp->data;
    deque->front = deque->front->next;

    if (deque->front == NULL) {
        deque->rear = NULL;
    } else {
        deque->front->prev = NULL;
    }

    free(temp);
    return data;
}

int deleteRear(Deque *deque)
{
    if (isEmpty(deque)) {
        printf("Deque is empty, cannot delete from rear.\n");
        return -1;
    }

    Node *temp = deque->rear;
    int data = temp->data;
    deque->rear = deque->rear->prev;

    if (deque->rear == NULL) {
        deque->front = NULL;
    } else {
        deque->rear->next = NULL;
    }

    free(temp);
    return data;
}

int getFront(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return -1;
    }
    return deque->front->data;
}

int getRear(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return -1;
    }
    return deque->rear->data;
}

void displayDeque(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }

    Node *temp = deque->front;
    printf("Deque elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void clearDeque(Deque *deque) {
    while (!isEmpty(deque)) {
        deleteFront(deque);
    }
}

void freeDeque(Deque *deque) {
    clearDeque(deque);
    free(deque);
}