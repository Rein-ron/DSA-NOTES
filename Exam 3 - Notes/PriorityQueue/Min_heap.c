#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int id;
    int priority;
} Item;

typedef struct {
    Item heap[MAX];
    int size;
} PriorityQueue;

void swap(Item *a, Item *b){
    Item temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(PriorityQueue *pq, int index){
    if(index == 0) return;
    int parent = (index - 1) / 2;
    if(pq->heap[parent].priority > pq->heap[index].priority){
        swap(&pq->heap[parent], &pq->heap[index]);
        heapifyUp(pq, parent);
    }
}

void insert(PriorityQueue *pq, Item it){
    if(pq->size == MAX) return;
    pq->heap[pq->size] = it;
    pq->size++;
    heapifyUp(pq, pq->size - 1);
}

void initQueue(PriorityQueue *pq){
    pq->size = 0;
}

void printQueue(PriorityQueue *pq){
    printf("Current MIN Heap Queue:\n");
    for(int i = 0; i < pq->size; i++){
        printf("Item ID: %d, Priority: %d\n", pq->heap[i].id, pq->heap[i].priority);
    }
    printf("\n");
}

int main(){
    PriorityQueue pq;
    initQueue(&pq);

    insert(&pq, (Item){1, 50});
    insert(&pq, (Item){2, 30});
    insert(&pq, (Item){3, 40});
    insert(&pq, (Item){4, 60});

    printQueue(&pq);

    return 0;
}
