#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}List;

List init(List L){
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int pos){
    int i;

   if(pos < 0 || pos > L.count || L.count == MAX){
      return L;
   }

    for(i = L.count;i > pos;i--){
        L.elem[i] = L.elem[i - 1];
    }

    L.elem[pos] = data;
    L.count++;

    return L;
}

List insertFirst(List L, int data){
    return insertPos(L, data, 0);
}

List insertLast(List L, int data){
    return insertPos(L, data, L.count);
}

List deletePos(List L, int pos){
    int i;

    if(pos < 0 || pos >= L.count){
        return L;
    }

    for(i = pos;i < L.count - 1;i++){
        L.elem[i] = L.elem[i + 1];
    }
    L.count--;

    return L;
}

void display(List L){
    int i;

    for(i = 0;i < L.count;i++){
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}

int main(){
    List L;
    L = init(L);
    L = insertFirst(L, 10);
    L = insertFirst(L, 20);
    L = insertFirst(L, 30);
    L = insertFirst(L, 40);
    display(L);
    L = insertPos(L, 50, 3);
    L = insertPos(L, 60, 4);
    L = insertPos(L, 70, 1);
    display(L);
    L = deletePos(L, 2);
    L = deletePos(L ,1);
    L = deletePos(L, 4);
    display(L);
}