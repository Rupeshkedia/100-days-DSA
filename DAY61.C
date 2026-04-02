#include <stdio.h>

#define MAX 100

int main() {
    int n, m, i, j;
    int u, v, isDirected;
    int adj[MAX][MAX];

    // Initialize the matrix with 0
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Is the graph directed? (1 for Yes, 0 for No): ");
    scanf("%d", &isDirected);

    printf("Enter %d pairs of edges (u v):\n", m);
    for (i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // Adjust for 0-indexed or 1-indexed input
        // This code assumes 0 to n-1 indexing
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adj[u][v] = 1;
            
            // If undirected, the edge exists both ways
            if (!isDirected) {
                adj[v][u] = 1;
            }
        } else {
            printf("Invalid vertex! Please use indices between 0 and %d\n", n-1);
            i--; // Decrement to retry this edge
        }
    }

    // Output the Adjacency Matrix
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}