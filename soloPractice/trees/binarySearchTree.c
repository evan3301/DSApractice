#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool insertNum(node** rootptr , int value) {
    node* root = *rootptr;

    // basecase 1
    if (root == NULL) {
        *rootptr = nodeCreate(value);
        return true;
    }
    // basecase 2
    if (value == root->value) {
        return false;
    }

    if (value < root->value) {
        return insertNum(&(root->left) , value);
    } else {
        return insertNum(&(root->right) , value);
    }
}

bool findNum(node* root , int value) {

    /// basecase 1
    if (root == NULL) {
        return false;
    }
    /// basecase 2
    if (root->value == value) {
        return true;
    }

    if (value < root->value) {
        return findNum(root->left , value);
    } else {
        return findNum(root->right , value);
    }
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
    node* root = NULL;

    insertNum(&root , 12);
    insertNum(&root , 13);
    insertNum(&root , 17);
    insertNum(&root , 20);
    insertNum(&root , 11);
    insertNum(&root , 14);
    insertNum(&root , 19);

    printTree(root);

    printf("%d (%d)\n" , 16 , findNum(root , 16));
    printf("%d (%d)\n" , 19 , findNum(root , 19));

    return 0;
}