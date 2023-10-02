#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} node;

node* nodeCreate(int value) {
    node* nodeMem = malloc(sizeof(nodeMem));

    nodeMem->value = value;

    nodeMem->left = NULL;
    nodeMem->right = NULL;
    return(nodeMem);
}

void printTree(node* root) {
  if (root == NULL) {
    return;
  }
  printTree(root->left);
  printf("%d\n", root->value);
  printTree(root->right);
}
/// inorder traversal , but can use any format

int main(void)
{
    node* root = nodeCreate(1);

    root->left = nodeCreate(2);
    root->left->left = nodeCreate(3);
    root->left->right = nodeCreate(4);

    root->right = nodeCreate(5);
    root->right->left = nodeCreate(6);
    root->right->right = nodeCreate(7);

    printTree(root);
    return 0;
}