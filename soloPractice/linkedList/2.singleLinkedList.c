#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* next;
}
node;

void printLinkedList(node* ptr)
{
    while (ptr != NULL)
    {
        printf("%i\n" , ptr->value);
        ptr = ptr->next;
    }
}

int main(void)
{
    node* head;
    node* n1;
    node* n2;

    head = malloc(sizeof(node));
    n1 = malloc(sizeof(node));
    n2 = malloc(sizeof(node));

    head->value = 1;
    head->next = n1;

    n1->value = 2;
    n1->next = n2;

    n2->value = 3;
    n2->next = NULL;

    printLinkedList(head);
}