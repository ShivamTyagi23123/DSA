// Problem Statement:
// Print the nodes visible when the binary tree is viewed from the right side.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 indicates NULL)

// Output Format:
// - Print right view nodes

// Example:
// Input:
// 7
// 1 2 3 4 5 -1 6

// Output:
// 1 3 6

// Explanation:
// At each level, the rightmost node is visible from the right view.

#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};
// Create a new tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
// Function to build the tree from level-order input
struct TreeNode* buildTree(int* arr, int n) {
    if (n == 0) {
        return NULL; // No nodes to create
    }
    struct TreeNode* root = createNode(arr[0]);
    struct TreeNode** queue = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));
    int front = 0, rear = 0;
    queue[rear++] = root; // Enqueue the root node
    int i = 1;
    while (i < n) {
        struct TreeNode* current = queue[front++]; // Dequeue a node
        if (arr[i] != -1) {
            current->left = createNode(arr[i]); // Create left child
            queue[rear++] = current->left; // Enqueue left child
        }
        i++;
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]); // Create right child
            queue[rear++] = current->right; // Enqueue right child
        }
        i++;
    }
    free(queue); // Free the queue memory
    return root; // Return the root of the tree
}
// Function to print the right view of the binary tree
void rightView(struct TreeNode* root) {
    if (root == NULL) {
        return; // Base case: if the tree is empty
    }
    struct TreeNode** queue = (struct TreeNode**)malloc(100 * sizeof(struct TreeNode*)); // Queue for level order traversal
    int front = 0, rear = 0;
    queue[rear++] = root; // Enqueue the root node
    while (front < rear) {
        int levelSize = rear - front; // Number of nodes at the current level
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* current = queue[front++]; // Dequeue a node
            if (i == levelSize - 1) { // If it's the last node of the current level
                printf("%d ", current->data); // Print the rightmost node
            }
            if (current->left != NULL) {
                queue[rear++] = current->left; // Enqueue left child
            }
            if (current->right != NULL) {
                queue[rear++] = current->right; // Enqueue right child
            }
        }
    }
    free(queue); // Free the queue memory
}
int main() {
    int N;
    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &N);
    
    int* arr = (int*)malloc(N * sizeof(int));
    printf("Enter the level-order traversal of the tree (-1 for NULL): ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    struct TreeNode* root = buildTree(arr, N); // Build the tree from input
    printf("Right view of the binary tree: ");
    rightView(root); // Print the right view of the tree
    
    free(arr); // Free the input array memory
    return 0;
}