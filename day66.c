// Problem: Detect cycle in directed graph using DFS and recursion stack.

// Output:
// - YES if cycle exists

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int graph[MAX][MAX];
int visited[MAX];
int rec_stack[MAX];
int has_cycle(int v) {
    visited[v] = 1;
    rec_stack[v] = 1;

    for (int i = 0; i < MAX; i++) {
        if (graph[v][i] == 1) { // Check for neighbors
            if (!visited[i]) {
                if (has_cycle(i)) {
                    return 1; // Cycle detected
                }
            } else if (rec_stack[i]) {
                return 1; // Cycle detected
            }
        }
    }
    rec_stack[v] = 0; // Remove from recursion stack
    return 0; // No cycle detected
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

    int cycle_detected = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (has_cycle(i)) {
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
