#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
#define MAX_NAME 256

typedef struct node{
    char name[MAX_NAME];
    int age;
    struct node* next;
}Node;

typedef Node* dict[MAX];

int hash(char* name){
    int i;
    int value = 0, length = strlen(name);
    for(i = 0;i < length;i++){
        value = name[i];
        value = value * 109 % MAX;
    }
    return value;
}

void init(dict table){
    int i;

    for(i = 0;i < MAX;i++){
        table[i] = NULL;
    }
}

bool insert(dict table, char* name, int age){
    if(table == NULL) return false;
    int index = hash(name);

    Node* newNode = malloc(sizeof(Node));
    if(newNode == NULL) return false;

    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->next = table[index];
    table[index] = newNode;
    return true;
}

bool insertLast(dict table, char* name, int age){
    if(table == NULL) return false;
    int index = hash(name);

    Node* newNode = malloc(sizeof(Node));
    if(newNode != NULL){
        strcpy(newNode->name, name);
        newNode->age = age;
    }

    Node** trav;
    for(trav = &(table[index]);*trav != NULL;trav = &(*trav)->next){}
    *trav = newNode;
    return true;
}

Node* lookup(dict table, char* name){
    int index = hash(name);
    Node* temp = table[index];
    while(temp != NULL && strcmp(temp->name, name) != 0){
        temp = temp->next;
    }
    return temp;
}

Node* delete(dict table, char* name){
    int index = hash(name);
    Node* temp = table[index];
    Node* prev = NULL;
    while(temp != NULL && strcmp(temp->name, name) != 0){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) return NULL;
    if(prev == NULL){
        table[index] = temp->next;
    }else{
        prev->next = temp->next;
    }
    
    return temp;
}

void display(dict table){
    int i;

    for(i = 0;i < MAX;i++){
        if(table[i] == NULL){
            printf("[%d]---\n", i);
        }else{
            printf("[%d] ", i);
            Node* temp = table[i];
            while(temp != NULL){
                printf("Name: %s Age: %d -> ", temp->name, temp->age);
                temp = temp->next;
            }
            printf("\n");
        }
    }
    printf("\n");
}

int main(){
    dict table;
    init(table);

    insert(table, "Ronald", 24);
    insert(table, "Gabriel", 29);
    insert(table, "Toji", 33);
    insert(table, "Humphrey", 18);
    insert(table, "Reynat", 40);
    insert(table, "Seb", 67);
    insert(table, "Jaelian", 1);
    insertLast(table, "Justin", 48);
    insertLast(table, "Winfrey", 39);
    insertLast(table, "King", 57);

    display(table);

    return 0;
}