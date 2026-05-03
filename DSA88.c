// Problem Statement
// Given n stalls located at different positions along a straight line and k cows, place the cows in the stalls such that the minimum distance between any two cows is maximized.

// This is an optimization problem where binary search on the answer is required.

// Input Format
// n k
// n space-separated integers representing stall positions

// Output Format
// Print the maximum possible minimum distance between any two cows.

// Sample Input
// 5 3
// 1 2 8 4 9

// Sample Output
// 3

// Explanation
// Cows can be placed at positions 1, 4, and 8. The minimum distance between any two cows is 3, which is the maximum possible.

#include <stdio.h>
#define MAX 100
int graph[MAX][MAX];
int dist[MAX][MAX];
void floydWarshall(int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != -1 && dist[k][j] != -1) {
                    int newDist = dist[i][k] + dist[k][j];
                    if (dist[i][j] == -1 || newDist < dist[i][j]) {
                        dist[i][j] = newDist;
                    }
                }
            }
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            dist[i][j] = graph[i][j];
        }
    }
    
    floydWarshall(n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
