// Problem Statement:
// Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

// Input Format:
// - First line contains integer N (number of nodes)
// - Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

// Output Format:
// - Print nodes column by column from leftmost to rightmost vertical line

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 4
// 2
// 1 5 6
// 3
// 7

// Explanation:
// Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.

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
        return root; // If both left and right LCA are not NULL, then one key is present in one subtree and other key is present in another subtree. So this node is the LCA.
    }
    return (leftLCA != NULL) ? leftLCA : rightLCA; // Otherwise, check if left subtree or right subtree is LCA
}
int main() {
    int N;
    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &N);
    
    int* arr = (int*)malloc(N * sizeof(int));
    printf("Enter the values for level-order traversal (-1 for NULL): ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    struct TreeNode* root = buildTree(arr, N);
    
    int n1, n2;
    printf("Enter the two node values to find their LCA: ");
    scanf("%d %d", &n1, &n2);
    
    struct TreeNode* lca = findLCA(root, n1, n2);
    if (lca != NULL) {
        printf("The LCA of %d and %d is: %d\n", n1, n2, lca->data);
    } else {
        printf("LCA does not exist for %d and %d\n", n1, n2);
    }
    
    free(arr); // Free the input array memory
    return 0;
}