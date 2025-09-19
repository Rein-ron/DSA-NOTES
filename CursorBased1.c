#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct{
    int elem;
    int next;
}Cell, HeapSpace[MAX];

typedef struct{
    HeapSpace H;
    int avail;
}VHeap;

void initialize(VHeap* V){
    V->avail = 0;
    int i;
    for(i = 0;i < MAX;i){
        V->H[i].next = i + 1;
    }
    V->H[MAX - 1].next = -1;
}

int alloc(VHeap* V){
    int L = V->avail;
    if(L != 1){
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
    }
    *L = newCell;
}

void insertLast(int* L, VHeap* V, int elem){
   int newCell = alloc(V);
   if(newCell != -1){
       V->H[newCell].elem = elem;

        if(*L == -1){
            *L == newCell;
        }else{
            int p;
            for(p = L;V->H[p].next != -1;p = &V->H[p].next){}
            V->H[p].next = newCell;
        }   
   }
}

void insertSorted(int* L, VHeap* V, int elem){

}

void delete(int* L, VHeap* V, int elem){
 
}

void deleteAllOccur(int* L, VHeap* V,int elem){

}

void display(int L, VHeap V){
}

int main(){
    VHeap V;
    int L = -1;

    return 0;
}