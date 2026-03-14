// Problem: Perform BFS from a given source using queue.

// Input:
// - n
// - adjacency list
// - source s

// Output:
// - BFS traversal order

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void bfs(int graph[MAX][MAX], int n, int s) {
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;

    // Enqueue the source vertex and mark it as visited
    queue[rear++] = s;
    visited[s] = 1;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        // Explore neighbors
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}
int main() {
    int n, m, s;
    scanf("%d %d", &n, &m);
    int graph[MAX][MAX] = {0};

    // Read edges and populate adjacency matrix
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; // For directed graph
        // For undirected graph, also set graph[v][u] = 1;
    }
    scanf("%d", &s); // Read source vertex

    printf("BFS Traversal: ");
    bfs(graph, n, s);
    printf("\n");
    return 0;
}