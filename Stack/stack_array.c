#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

int* array = NULL;
int N = 0;
int max_size = 1;

void resize(int new_size)
{
    int* new_array = (int *)malloc(sizeof(int) * new_size);
    for (int i = 0; i < N; i++)
    {
        new_array[i] = array[i];
    }

    free(array);
    array = new_array;
    max_size = new_size;
}

void push(int item)
{
    if (array == NULL) 
    {
        array = (int *)malloc(sizeof(int));
    }
    if (N == max_size)
    {
        resize(2 * max_size);
    }
    array[N++] = item;
}

int pop()
{
    if (isEmpty()) return INT_MIN;
    int item = array[--N];
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
