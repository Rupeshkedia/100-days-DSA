#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

// Structure for Adjacency List Node
struct Node {
    int dest;
    struct Node* next;
};

struct Node* adj[MAXN];
int visited[MAXN];

// Function to add an edge to the adjacency list
void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// DFS traversal to mark all nodes in a component
void dfs(int v) {
    visited[v] = 1;
    struct Node* temp = adj[v];
    while (temp != NULL) {
        int neighbor = temp->dest;
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Initialize adjacency list and visited array
    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u); // Since it's an undirected graph
    }

    int componentCount = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            // New unvisited node found, start a new DFS
            componentCount++;
            dfs(i);
        }
    }

    printf("%d\n", componentCount);

    return 0;
}