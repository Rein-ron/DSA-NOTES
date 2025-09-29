#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct{
    int *elemPtr;
    int count;
    int max;
}List;


void init(List *L){
    L->elemPtr = malloc(sizeof(int) * LENGTH);
    L->count = 0;
    L->max = LENGTH;

     int i;

    for(i = 0;i < LENGTH;i++){
        L->elemPtr[i] = -1;
    }
}

void insertPos(List *L, int data, int position){
    int i;

    for(i = L->count - 1;i >= position;i--){
        L->elemPtr[i + 1] = L->elemPtr[i];
    }

    L->elemPtr[position] = data;
    L->count++;
}

void insertFirst(List *L, int data){
    insertPos(L, data, 0);
} 

void deletePos(List *L, int position){
    int i;

    for(i = position;i < L->count;i++){
        L->elemPtr[i] = L->elemPtr[i + 1];
    }

    L->count--;
}

void deleteFirst(List *L){
    deletePos(L, 0);
}

void deleteLast(List *L){
    deletePos(L, L->count);
}

void display(List *L){
    int i;

    for(i = 0;i < L->count;i++){
        printf("%d ", L->elemPtr[i]);
    }
    printf("\n");
}

int main(){
    List L;

    init(&L);
    insertPos(&L, 10, 0);
    insertPos(&L, 20, 1);
    insertPos(&L, 30, 2);
    display(&L);
    insertFirst(&L, 40);
    insertFirst(&L, 50);
    insertFirst(&L, 60);
    display(&L);
    deletePos(&L, 1);
    display(&L);
    deleteFirst(&L);
    display(&L);
    deleteLast(&L);
    display(&L);
    return 0;
}