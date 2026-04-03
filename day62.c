#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent the Graph
struct Graph {
    int numVertices;
    struct Node** adjLists; // Array of linked lists
};

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with n vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    // Create an array of adjacency lists. Size is n.
    graph->adjLists = malloc(vertices * sizeof(struct Node*));

    // Initialize each adjacency list as empty
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Function to add an edge (undirected)
void addEdge(struct Graph* graph, int u, int v) {
    // Add edge from u to v
    struct Node* newNode = createNode(v);
    newNode->next = graph->adjLists[u];
    graph->adjLists[u] = newNode;

    // Add edge from v to u (since it's undirected)
    newNode = createNode(u);
    newNode->next = graph->adjLists[v];
    graph->adjLists[v] = newNode;
}

// Function to print the adjacency list
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->adjLists[v];
        printf("Vertex %d: ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int n, m;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    struct Graph* graph = createGraph(n);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        // Assuming 0-indexed vertices
        addEdge(graph, u, v);
    }

    printf("\nAdjacency List Representation:\n");
    printGraph(graph);

    return 0;
}