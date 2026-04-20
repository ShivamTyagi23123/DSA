// Problem Statement:
// Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 represents NULL)
// - Third line contains two node values

// Output Format:
// - Print the LCA value

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7
// 4 5

// Output:
// 2

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
// Function to find the LCA of two nodes in the binary tree
struct TreeNode* findLCA(struct TreeNode* root, int n1, int n2) {
    if (root == NULL) {
        return NULL; // Base case: if the tree is empty
    }
    if (root->data == n1 || root->data == n2) {
        return root; // If either n1 or n2 matches the root's data, return the root
    }
    struct TreeNode* leftLCA = findLCA(root->left, n1, n2); // Recur for left subtree
    struct TreeNode* rightLCA = findLCA(root->right, n1, n2); // Recur for right subtree
    if (leftLCA && rightLCA) {
        return root; // If both left and right LCA are not NULL, then this node is the LCA
    }
    return (leftLCA != NULL) ? leftLCA : rightLCA; // Otherwise, return the non-NULL LCA
}   
int main() {
    int N;
    printf("Enter the number of nodes in the tree: ");
    scanf("%d", &N);
    
    int* arr = (int*)malloc(N * sizeof(int));
    printf("Enter the level-order traversal of the tree (-1 for NULL): ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    struct TreeNode* root = buildTree(arr, N); // Build the tree from input
    free(arr); // Free the array memory
    
    int n1, n2;
    printf("Enter the two node values to find their LCA: ");
    scanf("%d %d", &n1, &n2);
    
    struct TreeNode* lca = findLCA(root, n1, n2); // Find the LCA
    if (lca != NULL) {
        printf("LCA of %d and %d is: %d\n", n1, n2, lca->data); // Print the LCA value
    } else {
        printf("LCA does not exist for %d and %d\n", n1, n2); // If LCA does not exist
    }
    
    return 0;
}
