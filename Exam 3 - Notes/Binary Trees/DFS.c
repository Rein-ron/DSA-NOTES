#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct node {
    int label;
    struct node *next;
} Node;

Node* adj[MAX];
int visited[MAX];

void dfs(int u) {
    visited[u] = 1;
    printf("%d ", u);

    Node* curr = adj[u];
    while(curr != NULL) {
        if(!visited[curr->label])
            dfs(curr->label);
        curr = curr->next;
    }
}

int main() {
    for(int i = 0; i < MAX; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    int edges[][2] = {{0,1}, {1,4}, {1,2}, {2,3}, {3,4}};
    int numEdges = sizeof(edges)/sizeof(edges[0]);

    for(int i = 0; i < numEdges; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        Node* n1 = malloc(sizeof(Node));
        n1->label = v;
        n1->next = adj[u];
        adj[u] = n1;

        Node* n2 = malloc(sizeof(Node));
        n2->label = u;
        n2->next = adj[v];
        adj[v] = n2;
    }

    printf("DFS: ");
    dfs(0);
    printf("\n");

    return 0;
}
