#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

void initQueue();

void enqueue(int item);

int dequeue();

int size();

bool isEmpty();

void testQueue();

#endif
