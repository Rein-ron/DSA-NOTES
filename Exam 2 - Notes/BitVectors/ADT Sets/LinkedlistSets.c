#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node* next;
}Node, *Set;


void init(Set* s){
    *s = NULL;
}

void insert(Set* s, int data){
    Node* trav;

    for(trav = *s;trav != NULL;trav = trav->next){
        if(trav->data == data){
            return;
        }
    }

    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *s;

    *s = newNode;

}


Set UnionSet(Set A, Set B){
    Node* trav;
    Set C;
    init(&C);

    for(trav = A;trav != NULL;trav = trav->next){
        insert(&C, trav->data);
    }

      for(trav = B;trav != NULL;trav = trav->next){
        insert(&C, trav->data);
    }

    return C;
}

Set IntersectionSet(Set A, Set B){
    Node* trav, *trav2;
    Set C;
    init(&C);

    for(trav = A;trav != NULL;trav = trav->next){
        for(trav2 = B;trav2 != NULL;trav2 = trav2->next){
                if(trav->data == trav2->data){
                    insert(&C, trav->data);
                    break;
                }
        }
    }

   return C;
}

Set DifferenceSet(Set A, Set B){
    Node* trav, *trav2;
    Set C;
    init(&C);

    for(trav = A;trav != NULL;trav = trav->next){
        bool inB = false;
        for(trav2 = B;trav2 != NULL;trav2 = trav2->next){
            if(trav->data == trav2->data){
                inB = true;
                break;
            }
        }
        if(!inB){
            insert(&C, trav->data);
        }
    }

    return C;
}

void display(Set s){
    Node* trav;
    int comma = 1;

    printf("{");
    for(trav = s; trav != NULL;trav = trav->next){
        if(!comma){
            printf(", ");
        }
        printf("%d", trav->data);
        comma = 0;
    }
    printf("}\n");
    
}

int main(){
    Set A, B, C;
    init(&A);
    init(&B);
    init(&C);

    insert(&A, 1);
    insert(&A, 2);
    insert(&A, 3);
    insert(&B, 4);
    insert(&B, 5);
    insert(&B, 2);

    C = UnionSet(A, B);
    display(C);
    C = IntersectionSet(A, B);
    display(C);
    C = DifferenceSet(A, B);
    display(C);
    return 0;
}