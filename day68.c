#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void kahnAlgorithm(int adj[MAX][MAX], int n) {
    int in_degree[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;
    int topo_order[MAX], count = 0;

    // 1. Calculate in-degree of every vertex
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                in_degree[j]++;
            }
        }
    }

    // 2. Enqueue all vertices with in-degree 0
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // 3. Process the queue
    while (front < rear) {
        int u = queue[front++];
        topo_order[count++] = u;

        // Iterate through neighbors
        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1) {
                in_degree[v]--; // "Remove" the edge
                
                // If in-degree becomes 0, add to queue
                if (in_degree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    // 4. Check for cycles
    if (count != n) {
        printf("\nError: The graph contains a cycle. Topological sort impossible.\n");
    } else {
        printf("\nTopological Sort: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", topo_order[i]);
        }
        printf("\n");
    }
}

int main() {
    int n, edges, u, v;
    int adj[MAX][MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    kahnAlgorithm(adj, n);

    return 0;
}