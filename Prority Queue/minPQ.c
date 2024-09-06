#include "minPQ.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to initialize the priority queue
void initPriorityQueue(PriorityQueue *pq, int capacity) {
    pq->heapArray = (int *)malloc(sizeof(int) * capacity);
    pq->size = 0;
    pq->capacity = capacity;
}

// Function to swap two elements in the heap
static void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify up (used when inserting an element)
static void heapifyUp(PriorityQueue *pq, int index) {
    int parent = (index - 1) / 2;
    if (index > 0 && pq->heapArray[index] < pq->heapArray[parent]) {
        swap(&pq->heapArray[index], &pq->heapArray[parent]);
        heapifyUp(pq, parent);
    }
}

// Function to heapify down (used when extracting the minimum element)
static void heapifyDown(PriorityQueue *pq, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < pq->size && pq->heapArray[left] < pq->heapArray[smallest])
        smallest = left;
    if (right < pq->size && pq->heapArray[right] < pq->heapArray[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&pq->heapArray[index], &pq->heapArray[smallest]);
        heapifyDown(pq, smallest);
    }
}

// Function to insert an element into the priority queue
void insert(PriorityQueue *pq, int element) {
    if (pq->size == pq->capacity) {
        // Resize the heap array if it's full
        pq->capacity *= 2;
        pq->heapArray = (int *)realloc(pq->heapArray, sizeof(int) * pq->capacity);
    }

    pq->heapArray[pq->size] = element;
    pq->size++;
    heapifyUp(pq, pq->size - 1);
}

// Function to extract the minimum element from the priority queue
int extractMin(PriorityQueue *pq) {
    if (isEmpty(pq))
        return INT_MIN; // Return INT_MIN if the heap is empty

    int minElement = pq->heapArray[0];
    pq->heapArray[0] = pq->heapArray[pq->size - 1];
    pq->size--;
    heapifyDown(pq, 0);

    return minElement;
}

// Function to get the minimum element without removing it
int getMin(PriorityQueue *pq) {
    if (isEmpty(pq))
        return INT_MIN;
    return pq->heapArray[0];
}

// Function to get the size of the priority queue
int size(PriorityQueue *pq) {
    return pq->size;
}

// Function to check if the priority queue is empty
bool isEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}

// Function to free the memory allocated for the priority queue
void freePriorityQueue(PriorityQueue *pq) {
    free(pq->heapArray);
    pq->heapArray = NULL;
    pq->size = 0;
    pq->capacity = 0;
}

// Function to test the priority queue implementation
void testPriorityQueue() {
    PriorityQueue pq;
    initPriorityQueue(&pq, 4); // Initial capacity of 4

    insert(&pq, 10);
    insert(&pq, 5);
    insert(&pq, 30);
    insert(&pq, 2);

    printf("Min element: %d\n", getMin(&pq));
    printf("Extract Min: %d\n", extractMin(&pq));
    printf("New Min element: %d\n", getMin(&pq));

    insert(&pq, 1);
    printf("New Min element after inserting 1: %d\n", getMin(&pq));

    freePriorityQueue(&pq);
}
