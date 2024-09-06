#ifndef MAX_PRIORITY_QUEUE_H
#define MAX_PRIORITY_QUEUE_H

#include <stdbool.h>

// Max Priority Queue structure
typedef struct {
    int *data;       // Array to hold the heap elements
    int size;        // Current number of elements in the heap
    int capacity;    // Maximum capacity of the heap
} MaxPriorityQueue;

// Function Prototypes
void initMaxPriorityQueue(MaxPriorityQueue *pq, int capacity);
void insertMaxPQ(MaxPriorityQueue *pq, int value);
int getMax(MaxPriorityQueue *pq);
int extractMax(MaxPriorityQueue *pq);
bool isMaxPQEmpty(MaxPriorityQueue *pq);
int maxPQSize(MaxPriorityQueue *pq);
void freeMaxPriorityQueue(MaxPriorityQueue *pq);

// Utility function for testing
void testMaxPriorityQueue();

#endif // MAX_PRIORITY_QUEUE_H
