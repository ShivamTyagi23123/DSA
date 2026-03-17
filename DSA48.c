// Problem: Count Leaf Nodes

// Implement the solution for this problem.

// Input:
// - Input specifications

// Output:
// - Output specifications

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
// Function to count the number of leaf nodes in the binary tree
int countLeafNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0; // No nodes in the tree
    }
    if (root->left == NULL && root->right == NULL) {
        return 1; // This is a leaf node
    }
    // Recursively count leaf nodes in left and right subtrees
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}
int main() {
    // Example usage:
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Number of leaf nodes in the binary tree: %d\n", countLeafNodes(root));
    return 0;
}
