// Problem Statement
// Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

// Input Format
// n m
// u v w
// ...

// Output Format
// Total weight of MST.

// Sample Input
// 4 5
// 1 2 3
// 1 3 5
// 2 3 1
// 2 4 4
// 3 4 2

// Sample Output
// 6

// Explanation
// One possible MST edges: (2-3), (3-4), (1-2)

#include <stdio.h>
#define MAX 100
int graph[MAX][MAX];
int visited[MAX];
int prim(int n) {
    int total_weight = 0;
    visited[1] = 1; // Start from the first node
    
    for (int count = 0; count < n - 1; count++) {
        int min_weight = 1e9;
        int u, v;
        
        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                for (int j = 1; j <= n; j++) {
                    if (!visited[j] && graph[i][j] && graph[i][j] < min_weight) {
                        min_weight = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        
        visited[v] = 1;
        total_weight += min_weight;
    }
    
    return total_weight;
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // Undirected graph
    }
    
    int result = prim(n);
    printf("%d\n", result);
    return 0;
}
