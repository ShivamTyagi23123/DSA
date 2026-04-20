// Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

// Output:
// - YES or NO

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int graph[MAX][MAX];
int visited[MAX];
int parent[MAX];
int has_cycle(int v, int p) {
    visited[v] = 1;
    parent[v] = p;

    for (int i = 0; i < MAX; i++) {
        if (graph[v][i] == 1) { // Check for neighbors
            if (!visited[i]) {
                if (has_cycle(i, v)) {
                    return 1; // Cycle detected
                }
            } else if (i != p) {
                return 1; // Cycle detected
            }
        }
    }
    return 0; // No cycle detected
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Read edges and populate adjacency matrix
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; // For undirected graph
        graph[v][u] = 1; // For undirected graph
    }

    int cycle_detected = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (has_cycle(i, -1)) {
                cycle_detected = 1;
                break;
            }
        }
    }

    if (cycle_detected) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
