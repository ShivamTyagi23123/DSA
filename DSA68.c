// Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int graph[MAX][MAX];
int in_degree[MAX];
void topological_sort(int graph[MAX][MAX], int n) {
    int queue[MAX];
    int front = 0, rear = 0;

    // Enqueue vertices with in-degree 0
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            queue[rear++] = i;
        }
    }

    printf("Topological Sort: ");
    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        // Decrease in-degree of neighbors
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1) { // Check for neighbors
                in_degree[i]--;
                if (in_degree[i] == 0) {
                    queue[rear++] = i; // Enqueue if in-degree becomes 0
                }
            }
        }
    }
    printf("\n");
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Read edges and populate adjacency matrix and in-degree array
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; // For directed graph
        in_degree[v]++; // Increment in-degree of vertex v
    }

    topological_sort(graph, n);
    return 0;
}
