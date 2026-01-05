#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_SIZE 50
#define MAX_CHAR 256

typedef struct node{
    char name[MAX_CHAR];
    char bday[MAX_CHAR];
    int age;
    struct node* next;
}Node;

typedef Node* dict[MAX_SIZE];

int hash(char* name){
    int i, hash_value = 0;
    for(i = 0;name[i] != '\0';i++){
        hash_value += name[i] * 23;
    }
    return hash_value % MAX_SIZE;
}

void init(dict table){
    int i;
    for(i = 0;i < MAX_SIZE;i++){
        table[i] = NULL;
    }
}

void insert(dict table, char* name, char* bday, int age){
    int index = hash(name);

    Node* newNode = malloc(sizeof(Node));
    if(newNode == NULL) return;

    strcpy(newNode->name, name);
    strcpy(newNode->bday, bday);
    newNode->age = age;
    newNode->next = table[index];
    table[index] = newNode;
}

void insertLast(dict table, char* name, char* bday, int age){
    int index = hash(name);

    Node* newNode = malloc(sizeof(Node));
    if(newNode == NULL) return;

    strcpy(newNode->name, name);
    strcpy(newNode->bday, bday);
    newNode->age = age;
    newNode->next = NULL;

    Node **trav;    
    for(trav = &(table[index]);*trav != NULL;trav = &(*trav)->next){}
    *trav = newNode;
}

Node* lookup(dict table, char* name){
    int index = hash(name);
    Node* trav;
    for(trav = table[index]; trav != NULL && strcmp(trav->name, name) != 0;trav = trav->next){}
    return trav;
}

void delete(dict table, char* name){
    int index = hash(name);
    Node** trav;
    for(trav = &(table[index]); *trav != NULL && strcmp((*trav)->name, name) != 0; trav = &(*trav)->next){}
    if(*trav != NULL){
        Node* temp = *trav;
        *trav = temp->next;
        free(temp);
    }

}

void freeDict(dict table){
    int i;

    for(i = 0;i < MAX_SIZE;i++){
        Node* trav = table[i];
        while(trav != NULL){
            Node* temp = trav;
            trav = trav->next;
            free(temp);
        }
        table[i] = NULL;
    }
}

void display(dict table){
    int i;

    printf("\n");
    for(i = 0;i < MAX_SIZE;i++){
        if(table[i] == NULL){
            printf("%d ---\n", i);
        }else{
            Node* trav = table[i];
            printf("%d ", i);
            while(trav != NULL){
                printf("Name: %s, Birthday: %s, Age: %d ",trav->name, trav->bday, trav->age);
                if(trav->next != NULL){
                    printf("-> ");
                }
                trav = trav->next;
            }
            printf("\n");
        }
    }
    
}

int main(){
    dict table;
    init(table);
    insert(table, "Ronald", "09/08/2004", 21);
    insert(table, "Alice", "02/14/2001", 24);
    insert(table, "Bob", "07/23/1999", 26);
    insert(table, "Charlie", "11/05/2002", 23);
    insertLast(table, "Diana", "05/19/2000", 25);
    insertLast(table, "Ethan", "12/30/2003", 21);
    insertLast(table, "Fiona", "03/17/2001", 24);
    insert(table, "George", "08/08/2002", 23);
    insert(table, "Hannah", "10/31/1998", 27);
    insert(table, "Ian", "04/12/2005", 20);
    insertLast(table, "Jasmine", "01/09/2004", 21);
    insertLast(table, "Kyle", "06/28/2002", 23);
    insert(table, "Liam", "09/25/2000", 25);
    insert(table, "Mia", "12/11/2003", 21);
    insert(table, "Nathan", "07/01/1999", 26);
    insert(table, "Olivia", "03/05/2001", 24);
    insert(table, "Patrick", "11/20/2002", 23);
    insert(table, "Quinn", "02/18/2000", 25);
    insert(table, "Riley", "08/14/2003", 22);
    insert(table, "Sophia", "10/02/2001", 24);
    insert(table, "Tristan", "05/06/2004", 21);
    insert(table, "Uma", "01/27/1999", 26);
    insert(table, "Victor", "06/15/2002", 23);
    insertLast(table, "Wendy", "09/09/2000", 25);
    display(table);
    freeDict(table);
    display(table);
    
}