#include <stdio.h>
#include <stdlib.h>
#include "BT.h"

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node to the left of a parent node
void insertLeft(Node* parent, int data) {
    if (parent->left == NULL) {
        parent->left = createNode(data);
    } else {
        printf("Left child already exists. Insertion failed.\n");
    }
}

// Function to insert a node to the right of a parent node
void insertRight(Node* parent, int data) {
    if (parent->right == NULL) {
        parent->right = createNode(data);
    } else {
        printf("Right child already exists. Insertion failed.\n");
    }
}

// Inorder traversal (Left, Root, Right)
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Preorder traversal (Root, Left, Right)
void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Postorder traversal (Left, Right, Root)
void postorderTraversal(Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Count total nodes in the tree
int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Calculate height of the tree
int height(Node* root) {
    if (root == NULL) {
        return -1; // Height of an empty tree is -1
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Find the maximum value in the tree
int findMax(Node* root) {
    if (root == NULL) {
        return -1; // Or some error value
    }
    int maxValue = root->data;
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    if (leftMax > maxValue) maxValue = leftMax;
    if (rightMax > maxValue) maxValue = rightMax;
    return maxValue;
}

// Find the minimum value in the tree
int findMin(Node* root) {
    if (root == NULL) {
        return -1; // Or some error value
    }
    int minValue = root->data;
    int leftMin = findMin(root->left);
    int rightMin = findMin(root->right);
    if (leftMin < minValue) minValue = leftMin;
    if (rightMin < minValue) minValue = rightMin;
    return minValue;
}

// Function to free the memory allocated for the tree
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}