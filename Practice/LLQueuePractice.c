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

void reversedQueue(Queue* Q){
	int temp[100];
	int top = -1;
	
	while(!isEmpty(Q)){
	   temp[++top] = dequeue(Q);
	}
		
	while(top >= 0){
		enqueue(Q, temp[top--]);	
	}
		
		
}

void SOE(Queue* Q){
	int temp[100];
	int top = -1;
	int value;
	int sum = 0;
	
	while(!isEmpty(Q)){
		value = dequeue(Q);
		sum += value;
		temp[++top] = value;
	}
	
	while(top >= 0){
		enqueue(Q, temp[top--]);
	}
	
	printf("The sum of all elements is %d\n", sum);
}

void AvgValue(Queue* Q){
	int temp[100];
	int top = -1;
	int value;
	float sum = 0;
	int count = 0;
		
	while(!isEmpty(Q)){
		value = dequeue(Q);
		sum += value;
		temp[++top] = value;
		count++;	
	}
	
	while(top >= 0){
		enqueue(Q, temp[top--]);
	}
	
	float avg = sum / count;
	printf("The average value of the Queue is %.2f\n", avg);
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
    printf("Count of the queue is %d\n", count);
    printf("Front of the Queue is %d\n",front(Q));
//     dequeue(Q);
//     dequeue(Q);
//     dequeue(Q);	
	 reversedQueue(Q);
     display(Q);
     SOE(Q);
     AvgValue(Q);
     
}