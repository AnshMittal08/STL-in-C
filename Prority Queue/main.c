#include "maxPQ.h"
#include "minPQ.h"
#include <stdio.h>
#include <assert.h>

// Test Max Priority Queue
void testMaxPriorityQueue() {
    MaxPriorityQueue maxPQ;
    initMaxPriorityQueue(&maxPQ, 4);

    insertMaxPQ(&maxPQ, 10);
    insertMaxPQ(&maxPQ, 20);
    insertMaxPQ(&maxPQ, 5);
    insertMaxPQ(&maxPQ, 30);

    printf("Max Priority Queue:\n");
    printf("Max Element: %d\n", getMax(&maxPQ)); // Should print 30
    printf("Extract Max: %d\n", extractMax(&maxPQ)); // Should print 30
    printf("Max Element after extraction: %d\n", getMax(&maxPQ)); // Should print 20

    while (!isMaxPQEmpty(&maxPQ)) {
        printf("Extract Max: %d\n", extractMax(&maxPQ)); // Should print remaining elements in descending order
    }

    freeMaxPriorityQueue(&maxPQ);
}

// Test Min Priority Queue
void testMinPriorityQueue() {
    PriorityQueue minPQ;
    initMinPriorityQueue(&minPQ, 4);

    insertMinPQ(&minPQ, 10);
    insertMinPQ(&minPQ, 20);
    insertMinPQ(&minPQ, 5);
    insertMinPQ(&minPQ, 30);

    printf("Min Priority Queue:\n");
    printf("Min Element: %d\n", getMin(&minPQ)); // Should print 5
    printf("Extract Min: %d\n", extractMin(&minPQ)); // Should print 5
    printf("Min Element after extraction: %d\n", getMin(&minPQ)); // Should print 10

    while (!isMinPQEmpty(&minPQ)) {
        printf("Extract Min: %d\n", extractMin(&minPQ)); // Should print remaining elements in ascending order
    }

    freeMinPriorityQueue(&minPQ);
}

int main() {
    testMaxPriorityQueue();
    testMinPriorityQueue();
    return 0;
}
