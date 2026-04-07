#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
bool recStack[MAX];
int V, E;

bool isCyclicUtil(int v) {
    if (!visited[v]) {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;

        // Recur for all the vertices adjacent to this vertex
        for (int i = 0; i < V; ++i) {
            if (adj[v][i]) {
                if (!visited[i] && isCyclicUtil(i))
                    return true;
                else if (recStack[i])
                    return true;
            }
        }
    }
    // Remove the vertex from recursion stack before returning
    recStack[v] = false;
    return false;
}

bool isCyclic() {
    // Initialize visited and recursion stack as false
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    // Call the recursive helper function for all vertices
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(i))
                return true;
        }
    }
    return false;
}

int main() {
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    // Initialize adjacency matrix
    for(int i=0; i<V; i++)
        for(int j=0; j<V; j++)
            adj[i][j] = 0;

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    if (isCyclic())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}