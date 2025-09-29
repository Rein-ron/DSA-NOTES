#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 8

void init(unsigned char *set);
void insert(unsigned char *set, int element);
void delete(unsigned char *set, int element);
bool find(unsigned char set, int element);
unsigned char SetUnion(unsigned char A, unsigned char B);
unsigned char SetIntersection(unsigned char A, unsigned char B);
unsigned char SetDifference(unsigned char A, unsigned char B);
void display(unsigned char set);


int main(){
    unsigned char A, B, C;

    init(&A);
    init(&B);
    init(&C);

    insert(&A, 2);
    insert(&A, 3);
    insert(&A, 7);
    insert(&A, 4);

    insert(&B, 5);
    insert(&B, 1);
    insert(&B, 6);
    insert(&B, 4);

    display(A);
    display(B);

    C = SetUnion(A, B);
    display(C);
    C = SetIntersection(A, B);
    display(C);
    C = SetDifference(A, B);
    display(C);
}

void init(unsigned char *set){
    *set = 0;
}

void insert(unsigned char *set, int element){
    if(element >= 0 && element < MAX){
        *set |= (1 << element);
    }
}

void delete(unsigned char *set, int element){
    if(element >= 0 && element < MAX){
        *set &= ~(1 << element);
    }
}

bool find(unsigned char set, int element){
    if(element >= 0 && element < MAX) return (set & (1 << element)) != 0;
    return false;
}

unsigned char SetUnion(unsigned char A, unsigned char B){
    return A | B;
}

unsigned char SetIntersection(unsigned char A, unsigned char B){
    return A & B;
}

unsigned char SetDifference(unsigned char A, unsigned char B){
    return A & (~B);
}

void display(unsigned char set){
    int i;
    int comma = 1;

    printf("{");
    for(i = 0;i < MAX;i++){
       if(find(set, i)){
        if(!comma){
          printf(", ");
        }
        printf("%d", i);
        comma = 0;
       }
    }
    printf("}\n");

   
}