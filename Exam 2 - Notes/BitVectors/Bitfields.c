#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    unsigned int field : 8;
}Set;

void init(Set *set);
void insert(Set *set, int element);
void delete(Set *set, int element);
bool find(Set set, int element);
Set SetUnion(Set A, Set B);
Set SetIntersection(Set A, Set B);
Set SetDifference(Set A, Set B);
void display(Set set);

int main(){
    Set A, B, C;

    init(&A);
    init(&B);
    init(&C);

    insert(&A, 2);
    insert(&A, 6);
    insert(&A, 3);

    insert(&B, 7);
    insert(&B, 3);
    insert(&B, 5);

    display(A);
    display(B);

    C = SetUnion(A, B);
    display(C);
    C = SetIntersection(A, B);
    display(C);
    C = SetDifference(A, B);
    display(C);
}

void init(Set *set){
    set->field = 0;
}

void insert(Set *set, int element){
    if(element >= 0 && element < 8){
        set->field |= (1 << element);
    }
}

void delete(Set *set, int element){
    if(element >= 0 && element < 8){
        set->field &= ~(1 << element);
    }
}

bool find(Set set, int element){
    if(element >= 0 && element < 8) return (set.field & (1 << element)) != 0;
    return false;
}

Set SetUnion(Set A, Set B){
    Set result;
    result.field = A.field | B.field;
    return result;
}

Set SetIntersection(Set A, Set B){
    Set result;
    result.field = A.field & B.field;
    return result;
}

Set SetDifference(Set A, Set B){
    Set result;
    result.field = A.field & (~B.field);
    return result;
}

void display(Set set){
    int i;
    int comma = 1;

    printf("{");
    for(i = 0;i < 8;i++){
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