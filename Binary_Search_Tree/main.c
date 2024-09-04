#include "bst.h"
#include <assert.h>

// Function to display the menu
void printMenu() {
    printf("\nBinary Tree Operations:\n");
    printf("1. Insert Nodes (Array Input)\n");
    printf("2. Delete Node\n");
    printf("3. Search Node\n");
    printf("4. Inorder Traversal\n");
    printf("5. Preorder Traversal\n");
    printf("6. Postorder Traversal\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

// Function to handle array input for inserting multiple nodes
void insertArray(TreeNode **root) {
    int n;
    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    int *array = (int *)malloc(n * sizeof(int));
    printf("Enter the elements (space-separated): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < n; i++) {
        *root = insertNode(*root, array[i]);
    }

    free(array); // Free the dynamically allocated memory
}

int main() {
    TreeNode *root = NULL;
    int choice, data;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertArray(&root);  // Insert nodes from array input
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 3:
                printf("Enter data to search: ");
                scanf("%d", &data);
                TreeNode *foundNode = searchNode(root, data);
                if (foundNode != NULL) {
                    printf("Node found: %d\n", foundNode->data);
                } else {
                    printf("Node not found\n");
                }
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 7:
                freeTree(root);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
