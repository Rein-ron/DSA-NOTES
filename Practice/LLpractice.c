#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define LENGTH 10;


typedef struct node{
    int data;
    struct node* next;
}Node;

typedef struct{
    Node* head;
    int count;
}List;


List* init(){
    List* newList = malloc(sizeof(List));
    newList->head = NULL;
    newList->count = 0;

    return newList;
}

void insertPos(List* L, int data, int pos){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    int count = 0;

    if(L->count == 0 || pos == 0){
        newNode->next = L->head;
        L->head = newNode;
        L->count++;

        return; 
    }

    Node* trav;
    for(trav = L->head;trav != NULL && count < pos - 1;trav = trav->next){
        count++;
    }
    newNode->next = trav->next;
    trav->next = newNode;
    L->count++;
}

void insertFirst(List *L, int data){
    insertPos(L, data, 0);
}

void insertLast(List *L, int data){
    insertPos(L, data, L->count);
}

void deletePos(List *L, int pos){
    Node* trav;
    Node* temp;
    int i;

    if(L->head == NULL || pos < 0 || pos >= L->count){
        return;
    }

    if(pos == 0){
        temp = L->head;
        L->head = L->head->next;
        free(temp);
        return;
    }

    for(i = 0, trav = L->head;i < pos - 1;i++){
        trav = trav->next;
    }

    temp = trav->next;
    trav->next = temp->next;
    free(temp);
    L->count--;
}

void deleteFirst(List* L){
    deletePos(L, 0);
}

void deleteLast(List* L){
    if(L->count > 0) deletePos(L, L->count - 1);
}

void display(List* L){
    Node* trav;

    for(trav = L->head;trav != NULL;trav = trav->next){
        printf("%d ", trav->data);
    }

    printf("\n");
}
int main(){
    List* L = init();
    insertFirst(L, 10);
    insertFirst(L, 20);
    insertFirst(L, 30);
    display(L);
    insertLast(L, 40);
    insertLast(L, 50);
    insertLast(L, 60);
    insertPos(L, 90, 3);
    display(L);
    deleteFirst(L);
    deleteFirst(L);
    deleteLast(L);
    deletePos(L, 4);
    display(L);
}
