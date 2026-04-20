// Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int graph[MAX][MAX];
int visited[MAX];
void topological_sort(int v) {
    visited[v] = 1;

    for (int i = 0; i < MAX; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            topological_sort(i);
        }
    }
    printf("%d ", v); // Print after visiting all neighbors
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Read edges and populate adjacency matrix
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; // For directed graph
    }

    printf("Topological Sort: ");
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topological_sort(i);
        }
    }
    printf("\n");
    return 0;
}
