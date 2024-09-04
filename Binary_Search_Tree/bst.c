#include"bst.h"

TreeNode* createNode(int data)
{
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if(!newNode)
    {
        printf("Memory Allocation Error!!\n");
        exit(1);
    }

    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode* insertNode(TreeNode *root, int data)
{
    if(root == NULL) root = createNode(data);
    else if(data <= root->data)
    {
        root->left = insertNode(root->left,data);
    }
    else{
    root->right = insertNode(root->right,data);
    }

    return root;
}

TreeNode* findMin(TreeNode *root)
{
    while (root->left != NULL) 
    {
        root = root->left;
    }
    return root;
}

TreeNode* deleteNode(TreeNode *root, int data)
{
    if(root==NULL) return root;

    if(data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if(data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        if(root->left == NULL)
        {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        } else if(root->right == NULL){
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        TreeNode *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

TreeNode* searchNode(TreeNode *root, int data)
{
    if(root == NULL || root->data == data)
    {
        return root;
    }
    if(data < root->data)
    {
        return searchNode(root->left,data);
    }
    else
    {
        return searchNode(root->right, data);
    }
}

void inorderTraversal(TreeNode *root)
{
    if(root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(TreeNode *root)
{
    if(root!=NULL)
    {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(TreeNode *root)
{
    if(root!=NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ",root->data);
    }
}

void freeTree(TreeNode *root)
{
    if(root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}