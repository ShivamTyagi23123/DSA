// Problem: BST Insert

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
// Function to insert a new node into the BST

struct TreeNode* insertIntoBST(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data); // Insert the new node here
    }
    if (data < root->data) {
        root->left = insertIntoBST(root->left, data); // Insert into left subtree
    } else {
        root->right = insertIntoBST(root->right, data); // Insert into right subtree
    }
    return root; // Return the unchanged root pointer
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

    printf("Inserted values into the BST.\n");
    return 0;
}
