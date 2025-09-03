#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct node{
    int data;
    struct node* next;
}Node;

typedef struct{
    Node* head;
    int count;
}List;

List* init()
