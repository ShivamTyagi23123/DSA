// Problem Statement:
// Check whether a given binary tree satisfies the Min-Heap property.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal

// Output Format:
// - Print YES if valid Min-Heap, otherwise NO

// Example:
// Input:
// 7
// 1 3 5 7 9 8 10

// Output:
// YES

// Explanation:
// Each parent node must be smaller than its children.

#include <stdio.h>
#include <stdlib.h>
// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Create node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Check Min-Heap property
int isMinHeap(struct Node* root) {
    if (root == NULL)
        return 1; // Empty tree is a Min-Heap
    if (root->left && root->data > root->left->data)
        return 0; // Violates Min-Heap
    if (root->right && root->data > root->right->data)
        return 0; // Violates Min-Heap
    return isMinHeap(root->left) && isMinHeap(root->right);
}
// Main function
int main() {
    int N;
    scanf("%d", &N);
    if (N == 0) {
        printf("YES\n");
        return 0;
    }
    struct Node* root = NULL;
    struct Node* queue[N];
    int front = 0, rear = 0;
    for (int i = 0; i < N; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (i == 0) {
            root = newNode;
        } else {
            if (queue[front]->left == NULL) {
                queue[front]->left = newNode;
            } else {
                queue[front]->right = newNode;
                front++;
            }
        }
        queue[rear++] = newNode;
    }
    printf(isMinHeap(root) ? "YES\n" : "NO\n");
    return 0;
}
