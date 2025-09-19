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
    if(!isFull(S)){
        S->top++;
        S->items[S->top] = data;
    } 
}

int pop(Stack* S){
    int value;
    if(!isEmpty(S)){
        value = S->items[S->top];
        S->top--;
        return value;
    }else{
        return -1;
    }

    
}

int peek(Stack* S){

    if(S->top == -1){
        printf("Stack is empty!\n");
        return -1;
    }else{
        return S->items[S->top];
    }
}

void searchStack(Stack* S, int data){
    Stack temp;
    init(&temp);
    int found = 0;
    int count = S->top;
          
    while(!(isEmpty(S))){
        int topVal = peek(S);
        if(topVal == data){
            found = 1;
            break;
        }
        push(&temp, pop(S));
    }

    if(found){
        printf("Data %d found in the stack\n", data);
    }

   while(!(isEmpty(&temp))){
        push(S, pop(&temp));  
    }
            
    
}

void reversedStacK(Stack* S){
    Stack temp, temp2;
    init(&temp);
    init(&temp2);
    int value;

    
        while(!isEmpty(S)){
            push(&temp, pop(S));
        }

         while(!isEmpty(&temp)){
            push(&temp2, pop(&temp));
        }
       

        while(!isEmpty(&temp2)){
            push(S, pop(&temp2));
        }
  
    
}

void minimumElement(Stack* S){
    Stack temp;
    init(&temp);
    int min = peek(S);
    int value;
    while(!isEmpty(S)){
        value = pop(S);
        if(min < value) min = value;
            push(&temp, value); 
    }

    while(!isEmpty(&temp)){
        push(S, pop(&temp));
    }

    printf("Minimum Element: %d", min);
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

    // push(&S, 1);
    push(&S, 10);
    push(&S, 8);
    push(&S, 9);
    push(&S, 12);
    push(&S, 23);
    push(&S, 39);
    push(&S, 4);
    push(&S, 5);
    push(&S, 6);
    display(S);
    // pop(&S);
    // pop(&S);
    // pop(&S);
    // printf("top of the stack: %d\n", peek(&S));
    // searchStack(&S, 2);
    // pop(&S);
    reversedStacK(&S);
    display(S);
    minimumElement(&S);


    return 0;
}