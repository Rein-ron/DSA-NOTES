#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    int items[MAX];
    int count;
}List;

typedef struct {
    List list;
    int front;
    int rear;
}Queue;

Queue* init(){
    Queue* newQueue = malloc(sizeof(Queue));
    newQueue->list.count = 0;
    newQueue->front = -1;
    newQueue->rear = -1;

    return newQueue;
}

bool isFull(Queue *Q){
    return Q->list.count == MAX;
}

bool empty(Queue *Q){
    return Q->list.count == 0;
}

void enqueue(Queue* Q,int value){
    if(isFull(Q)){
        printf("Queue is Full!\n");
        return;
    }

    if(empty(Q)){
        Q->front = 0;
        Q->rear = 0;
    }else{
     Q->rear = (Q->rear + 1) % MAX;
    }

    Q->list.items[Q->rear] = value;
    Q->list.count++;

}

int dequeue(Queue* Q){
    if(empty(Q)){
        printf("Queue is empty!\n");
        return -1;
    }

    int value = Q->list.items[Q->front];

    if(Q->list.count == 1){
        Q->front = -1;
        Q->rear = -1;
    }else{
        Q->front = (Q->front + 1) % MAX;
    }
    
    Q->list.count--;
    return value;
}

void display(Queue* Q){

    int i, index;

    for(i = 0, index = Q->front;i < Q->list.count;i++){
        printf("%d ", Q->list.items[index]);
        index = (index + 1) % MAX;
    }

    printf("\n");
}
int main(){
    Queue* Q = init();

    enqueue(Q, 10);
    enqueue(Q, 20);
    enqueue(Q, 30);
    display(Q);
    int catcher = dequeue(Q);
    display(Q);
    if(catcher != -1){
        printf("%d is removed from the queue.", catcher);
    }

    return 0;
}
