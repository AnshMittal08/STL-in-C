#ifndef BINARY_TREE_H
#define BINARY_TREE_H

// Definition of the binary tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function prototypes
Node* createNode(int data);
void insertLeft(Node* parent, int data);
void insertRight(Node* parent, int data);
void inorderTraversal(Node* root);
void preorderTraversal(Node* root);
void postorderTraversal(Node* root);
int countNodes(Node* root);
int height(Node* root);
int findMax(Node* root);
int findMin(Node* root);
void freeTree(Node* root);

#endif // BINARY_TREE_H