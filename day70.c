// Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

// Input:
// - n vertices
// - m edges (u,v,w)

// Output:
// - Shortest distances OR NEGATIVE CYCLE

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int graph[MAX][MAX];
void bellman_ford(int graph[MAX][MAX], int n, int m, int src) {
    int dist[MAX];
    for (int i = 0; i < n; i++) {
        dist[i] = __INT_MAX__;
    }
    dist[src] = 0;

    // Relax edges repeatedly
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            if (dist[u] != __INT_MAX__ && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative-weight cycles
    for (int j = 0; j < m; j++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        if (dist[u] != __INT_MAX__ && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            return;
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}
int main() {
    int n, m, src;
    scanf("%d %d", &n, &m);
    int graph[MAX][MAX] = {0};

    // Read edges and populate adjacency matrix with weights
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w; // For directed graph
        // For undirected graph, also set graph[v][u] = w;
    }
    scanf("%d", &src); // Read source vertex

    bellman_ford(graph, n, m, src);
    return 0;
}
