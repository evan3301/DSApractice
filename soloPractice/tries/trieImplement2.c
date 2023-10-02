/// also known as prefix tree

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/// stores all ASCII strings
#define NUM_CHAR 256

typedef struct trieNode {
    /// children are array of trieNode pointers
    struct trieNode *children[NUM_CHAR];

    /// indicates end of word
    bool terminalNode;
} trieNode;

trieNode *createNode() {
    trieNode *newNode = malloc(sizeof(newNode));

    /// initializes all children as NULL to start
    for (int i = 0; i < NUM_CHAR; i++) {
        newNode->children[i] = NULL;
    }

    newNode->terminalNode = false;
    return newNode;
}

bool trieInsert(trieNode **root , char *signedText) {

    /// double pointer to change root
    if (*root == NULL) {
        *root = createNode();
    }

    /// ensures lack of negative strings
    unsigned char *text = (unsigned char*)signedText;

    /// temp pointer to traverse tree , starting at root
    trieNode *tmp = *root;
    int length = strlen(signedText);

    /// moving through string via tmp pointer , creating new nodes where NULL
    for (int i = 0; i < length; i++) {
        if (tmp->children[text[i]] == NULL) {
            tmp->children[text[i]] = createNode();
        }
        tmp = tmp->children[text[i]];
    }

    /// checks if string is already in trie , else inserts terminal where word would end
    if (tmp->terminalNode) {
        return false;
    } else {
        tmp->terminalNode = true;
        return true;
    }
}

void printTrieStr(trieNode *node , unsigned char *prefix , int length) {
    /// prefix meaning the history of nodes so far

    /// leaves room for an extra character + the nul character
    unsigned char newPrefix[length + 2];
    /// copies old prefix to new prefix
    memcpy(newPrefix, prefix, length);
    /// NULL terminates to stop memory overflow
    newPrefix[length + 1] = 0;

    /// basecase 1
    if (node->terminalNode) {
        printf("WORD: %s\n" , prefix);
    }

    /// basecase 2
    for (int i = 0; i < NUM_CHAR; i++) {
        /// if more child nodes after terminalNode , recurse into newPrefix and print
        if (node->children[i] != NULL) {
            newPrefix[length] = i;
            printTrieStr(node->children[i] , newPrefix, length + 1);
        }
    }
}

void printTrie(trieNode *root) {
    if (root == NULL) {
        printf("Trie is empty \n");
        return;
    }

    printTrieStr(root , NULL , 0);
}

int main(void)
{
    trieNode *root = NULL;

    trieInsert(&root , "CAMP");
    trieInsert(&root , "CAT");
    trieInsert(&root , "CATTLE");
    trieInsert(&root , "KIN");
    trieInsert(&root , "SCOOP");
    printTrie(root);
}