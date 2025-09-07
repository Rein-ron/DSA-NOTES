#include <stdio.h>
#include <stdlib.h>
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
    Quene* newQueue = malloc(sizeof(Quene));
    newQueue->list.count = 0;
    newQueue->front = -1;
    newQueue->rear = -1;

    return newQueue;
}

bool isFull(Queue *Q){
    if(Q->list.count == MAX){
        return true;
    }

    return false;
}

bool empty(Queue *Q){
    if(Q->list.count == 0){
        return true;
    }

    return false;
}

void enqueue(Queue* Q,int value){
    if(isFull){
        printf("Queue is Full!\n");
        return;
    }

    if(empty){
        Q->front = 0;
        Q->rear = 0;
    }
}

int main(){
    Queue* Q = init();

}
