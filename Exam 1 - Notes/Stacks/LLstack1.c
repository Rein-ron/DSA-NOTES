#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Stack{
    Node* top;
}Stack;

Stack* initialize(){
    Stack* newStack = malloc(sizeof(Stack));
    newStack->top = NULL;

    return newStack;
}

bool isFull(Stack* S){
    return false;
}

bool isEmpty(Stack* S){
    return S->top == NULL; 
}

void push(Stack* S, int value){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = S->top;
    S->top = newNode;
    
}

void pop(Stack* S){
    if(isEmpty(S)){
        return;
    }

    Node* temp = S->top;
    int value = S->top->data;
    S->top = S->top->next;
    free(temp);

    // return value; if asking to return value turn data type to int
}

int peek(Stack* S){
    if(isEmpty(S)){
        return -1;
    };

    return S->top->data;
}

void display(Stack* S){
    if(isEmpty(S)){
        printf("Stack is empty.\n");
        return;
    }
    Node* trav = S->top;

    while(trav != NULL){
        printf("%d ", trav->data);
        trav = trav->next;
    }

    printf("\n");
}

int main(){
    Stack* S = initialize();

    push(S, 10);
    push(S, 20);
    push(S, 30);
    push(S, 40);
    display(S);
    pop(S);
    pop(S);
    display(S);
    return 0;
}


