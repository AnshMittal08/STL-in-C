#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include "queue.h"

static int* array = NULL;
static int head = 0;
static int tail = 0;
static int N = 0;
static int max_size = 1;

static void resize(int new_size)
{
    int* new_array = (int *)malloc(sizeof(int) * new_size);
    int current_size = size();
    for (int i = 0; i < current_size; i++)
    {
        new_array[i] = array[(head + i) % max_size];
    }

    free(array);
    array = new_array;
    head = 0;
    tail = current_size;
    max_size = new_size;
}

void initQueue()
{
    array = (int *)malloc(sizeof(int));
    head = 0;
    tail = 0;
    N = 0;
    max_size = 1;
}

void enqueue(int item)
{
    if (N == max_size)
    {
        resize(2 * max_size);
    }
    array[tail] = item;
    tail = (tail + 1) % max_size;
    N++;
}

int dequeue()
{
    if (isEmpty()) return INT_MIN;
    int item = array[head];
    head = (head + 1) % max_size;
    N--;
    if (N > 0 && N == max_size / 4)
    {
        resize(max_size / 2);
    }
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
