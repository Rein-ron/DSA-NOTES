#include <stdio.h>
#include <stdbool.h>
#define MAX 8

void init(unsigned char *set){
    *set = 0;
}

void insert(unsigned char *set, int elem){
    if(elem >= 0 && elem < MAX){
        unsigned char mask = 1 << elem;
        *set |= mask;
    }
}

void delete(unsigned char *set, int elem){
    if(elem >= 0 && elem < MAX){
        unsigned char mask = 1 << elem;
        *set &= (~mask);
    }
}

bool find(unsigned char *set, int elem){
    if(elem >= 0 && elem < MAX){
        unsigned char mask = 1 << elem;
        return (*set & mask) != 0;
    }
   return false;
}

unsigned char Union(unsigned char A, unsigned char B){
    return A | B;
}

unsigned char intersection(unsigned char A, unsigned char B){
    return A & B;
}

unsigned char difference(unsigned char A, unsigned char B){
    return A & (~B);
}

void display(unsigned char set){
    int i; 
    int first = 1;
    printf("{");
    for(i = 0;i < MAX;i++){
        if((set >> i) & 1){
          if(!first) printf(",");
          printf("%d", i); 
          first = 0;
        }
        
    }
    printf("}");
    printf("\n");
}

int main(){
    unsigned char A, B, C;
    init(&A);
    insert(&A, 5);
    insert(&A, 6);
    insert(&A, 2);
    insert(&A, 1);
    insert(&A, 7);
    insert(&B, 4);
    insert(&B, 2);
    insert(&B, 1);
    insert(&B, 3);
    insert(&B, 6);
    display(A);
    display(B);
    C = Union(A, B);
    display(C);
    C = intersection(A, B);
    display(C);
    C = difference(A, B);
    display(C);
    return 0;
}