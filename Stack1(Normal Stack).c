#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int items[MAX];
    int top;
}Stack;

Stack* init(){
    Stack* newStack = malloc(sizeof(Stack));
    newStack->top = -1;

    return newStack;
}

void push(Stack* S, int data){
    if(S->top > MAX){
        printf("Overflow!\n");
        return;
    }
    S->top++;
    S->items[S->top] = data;
}

void pop(Stack* S){
    if(S->top < 0){
        printf("Underflow!\n");
        return;
    }
    S->top--;
}

void peek(Stack* S){
    if(S->top == -1) return;
    
    printf("Top of the Stack is %d.", S->items[S->top]);
}

void display(Stack* S){
    int i;

    for(i = 0;i <= S->top;i++){
        printf("%d ", S->items[i]);
    }

    printf("\n");
}

int main(){
    Stack* S = init();

    push(S, 1);
    push(S, 3);
    push(S, 5);
    push(S, 6);
    push(S, 7);
    display(S);
    pop(S);
    display(S);
}