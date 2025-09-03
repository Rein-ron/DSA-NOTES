#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int arr[MAX];
    int top;
}List;

void push(List* L, int data){
    
    L->arr[L->top - 1] = data;
    L->top--;
}

void pop(List* L){
    L->top++;
}
void printArr(List L){
    int i;

    for(i = L.top;i < MAX;i++){
        printf("%d ", L.arr[i]);
    }

    printf("\n");
}
int main(){
    List L;
    L.top = MAX;

    push(&L, 1);
    push(&L, 3);
    push(&L, 5);
    printArr(L);
    pop(&L);
    printArr(L);
}