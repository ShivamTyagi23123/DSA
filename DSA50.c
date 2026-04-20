// Problem: BST Search

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
// Function to search for a value in the BST
int searchBST(struct TreeNode* root, int target) {
    if (root == NULL) {
        return 0; // Target not found
    }
    if (root->data == target) {
        return 1; // Target found
    }
    if (target < root->data) {
        return searchBST(root->left, target); // Search in left subtree
    } else {
        return searchBST(root->right, target); // Search in right subtree
    }
}
int main() {
    // Example usage:
    struct TreeNode* root = NULL;
    root = insertIntoBST(root, 5);
    insertIntoBST(root, 3);
    insertIntoBST(root, 7);
    insertIntoBST(root, 2);
    insertIntoBST(root, 4);
    insertIntoBST(root, 6);
    insertIntoBST(root, 8);

    int target = 4;
    if (searchBST(root, target)) {
        printf("Value %d found in the BST.\n", target);
    } else {
        printf("Value %d not found in the BST.\n", target);
    }
    return 0;
}
