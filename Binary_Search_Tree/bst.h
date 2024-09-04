#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

TreeNode* createNode(int data);
TreeNode* insertNode(TreeNode *root, int data);
TreeNode* deleteNode(TreeNode* root, int data);
TreeNode* findMin(TreeNode* root);
TreeNode* searchNode(TreeNode *root, int data);

void inorderTraversal(TreeNode *root);
void postorderTraversal(TreeNode *root);
void preorderTraversal(TreeNode *root);
void freeTree(TreeNode *root);

#endif