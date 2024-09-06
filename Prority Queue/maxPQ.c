#include "maxPQ.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Initialize the Max Priority Queue
void initMaxPriorityQueue(MaxPriorityQueue *pq, int capacity) {
    pq->data = (int *)malloc(capacity * sizeof(int));
    pq->size = 0;
    pq->capacity = capacity;
}

// Helper function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Helper function to resize the heap
void resizeMaxPQ(MaxPriorityQueue *pq) {
    pq->capacity *= 2;
    pq->data = (int *)realloc(pq->data, pq->capacity * sizeof(int));
}

// Insert a value into the Max Priority Queue
void insertMaxPQ(MaxPriorityQueue *pq, int value) {
    if (pq->size == pq->capacity) {
        resizeMaxPQ(pq);
    }
    pq->data[pq->size] = value;
    int i = pq->size;
    pq->size++;

    // Heapify up
    while (i != 0 && pq->data[(i - 1) / 2] < pq->data[i]) {
        swap(&pq->data[i], &pq->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Get the maximum element (root of the heap)
int getMax(MaxPriorityQueue *pq) {
    if (pq->size == 0) return INT_MIN;
    return pq->data[0];
}

// Extract the maximum element from the Max Priority Queue
int extractMax(MaxPriorityQueue *pq) {
    if (pq->size == 0) return INT_MIN;

    int max = pq->data[0];
    pq->data[0] = pq->data[pq->size - 1];
    pq->size--;

    // Heapify down
    int i = 0;
    while ((2 * i + 1) < pq->size) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < pq->size && pq->data[left] > pq->data[largest]) {
            largest = left;
        }
        if (right < pq->size && pq->data[right] > pq->data[largest]) {
            largest = right;
        }
        if (largest == i) break;

        swap(&pq->data[i], &pq->data[largest]);
        i = largest;
    }

    return max;
}

// Check if the Max Priority Queue is empty
bool isMaxPQEmpty(MaxPriorityQueue *pq) {
    return pq->size == 0;
}

// Get the current size of the Max Priority Queue
int maxPQSize(MaxPriorityQueue *pq) {
    return pq->size;
}

// Free the Max Priority Queue
void freeMaxPriorityQueue(MaxPriorityQueue *pq) {
    free(pq->data);
    pq->data = NULL;
    pq->size = 0;
    pq->capacity = 0;
}

// Utility function for testing the Max Priority Queue
void testMaxPriorityQueue() {
    MaxPriorityQueue pq;
    initMaxPriorityQueue(&pq, 4);

    insertMaxPQ(&pq, 3);
    insertMaxPQ(&pq, 1);
    insertMaxPQ(&pq, 6);
    insertMaxPQ(&pq, 5);
    insertMaxPQ(&pq, 2);
    insertMaxPQ(&pq, 4);

    printf("Max Element: %d\n", getMax(&pq)); // Should print 6
    printf("Extract Max: %d\n", extractMax(&pq)); // Should print 6
    printf("Max Element after extraction: %d\n", getMax(&pq)); // Should print 5

    while (!isMaxPQEmpty(&pq)) {
        printf("Extract Max: %d\n", extractMax(&pq)); // Should print remaining elements in descending order
    }

    freeMaxPriorityQueue(&pq);
}
