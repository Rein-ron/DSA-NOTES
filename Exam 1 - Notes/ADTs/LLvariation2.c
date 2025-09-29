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

void init(List** List){
    *List = malloc(sizeof(List));
    (*List)->head = NULL;
    (*List)->count = 0;
}

void empty(List** List){
    Node* temp;
    
    while((*List)->head != NULL){
        temp = (*List)->head;
        (*List)->head = (*List)->head->next;
        free(temp);
    }
}

void insertPos(List** List, int data, int position){
    Node** headref = &(*List)->head;
    int count = 0;
     
    while(*headref != NULL && count < position - 1){
        headref = &((*headref)->next);
        count++;
     }

     Node* newNode = malloc(sizeof(Node));
     newNode->data = data;
     newNode->next = *headref;
     *headref = newNode;

     (*List)->count++;
}

void insertFirst(List** List, int data){
    insertPos(List, data, 0);
}

void insertLast(List** List, int data){
    insertPos(List, data, (*List)->count);
}

void deletePos(List** List, int position){
    Node** headref = &(*List)->head;
    Node* temp;
    int count = 0;

    if(position == 0){
        temp = *headref;
        *headref = (*headref)->next;
        free(temp);
        (*List)->count--;
        return;
    }

    while(*headref != NULL && count < position - 1){
        headref = &((*headref)->next);
        count++;
    }

    temp = (*headref)->next;
    (*headref)->next = temp->next;
    free(temp);
    (*List)->count--;
}

void deleteStart(List** List){
    deletePos(List, 0);
}

void deleteLast(List** List){
    deletePos(List, (*List)->count - 1);
}

int retrieve(List** List, int index){
    Node** headref = &((*List)->head);
    int count = 0;

     while(*headref != NULL && count < index){
        headref = &((*headref)->next);
        count++;
     }

     if(*headref == NULL) return -1;
     return (*headref)->data;
}

int locate(List** List, int data){
    Node** headref = &((*List)->head);
    int count = 0;

    while(*headref != NULL && (*headref)->data != data){
        headref = &((*headref)->next);
        count++;
    }

    if(*headref == NULL) return -1;
    return count;
}

void display(List** List){
    Node** headref = &(*List)->head;

    while(*headref != NULL){
        printf("%d ", (*headref)->data);
        headref = &((*headref)->next);
    }
    printf("\n");
}

int main(){
    List* L;
    init(&L);
    insertFirst(&L, 10);
    insertFirst(&L, 20);
    display(&L);
    insertPos(&L, 30, 2);
    insertPos(&L, 40, 3);
    display(&L);
    insertLast(&L, 50);
    insertLast(&L, 60);
    display(&L);
    deletePos(&L, 2);
    display(&L);
    deleteStart(&L);
    display(&L);
    deleteLast(&L);
    display(&L);

    int catcher = retrieve(&L, 3);
    if(catcher != -1){
        printf("Found.\n");
    }else{
        printf("Not Found.\n");
    }

    catcher = locate(&L, 30);
    if(catcher != -1){
        printf("Found at Index %d.\n", catcher);
    }else{
        printf("Not Found.\n");
    }
    return 0;
}