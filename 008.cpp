/*
date:
lab set: 8
8. Apply transform and conquer technique to implement a program to construct an AVL Tree for a given set of elements and display balance factor for each node.
*/
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int key;
    int height;
    struct Node *left;
    struct Node *right;
};
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int height(struct Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}
struct Node *newnode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->right = NULL;
    node->left = NULL;
    node->height = 0;
    return node;
}
struct Node *rightRotate(struct Node *root)
{
    struct Node *left_subtree = root->left;
    struct Node *temp = left_subtree->right;
    left_subtree->right = root;
    root->left = temp;
    root->height = height(root);
    left_subtree->height = height(temp);
    return left_subtree;
}
struct Node *leftRotate(struct Node *root)
{
    struct Node *right_subtree = root->right;
    struct Node *temp = right_subtree->left;
    right_subtree->left = root;
    root->right = temp;
    root->height = height(root);
    right_subtree->height = height(right_subtree);
    return right_subtree;
}
int getbalance(struct Node *root)
{
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}
struct Node *insert(struct Node *node, int key)
{
    if (node == NULL)
        return newnode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
    node->height = height(node);
    int balance = getbalance(node);
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d (%d) ", root->key, getbalance(root));
    inorder(root->right);
}
int main()
{
    struct Node *root = NULL;
    int elements[25], n;
    printf("Enter no. of elements to be inserted : ");
    scanf("%d", &n);
    printf("\nEnter the elements of the tree : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &elements[i]);
        root = insert(root, elements[i]);
    }
    printf("\nInorder traversal of the constructed AVL tree :\n");
    inorder(root);
    printf("\n");
    return 0;
}
