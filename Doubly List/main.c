#include "doubly_list.h"
#include <stdio.h>

int main() {
    DoublyList list;
    initList(&list);

    // Append elements
    append(&list, 10);
    append(&list, 20);
    append(&list, 30);

    // Print list
    printf("List after appending 10, 20, 30:\n");
    printList(&list);

    // Prepend elements
    prepend(&list, 5);
    prepend(&list, 1);

    // Print list
    printf("List after prepending 5, 1:\n");
    printList(&list);

    // Insert at specific position
    insertAt(&list, 2, 15); // Insert 15 at index 2

    // Print list
    printf("List after inserting 15 at index 2:\n");
    printList(&list);

    // Delete a node
    Node *nodeToDelete = list.head->next; // Assuming we want to delete the second node
    deleteNode(&list, nodeToDelete);

    // Print list
    printf("List after deleting second node:\n");
    printList(&list);

    // Free the list
    freeList(&list);

    return 0;
}
