#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdbool.h>

// Structure definition for a Priority Queue
typedef struct {
    int *heapArray;   // Dynamic array to store heap elements
    int size;         // Current number of elements in the heap
    int capacity;     // Maximum capacity of the heap
} PriorityQueue;

// Initialize a priority queue with a given capacity
void initPriorityQueue(PriorityQueue *pq, int capacity);

// Insert an element into the priority queue
void insert(PriorityQueue *pq, int element);

// Remove and return the minimum element from the priority queue
int extractMin(PriorityQueue *pq);

// Get the minimum element without removing it
int getMin(PriorityQueue *pq);

// Get the number of elements in the priority queue
int size(PriorityQueue *pq);

// Check if the priority queue is empty
bool isEmpty(PriorityQueue *pq);

// Free the memory allocated for the priority queue
void freePriorityQueue(PriorityQueue *pq);

// Test the priority queue implementation
void testPriorityQueue();

#endif // PRIORITY_QUEUE_H
