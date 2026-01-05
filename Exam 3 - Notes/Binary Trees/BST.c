#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 100

typedef struct node {
    char *key;
    struct node* LC;
    struct node* RC;
} Node, *BST;

void insert(BST *tree, const char *key_data) {
    Node **trav;
    for(trav = tree; *trav != NULL && strcmp((*trav)->key, key_data) != 0;) {
        if(strcmp((*trav)->key, key_data) < 0) {
            trav = &(*trav)->RC;
        } else {
            trav = &(*trav)->LC;
        }
    }
    if(*trav == NULL) {
        Node* temp = malloc(sizeof(Node));
        if(temp != NULL) {
            temp->key = strdup(key_data);
            temp->LC = temp->RC = NULL;
            *trav = temp;
            printf("Inserted key: \"%s\"\n", key_data);
        }
    } else {
        printf("Key \"%s\" already exists. Ignoring.\n", key_data);
    }
}

BST findMin(BST tree) {
    while(tree && tree->LC != NULL) tree = tree->LC;
    return tree;
}

BST deleteNode(BST tree, const char *key_data) {
    if(tree == NULL) return NULL;

    int cmp = strcmp(key_data, tree->key);

    if(cmp < 0) {
        tree->LC = deleteNode(tree->LC, key_data);
    } else if(cmp > 0) {
        tree->RC = deleteNode(tree->RC, key_data);
    } else { 
        if(tree->LC == NULL) {
            BST temp = tree->RC;
            free(tree->key);
            free(tree);
            return temp;
        } else if(tree->RC == NULL) {
            BST temp = tree->LC;
            free(tree->key);
            free(tree);
            return temp;
        } else {
            BST temp = findMin(tree->RC);
            free(tree->key);
            tree->key = strdup(temp->key);
            tree->RC = deleteNode(tree->RC, temp->key);
        }
    }
    return tree;
}

void inorderTraversal(BST tree) {
    if(tree == NULL) return;
    inorderTraversal(tree->LC);
    printf("\"%s\" ", tree->key);
    inorderTraversal(tree->RC);
}

void preorderTraversal(BST tree) {
    if(tree == NULL) return;
    printf("\"%s\" ", tree->key);
    preorderTraversal(tree->LC);
    preorderTraversal(tree->RC);
}

void postorderTraversal(BST tree) {
    if(tree == NULL) return;
    postorderTraversal(tree->LC);
    postorderTraversal(tree->RC);
    printf("\"%s\" ", tree->key);
}

void destroyTree(BST tree) {
    if(tree != NULL) {
        destroyTree(tree->LC);
        destroyTree(tree->RC);
        if(tree->key != NULL) free(tree->key);
        free(tree);
    }
}

int main() {
    BST myTree = NULL;

    insert(&myTree, "Mero");
    insert(&myTree, "Alice");
    insert(&myTree, "Bob");
    insert(&myTree, "Charlie");
    insert(&myTree, "Diana");
    insert(&myTree, "Eve");
    insert(&myTree, "Frank");

    insert(&myTree, "Mero"); 

    printf("\n--- BST Traversal Results ---\n");

    printf("1. In-Order Traversal:\n   ");
    inorderTraversal(myTree);
    printf("\n\n");

    printf("2. Pre-Order Traversal:\n   ");
    preorderTraversal(myTree);
    printf("\n\n");

    printf("3. Post-Order Traversal:\n   ");
    postorderTraversal(myTree);
    printf("\n\n");

 
    printf("--- Deleting \"Charlie\" ---\n");
    myTree = deleteNode(myTree, "Charlie");

    printf("In-Order After Deletion:\n   ");
    inorderTraversal(myTree);
    printf("\n\n");

    destroyTree(myTree);
    printf("Tree destroyed and memory freed.\n");

    return 0;
}
