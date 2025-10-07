#include <stdio.h>
#include <stdbool.h>
#define MAX 100

typedef int object;

typedef struct{
    object content[MAX];
    int count;
} Set;

void init(Set* s){
    s->count = 0;
}



void insert(Set* s, int data){
    bool in_set = false;
    int i;
    for(i = 0;i < s->count;i++){
        if(s->content[i] == data){
            return;
        }
    }

    if(!in_set){
        s->content[i] = data;
        s->count++;
    }
}

bool isMember(Set* s, int data){
    int i;
    
    for(i = 0;i < s->count;i++){
        if(s->content[i] == data){
            return true;
        }
    }

    return false;
}

Set UnionSet(Set A, Set B){
    int i;
    Set C;
    init(&C);

    for(i = 0;i < A.count;i++){
        insert(&C, A.content[i]);
    }

    for(i = 0;i < B.count;i++){
        insert(&C, B.content[i]);
    }

    return C;
}

Set IntersectionSet(Set A, Set B){
    int i, j;
    Set C;
    init(&C);

    for(i = 0;i < A.count;i++){
        for(j = 0;j < B.count;j++){
            if(A.content[i] == B.content[j]){
                insert(&C, A.content[i]);
                break;
            }
        }
    }

    return C;
}

Set DifferenceSet(Set A, Set B){
    int i, j;
    Set C;
    init(&C);

    for(i = 0;i < A.count;i++){
        bool inB = false;
        for(j = 0;j < B.count;j++){
            if(A.content[i] == B.content[j]){
                inB = true;
                break;
            }
        }
        if(!inB){
                insert(&C, A.content[i]);
            }
    }

    return C;
}

void printSet(Set s){
    int i;
    int comma = 1;

    printf("{");
    for(i = 0;i < s.count;i++){
        if(!comma){
            printf(", ");
        }
        printf("%d", s.content[i]);
        comma = 0;
    }
    printf("}\n");
}

int main(){
    Set A, B, C;
    init(&A);
    init(&B);
   

    insert(&A, 1);
    insert(&A, 3);
    insert(&A, 2);
    insert(&B, 1);
    insert(&B, 4);
    insert(&B, 5);

    C = UnionSet(A, B);
    printSet(C);
    C = IntersectionSet(A, B);
    printSet(C);
    C = DifferenceSet(A, B);
    printSet(C);
    return 0;
}