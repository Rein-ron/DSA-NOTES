#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 12

typedef struct{
    int elem;
    int next;
}Cell, HeapSpace[MAX];

typedef struct{
    HeapSpace H;
    int avail;
}VHeap;

void init(VHeap *V){
    V->avail = 0;
    int i;
    for(i = 0; i < MAX;i++){
        V->H[i].next = i + 1;
    }
    V->H[MAX - 1].next = -1;

}

int alloc(VHeap* V){
    int L = V->avail;
    if(L != -1){
        V->avail = V->H[L].next;
    }

    return L;
}

void dealloc(VHeap* V, int index){
    V->H[index].next = V->avail;
    V->avail = index;
}

void insertFirst(int* L, VHeap* V, int elem){
    int newCell = alloc(V);
    if(newCell != -1){
        V->H[newCell].elem = elem;
        V->H[newCell].next = *L;
        *L = newCell;
    }
   
}

void insertLast(int* L, VHeap* V, int elem){
    int newCell = alloc(V);
    if(newCell != -1){
        V->H[newCell].elem = elem;
        V->H[newCell].next = -1;
        if(*L == -1){
            *L = newCell;
        }else{
            int p;
            for(p = *L;V->H[p].next != -1;p = V->H[p].next){}
            V->H[p].next = newCell;
        }
    }
}

void insertSorted(int* L, VHeap* V, int elem){
    int newCell = alloc(V);
    if(newCell != -1){
        V->H[newCell].elem = elem;
        V->H[newCell].next = -1;

        if(*L == -1 || elem < V->H[*L].elem){
            V->H[newCell].next = *L;
            *L = newCell;
        }else{
            int p;
            for(p = *L;V->H[p].next != -1 && V->H[V->H[p].next].elem < elem;p = V->H[p].next){}
            V->H[newCell].next = V->H[p].next;
            V->H[p].next = newCell;
        }
    }
}

void delete(int* L, VHeap* V, int elem){
    int* p;
    for(p = L;*p != -1 && V->H[*p].elem != elem;p = &V->H[*p].next){}
    
    if(*p != -1){
        int del = *p;
        *p = V->H[del].next;
        dealloc(V, del);
    }
}

void deleteAllOccur(int* L, VHeap* V, int elem){
     int* p;

     for(p = L;*p != -1;){
        if(V->H[*p].elem == elem){
                int del = *p;
                *p = V->H[del].next;
                dealloc(V, del);
            }else{
                p = &V->H[*p].next;
        }
     }
}
void display(int L, VHeap V){
    int i;

    for(i = L;i != -1;i = V.H[i].next){
        printf("%d ", V.H[i].elem);
    }

    printf("\n");
}

int main(){
    VHeap H;
    int L  = -1;

    init(&H);
    insertFirst(&L, &H, 10);
    insertFirst(&L, &H, 20);
    insertFirst(&L, &H, 30);
    insertFirst(&L, &H, 40);
    display(L, H);
    insertLast(&L, &H, 50);
    insertLast(&L, &H, 60);
    insertLast(&L, &H, 70);
    display(L, H);
    insertSorted(&L, &H, 25);
    insertSorted(&L, &H, 15);
    display(L, H);
    delete(&L, &H, 10);
    delete(&L, &H, 40);
    display(L, H);
    insertFirst(&L, &H, 10);
    insertFirst(&L, &H, 10);
    insertFirst(&L, &H, 10);
    display(L, H);
    deleteAllOccur(&L, &H, 10);
    display(L, H);
    return 0;
}