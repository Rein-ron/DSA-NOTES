#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Queue{
    Node* front;
    Node* rear;
}Queue;

Queue* initialize(){
    Queue* newQueue = malloc(sizeof(Queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;

    return newQueue;
}

bool isFull(Queue* Q){
    return false;
}

bool isEmpty(Queue* Q){
    return Q->rear == NULL;
}

void enqueue(Queue* Q, int value){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if(isEmpty(Q)){
        Q->front = newNode;
        Q->rear = newNode;
    }else{
         Q->front->next = newNode;
         Q->front = newNode;
    }

}

int dequeue(Queue* Q){
    if(isEmpty(Q)){
        return -1;
    }

    Node* temp = Q->rear;
    int value = temp->data;
    Q->rear = Q->rear->next;

     if(Q->rear == NULL){
        Q->front = NULL;
    }

    free(temp);
    return value;
}

int front(Queue* Q){
    if(Q->rear == NULL){
        return -1;
    }

    return Q->rear->data;
}

void display(Queue* Q){
    if(isEmpty(Q)){
        return;
    }
    Node* trav = Q->rear;

    while(trav != NULL){
        printf("%d ", trav->data);
        trav = trav->next;
    }

    printf("\n");
}


int main(){
    Queue* Q = initialize();

    enqueue(Q, 10);
    enqueue(Q, 20);
    enqueue(Q, 30);
    enqueue(Q, 40);
    display(Q);
    dequeue(Q);
    dequeue(Q);
    display(Q);
}