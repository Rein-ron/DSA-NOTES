#include <stdio.h>
#define SIZE 30

typedef enum{ FALSE, TRUE } Boolean;
typedef Boolean Set[SIZE];

void init(Set s){
    int i;
    for(i = 0;i < SIZE;i++){
        s[i] = FALSE;
    }
}

Boolean isMember(Set s, int index){
    if(index >= 0 && index < SIZE){
        return s[index];
    }
    return FALSE;
}

void insertSet(Set s, int index){
    if(index >= 0 && index < SIZE){
        s[index] = TRUE;
    }
}

void AssignSet(Set A, Set B){
    int i;
    for(i = 0;i < SIZE;i++){
        A[i] = B[i];
    }
}

int minSet(Set s){
    int i;
    for(i = 0;i < SIZE;i++){
        if(s[i] == TRUE){
            return i;
        }
    }
    return -1;
}

int maxSet(Set s){
    int i;
    for(i = SIZE - 1;i > 0;i--){
        if(s[i] == TRUE){
            return i;
        }
    }
    return -1;
}

int equalSet(Set A, Set B){
    int i;
    for(i = 0;i < SIZE;i++){
      if(A[i] != B[i]){
         return 0;
      }
    }
    return 1;
}

int findSet(Set s, int index){
    if(index >= 0 && index < SIZE){
        return index;
    }
}

void deleteSet(Set s, int index){
    if(index >= 0 && index < SIZE){
        s[index] = FALSE; 
    }
}

void SetUnion(Set A, Set B, Set C){
    int i;

    for(i = 0;i < SIZE;i++){
        C[i] = A[i] || B[i];
    }

}

void SetIntersection(Set A, Set B, Set C){
    int i;

    for(i = 0;i < SIZE;i++){
        C[i] = A[i] && B[i];
    }

}

void SetDifference(Set A, Set B, Set C){
    int i;

    for(i = 0;i < SIZE;i++){
        C[i] = A[i] && !B[i];
    }
}
void display(Set s){
    int i, first = 1;
    printf("{");
    for(i = 0; i < SIZE;i++){
        if(s[i] == TRUE){
            if(!first) printf(",");
            printf("%d", i);
            first = 0;
        }
    }
    printf("}\n");
}


int main(){
    Set A, B, C;
    init(&A);
    init(&B);
    init(&C);

    insertSet(A, 2);
    insertSet(A, 4);
    insertSet(A, 7);
    insertSet(A, 10);
    insertSet(A, 15);

    insertSet(B, 4);
    insertSet(B, 5);
    insertSet(B, 10);
    insertSet(B, 12);
    insertSet(B, 15);

    printf("A = "); display(A);
    printf("B = "); display(B);

    SetUnion(A, B, C);
    printf("Union = "); display(C);

    SetIntersection(A, B, C);
    printf("Intersection = "); display(C);

    SetDifference(A, B, C);
    printf("Difference = "); display(C);

}
