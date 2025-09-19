#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct node{
    int data;
    struct node* next;
}Node;

typedef struct{
    Node* front;
    Node* rear;
}Queue;

Queue* init(){
    Queue* newQueue = malloc(sizeof(Queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;

    return newQueue;
}

bool isFull(Queue* Q){
    return false;
}

bool isEmpty(Queue* Q){
    return Q->front == NULL;
}

void enqueue(Queue* Q, int data){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(isEmpty(Q)){
        Q->front = newNode;
        Q->rear = newNode;
    }else{
        Q->rear->next = newNode;
        Q->rear = newNode;
    }
}

int dequeue(Queue* Q){
    int value;
    if(!isEmpty(Q)){
        Node* temp = Q->front;
        value = Q->front->data;
        Q->front = Q->front->next;

        if(isEmpty(Q)){
            Q->rear = NULL;
        }

        free(temp);
    }else{
        return -1;
    }

    return value;
}

int front(Queue* Q){
    if(isEmpty(Q)){
        return -1;
    }

    return Q->front->data;
}


void display(Queue* Q){
    Node* trav = Q->front;
    
    while(trav != NULL){
        printf("%d ", trav->data);
        trav = trav->next;
    }

    printf("\n");
}

int main(){
    Queue* Q = init();
    int count = 0;
    int value;
    
    while(1){
        printf("Enter a number in the queue: ");
        scanf("%d", &value);

        if(value != -1){
            enqueue(Q, value);
            count++;
        }else{
            break;
        }
    }
   
   
    display(Q);
    printf("Front of the Queue is %d\n",front(Q));
    // dequeue(Q);
    // dequeue(Q);
    // dequeue(Q);
    // display(Q);
}