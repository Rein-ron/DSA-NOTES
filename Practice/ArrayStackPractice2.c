#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct{
    int items[MAX];
    int top;
}Stack;


void init(Stack* S){
    S->top = -1;
}

bool isFull(Stack* S){
    return S->top == MAX - 1;
}

bool isEmpty(Stack* S){
    return S->top == -1;
}

void push(Stack* S, int data){
    if(isFull(S)){
        return;
    }
    S->top++;
    S->items[S->top] = data;
}

int pop(Stack* S){
    int value;

    if(isEmpty(S)){
        return -1;
    }
    value = S->items[S->top];
    S->top--;
    return value;
}

int peek(Stack* S){
    if(isEmpty(S)){
        return -1;
    }
    return S->items[S->top];
}



void display(Stack S){
    int i;

    for(i = 0;i <= S.top;i++){
        printf("%d ", S.items[i]);
    }

    printf("\n");
}

int main(){
    Stack S; 
    init(&S);

    push(&S, 10);
    push(&S, 20);
    push(&S, 30);
    push(&S, 40);
    display(S);
    // pop(&S);
    // pop(&S);
    display(S);
}