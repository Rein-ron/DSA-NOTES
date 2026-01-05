#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int value;  
} Node;

typedef struct {
    Node heap[MAX];
    int size;
} PartiallyOrderedTree;


void swap(Node *a, Node *b){
    Node temp = *a;
    *a = *b;
    *b = temp;
}


void heapifyUpMax(PartiallyOrderedTree *tree, int index){
    if(index == 0) return;
    int parent = (index - 1) / 2;
    if(tree->heap[parent].value < tree->heap[index].value){
        swap(&tree->heap[parent], &tree->heap[index]);
        heapifyUpMax(tree, parent);
    }
}

void insertMax(PartiallyOrderedTree *tree, int val){
    if(tree->size == MAX) return;
    tree->heap[tree->size].value = val;
    tree->size++;
    heapifyUpMax(tree, tree->size - 1);
}

void printTree(PartiallyOrderedTree *tree){
    printf("Partial Order Tree (Array Form):\n");
    for(int i = 0; i < tree->size; i++){
        printf("%d ", tree->heap[i].value);
    }
    printf("\n\n");
}


int main(){
    PartiallyOrderedTree tree;
    tree.size = 0;

    insertMax(&tree, 50);
    insertMax(&tree, 30);
    insertMax(&tree, 60);
    insertMax(&tree, 40);

    printTree(&tree); 

    return 0;
}
