#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct node{
    int data;
    struct node* next;
}Node;

unsigned hash(int num);
void init();
bool insert(Node* table);
Node* lookup(int data);
Node* delete(int data);
void freeDict();
void display();

Node* hash_table[MAX];  

int main(){
    init();

    Node num1 = {19, NULL};
    Node num2 = {12, NULL};
    Node num3 = {14, NULL};
    Node num4 = {24, NULL};
    Node num5 = {34, NULL};
    Node num6 = {29, NULL};
    Node num7 = {32, NULL};
    Node num8 = {72, NULL};
    Node num9 = {82, NULL};

    insert(&num1);
    insert(&num2);
    insert(&num3);
    insert(&num4);
    insert(&num5);
    insert(&num6);
    insert(&num7);
    insert(&num8);
    insert(&num9);
    display();
    Node* found = lookup(102);
    if(found != NULL){
        printf("Found %d\n", found->data);
    }else{
        printf("Not Found\n");
    }
    Node* deleted = delete(24);
    if(deleted != NULL){
        printf("Deleted %d\n", deleted->data);
    }
    display();
    freeDict();
    display();
    return 0;
}

unsigned hash(int num){
    return num % MAX;
}

void init(){
    int i;

    for(i = 0;i < MAX;i++){
        hash_table[i] = NULL;
    }

}

bool insert(Node* table){
    if(table == NULL) return false;
    int index = hash(table->data);
    table->next = hash_table[index];
    hash_table[index] = table;
    return true;
}

Node* lookup(int data){
    int index = hash(data);
    Node* temp = hash_table[index];
    while(temp != NULL && temp->data != data){
        temp = temp->next;
    }

    return temp;
}

Node* delete(int data){
    int index = hash(data);
    Node* temp = hash_table[index];
    Node* prev = NULL;
    while(temp != NULL && temp->data != data){
        prev = temp;
        temp = temp->next;
    }


    if(temp == NULL) return NULL;
    if(prev == NULL){
        hash_table[index] = temp->next;
    }else{
        prev->next = temp->next;
    }
    return temp;
}

void freeDict(){
    int i;

    for(i = 0;i < MAX;i++){
        Node* trav = hash_table[i];
        while(trav != NULL){
            Node* temp = trav;
            trav = trav->next;
            free(temp);
        }
        hash_table[i] = NULL;
    }
}

void display(){
    int i;
   

    for(i = 0;i < MAX;i++){
        if(hash_table[i] == NULL){
            printf("%d ---", i);
        }else{
            printf("%d ", i);
            Node* temp = hash_table[i];
            while(temp != NULL){
                printf("%d -> ", temp->data);
                temp = temp->next;
            }    
        }
        printf("\n");
    }
    printf("\n");
}