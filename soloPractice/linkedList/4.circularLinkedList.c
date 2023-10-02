#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
    struct node* prev;
} node;

void (printLinkedList(node* ptr)) {
while (ptr != NULL) {
    printf("%i\n" , ptr->value);
    ptr = ptr->next;
}
}

int main(void)
{
    node* head = NULL;
    node* n1 = NULL;
    node* n2 = NULL;
    node* n3 = NULL;

    head = malloc(sizeof(node));
    n1 = malloc(sizeof(node));
    n2 = malloc(sizeof(node));
    n3 = malloc(sizeof(node));

    head->value = 1;
    n1->value = 2;
    n2->value = 3;
    n3->value = 4;

    head->next = n1;
    head->prev = n3;

    n1->next = n2;
    n1->prev = head;

    n2->next = n3;
    n2->prev = n1;

    n3->next = head;
    n3->prev = n2;

    printLinkedList(head);
}

/// can be a single or double linked list