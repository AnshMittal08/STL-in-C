// main.c
#include "DeQue.h"

int main() {
    Deque *deque = createDeque();

    insertFront(deque, 10);
    insertRear(deque, 20);
    insertFront(deque, 5);
    insertRear(deque, 30);

    printf("Front element: %d\n", getFront(deque));
    printf("Rear element: %d\n", getRear(deque));

    displayDeque(deque);

    printf("Inserting 15 at position 2:\n");
    insertAt(deque, 15, 2);  // Insert 15 at position 2
    displayDeque(deque);

    printf("Deleting from front: %d\n", deleteFront(deque));
    printf("Deleting from rear: %d\n", deleteRear(deque));

    displayDeque(deque);

    printf("Clearing the deque.\n");
    clearDeque(deque);
    displayDeque(deque);

    freeDeque(deque);
    return 0;
}
