#include <stdio.h>
#include <stdlib.h>

#define alphaSize 26

typedef struct trie {
    int value;
    struct trie* character[alphaSize];
} trie;

trie* getNew() {
    trie* node = malloc(sizeof(trie));
    node->value = 0;

    for (int i = 0; i < alphaSize; i++) {
        node->character[i] = NULL;
    }
    return node;
}

void insert (trie* head , char* str) {

    /// start from root node 'head'
    trie* current = head;

    /// base case 1 = in case of NULL , insert new
    while (*str) {
        if (current->character [*str - 'a'] == NULL) {
            current->character [*str - 'a'] = getNew();
        }

        /// move to next node
        current = current->character[*str - 'a'];

        /// move to next character
        str++;
    }

    /// mark current node
    current->value = 1;
}

int search (trie* head , char* str) {

    /// if trie is empty
    if (head == NULL) {
        return 1;
    }

    trie* current = head;
    while (*str) {

        /// move to next node
        current = current->character[*str - 'a'];

        /// if node is empty ; string not found
        if (current == NULL) {
            return 1;
        }

        /// move to next character
        str++;
    }
    return current->value;
}

int main()
{
    trie* head = getNew();

    insert(head , "hello");
    printf("%d \n" , search(head , "hello"));

    insert(head , "hi");;
    printf("%d \n" , search(head , "hi"));

    insert(head , "howdy");
    printf("%d \n" , search(head , "howdy"));

    printf("%d \n" , search(head , "hmm"));

    return 0;
}