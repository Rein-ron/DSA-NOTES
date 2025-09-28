#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct node{
    int data;
    struct node* next;
}Node;

typedef struct Stack{
   Node* top;
}Stack;

Stack* init(){
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

void push(Stack* S, int data){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = S->top;
    S->top = newNode;
}

int pop(Stack* S){
    int value;
    if(!isEmpty(S)){
        Node* temp = S->top;
        value = S->top->data;
        S->top = temp->next;
        free(temp);
    }

    return value;
}

int peek(Stack* S){
    return S->top->data;
}

void reversedStack(Stack* S){
    Stack* tempStack = init();
    Stack* tempStack2 = init();

    while(!isEmpty(S)){
        push(tempStack, pop(S));
    }

    while(!isEmpty(tempStack)){
        push(tempStack2, pop(tempStack));
    }

    while(!isEmpty(tempStack2)){
        push(S, pop(tempStack2));
    }

}

void middle(Stack* S){
    Stack* temp = init();
    int count = 0;
    
    int value;
    while(!isEmpty(S)){
        push(temp, pop(S));
        count++;
    }

    int middle = count / 2;
    int middleValue = 0;
    int current = 0;

    while(!isEmpty(temp)){   
        value = pop(temp);
        if(current == middle){
            middleValue = value;
        }else{
            push(S, value);
        }
        current++;
    }

    printf("Deleted Middle Element: %d\n", middleValue);
}

void AvgValue(Stack* S){
    Stack* temp = init();
    int count = 0;
    float sum = 0;
    int value;

    while(!isEmpty(S)){
        value = pop(S);
        sum += value;
        push(temp, value);
        count++;
    }

    while(!isEmpty(temp)){
        push(S, pop(temp));
    }

    printf("Average of the said stack: %.2f\n", sum / count);
}


void ElementRetrieval(Stack* S, int index){
    printf("Top element: %d\n", peek(S));
    Stack* temp = init();
    int count = 0;
    int value;

    while(!isEmpty(S)){
        push(temp, pop(S));
    }

    while(!isEmpty(temp)){
        value = pop(temp);
        if(count == index){
            if(index == 2){
             printf("%dnd element from top: %d\n",index, value);
            }else if(index == 3){
             printf("%drd element from top: %d\n",index, value);
            }else{
             printf("%dth element from top: %d\n",index, value);
            }
            
        }else{
            push(S, value);
        }
        count++;    
    }

}

void display(Stack* S){
    Node* trav = S->top;

    while(trav != NULL){
        printf("%d ", trav->data);
        trav = trav->next;
    }

    printf("\n");
}

int main(){
    Stack* S = init();

    push(S, 1);
    push(S, 2);
    push(S, 3);
    push(S, 4);
    push(S, 5);
    push(S, 6);
    display(S);
    reversedStack(S);
    display(S);
    middle(S);
    display(S);
    AvgValue(S);
    ElementRetrieval(S, 3);
}