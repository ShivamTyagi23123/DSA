// Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int graph[MAX][MAX];
int visited[MAX];
int min_distance(int dist[], int n) {
    int min = __INT_MAX__, min_index;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}
void dijkstra(int graph[MAX][MAX], int n, int src) {
    int dist[MAX];
    for (int i = 0; i < n; i++) {
        dist[i] = __INT_MAX__;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = min_distance(dist, n);
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != __INT_MAX__ && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
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

    dijkstra(graph, n, src);
    return 0;
}
