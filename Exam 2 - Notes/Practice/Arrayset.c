#include <stdio.h>
#include <stdbool.h>
#define MAX 100

typedef int object;

typedef struct {
    object set[MAX];
    int size;
}SET;

void init(SET *s){
    s->size = 0;
}

void insert(SET *s, int elem){
    int i;
    for(i = 0;i < s->size;i++){
        if(s->set[i] == elem) return;
    }

    if(s->size < MAX){
        s->set[i] = elem;
        s->size++;
    }

}

bool isMember(SET *s, int elem){
    int i;
    for(i = 0;i < s->size;i++){
        if(s->set[i] == elem){
            return true;
        }
    }
    return false;
}

SET Union(SET A, SET B){
    SET C;
    init(&C);
    int i;

    for(i = 0;i < A.size;i++){
        insert(&C, A.set[i]);
    }

    for(i = 0;i < B.size;i++){
        insert(&C, B.set[i]);
    }
    return C;
}

SET Intersection(SET A, SET B){
    SET C;
    init(&C);
    int i, j;

    for(i = 0;i < A.size;i++){
        for(j = 0;j < B.size;j++){
            if(A.set[i] == B.set[j]){
                insert(&C, A.set[i]);
                break;
            }
        }
    }
    return C;
}

SET Difference(SET A, SET B){
    SET C;
    init(&C);
    int i, j;
    
    for(i = 0;i < A.size;i++){
        bool inB = false;
        for(j = 0;j < B.size;j++){
            if(A.set[i] == B.set[j]){
                inB = true;
                break;
            }
        }
        if(!inB){
            insert(&C, A.set[i]);
        }
    }
    return C;
}

void display(SET s){
    int i, first = 1;
    for(i = 0; i < s.size;i++){
        if(!first) printf(",");
        printf("%d", s.set[i]);
        first = 0;
    }
    printf("\n");
}

int main(){
    SET A, B, C;
    init(&A);
    init(&B);
    init(&C);

    insert(&A, 5);
    insert(&A, 4);
    insert(&A, 3);
    insert(&A, 8);
    insert(&A, 9);
    display(A);

    insert(&B, 5);
    insert(&B, 8);
    insert(&B, 9);
    insert(&B, 2);
    insert(&B, 1);
    display(B);

    C = Union(A,B);
    display(C);
    C = Intersection(A,B);
    display(C);
    C = Difference(A,B);
    display(C);
}