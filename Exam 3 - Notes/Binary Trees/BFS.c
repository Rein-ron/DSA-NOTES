#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

typedef struct node {
    int label;
    struct node *next;
} Node;

typedef Node* AdjList[MAX];

int queue[MAX];
int front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

bool isEmpty() {
    return front == rear;
}

int main() {
    AdjList M = {NULL};
    int edges[][2] = {{0,1}, {1,4}, {1,2}, {2,3}, {3,4}};
    int numEdges = sizeof(edges)/sizeof(edges[0]);
    
    for(int i = 0; i < numEdges; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        Node *n1 = (Node*) malloc(sizeof(Node));
        n1->label = v;
        n1->next = M[u];
        M[u] = n1;
        
        Node *n2 = (Node*) malloc(sizeof(Node));
        n2->label = u;
        n2->next = M[v];
        M[v] = n2;
    }
    
    int visited[MAX] = {0};
    int start = 0;
    visited[start] = 1;
    enqueue(start);
    
    printf("BFS: ");
    
    while(!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        
        Node *curr = M[node];
        while(curr != NULL) {
            if(!visited[curr->label]) {
                visited[curr->label] = 1;
                enqueue(curr->label);
            }
            curr = curr->next;
        }
    }
    
    printf("\n");
    return 0;
}
