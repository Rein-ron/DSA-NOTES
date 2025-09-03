#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct node{
    int data;
    struct node* next;
}Node;

typedef struct{
    Node* head;
    int count;
}List;


List* init(){
    List *newList = malloc(sizeof(List));
    newList->head= NULL;
    newList->count = 0;

    return newList;

}

void empty(List* L){
    Node* trav;
    Node* temp;

    if(L->head == NULL){
        printf("List is already empty.");
        return;
    }

    for(trav = L->head;trav != NULL;){
        temp = trav;
        trav = trav->next;
        free(temp);
    }

    // trav = L->head;
    // while(trav != NULL){
    //     temp = trav;
    //     trav = trav->next;
    //     free(temp);
    // }

    L->head = NULL;
    L->count = 0;
}

void insertPos(List* L, int data, int position){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    Node* trav;
    int count = 0;

    if(position == 0 || L->count == 0){
        newNode->next = L->head;
        L->head = newNode;
        L->count++;

        return;
    }

    for(trav = L->head;trav != NULL && count < position - 1;trav = trav->next){
        count++;
    }

    newNode->next = trav->next;
    trav->next = newNode;
    L->count++;
}

void insertFirst(List* L, int data){
    // Node* newNode = malloc(sizeof(Node));
    // newNode->data = data;
    // newNode->next = L->head;
    // L->head = newNode;
    // L->count++;
    insertPos(L, data, 0);
}

void insertLast(List* L, int data){
    // Node* newNode = malloc(sizeof(Node));
    // newNode->data = data;
    // newNode->next = NULL;

    // Node* trav;
    // for(trav = L->head;trav->next != NULL;trav = trav->next){}

    // trav->next = newNode;
    // L->count++;
    insertPos(L, data, L->count - 1);
}

void deletePos(List* L, int position){
    Node* trav;
    Node* temp;
    int i;

    if(position == 0){
        temp = L->head;
        L->head = L->head->next;
        free(temp);
        L->count--;
        return;
    }

    for(i = 0, trav = L->head;i < position - 1;i++){
        trav = trav->next;
    }

    
    temp = trav->next;
    trav->next = temp->next;
    free(temp);
    L->count--;
}

void deleteStart(List* L){
    // Node* temp;
    // temp = L->head;
    // L->head = L->head->next;
    // free(temp);
    // L->count--;
    deletePos(L, 0);
}

void deleteLast(List* L){
    // Node* trav;

    // for(trav = L->head;trav->next->next != NULL;trav = trav->next){}

    // free(trav->next);
    // trav->next = NULL;
    // L->count--;s
    deletePos(L, L->count - 1);
}

int retrieve(List* L, int index){
    Node* trav;
    int i;

    if(index > L->count - 1){
        return -1;
    }

    for(i = 0, trav = L->head;i < index;i++){
        trav = trav->next;
    }

    return trav->data;
}

int locate(List* L, int data){
    Node* trav;
    int i;
    for(trav = L->head;trav != NULL;trav = trav->next){
        if(trav->data == data) return i;
        i++;
    }

    return -1;
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
    int index = 1;
    insertPos(L, 10, 0);
    insertPos(L, 20, 1);
    insertPos(L, 30, 2);
    display(L);
    insertFirst(L, 40);
    display(L);
    insertLast(L, 50);
    display(L);
    deletePos(L, 1);
    display(L);
    deleteStart(L);
    display(L);
    deleteLast(L);
    display(L);
    int catcher = retrieve(L, index);
    if(catcher != -1){
        printf("Data of Index %d is %d\n",index, catcher);
    }else{
        printf("Not Found\n");
    }
    catcher = locate(L, 20);
    if(catcher != -1){
        printf("Found\n");
    }else{
        printf("Not Found\n");
    }
    empty(L);
    if(L->head == NULL){
        printf("List is empty");
    }

    return 0;
}