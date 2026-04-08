#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX]; // Adjacency Matrix
int visited[MAX];
int stack[MAX];
int top = -1;
int num_nodes;

void push(int v) {
    stack[++top] = v;
}

void dfs(int v) {
    visited[v] = 1;
    
    for (int i = 0; i < num_nodes; i++) {
        // If there is an edge and the neighbor is not visited
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
    
    // All neighbors explored, push to stack
    push(v);
}

void topologicalSort() {
    for (int i = 0; i < num_nodes; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < num_nodes; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &num_nodes);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix
    for(int i=0; i<num_nodes; i++)
        for(int j=0; j<num_nodes; j++)
            adj[i][j] = 0;

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    topologicalSort();

    return 0;
}