#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

struct Node {
    int dest;
    struct Node* next;
};

struct Graph {
    struct Node* head[MAX_NODES];
};

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = graph->head[src];
    graph->head[src] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = src;
    newNode->next = graph->head[dest];
    graph->head[dest] = newNode;
}

// DFS function to detect cycle
bool isCyclicUtil(int v, bool visited[], int parent, struct Graph* graph) {
    visited[v] = true;

    struct Node* temp = graph->head[v];
    while (temp != NULL) {
        int adjacent = temp->dest;

        // If adjacent node is not visited, recurse
        if (!visited[adjacent]) {
            if (isCyclicUtil(adjacent, visited, v, graph))
                return true;
        }
        // If adjacent is visited and not the parent, cycle found
        else if (adjacent != parent) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool isCyclic(struct Graph* graph, int n) {
    bool visited[MAX_NODES] = {false};

    // Handle disconnected components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(i, visited, -1, graph))
                return true;
        }
    }
    return false;
}

int main() {
    int n = 5; // Number of vertices
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    for (int i = 0; i < n; i++) graph->head[i] = NULL;

    // Example: 0-1, 1-2, 2-0 (forms a cycle)
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 3, 4);

    if (isCyclic(graph, n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}