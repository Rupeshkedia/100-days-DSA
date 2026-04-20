#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100
#define INF INT_MAX

void dijkstra(int n, int graph[MAX][MAX], int source) {
    int dist[MAX];
    bool visited[MAX];

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[source] = 0;

    for (int count = 1; count <= n; count++) {
        int min = INF, u = -1;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && dist[v] < min) {
                min = dist[v];
                u = v;
            }
        }

        if (u == -1) break;

        visited[u] = true;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] != 0 && dist[u] != INF 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");
}

int main() {
    int n, m;
    int graph[MAX][MAX] = {0};

    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; 
    }

    int source;
    scanf("%d", &source);

    dijkstra(n, graph, source);

    return 0;
}