#include <stdio.h>
#include "BT.h"

int main() {
    // Create root node
    Node* root = createNode(1);

    // Insert nodes
    insertLeft(root, 2);
    insertRight(root, 3);
    
    insertLeft(root->left, 4);  // Left of 2
    insertRight(root->left, 5); // Right of 2
    
    insertLeft(root->right, 6); // Left of 3
    insertRight(root->right, 7); // Right of 3

    // Traversal
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    // Count nodes
    printf("Total number of nodes: %d\n", countNodes(root));

    // Height of the tree
    printf("Height of the tree: %d\n", height(root));

    // Find maximum and minimum values
    printf("Maximum value in the tree: %d\n", findMax(root));
    printf("Minimum value in the tree: %d\n", findMin(root));

    // Free memory
    freeTree(root);
    return 0;
}