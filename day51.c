// Problem Statement:
// Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers
// - Third line contains two node values

// Output Format:
// - Print the LCA value

// Example:
// Input:
// 7
// 6 2 8 0 4 7 9
// 2 8

// Output:
// 6

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
// Function to find the LCA of two nodes in the BST
struct TreeNode* findLCA(struct TreeNode* root, int n1, int n2) {
    if (root == NULL) {
        return NULL; // Base case: if the tree is empty
    }
    if (root->data > n1 && root->data > n2) {
        return findLCA(root->left, n1, n2); // LCA lies in left subtree
    }
    if (root->data < n1 && root->data < n2) {
        return findLCA(root->right, n1, n2); // LCA lies in right subtree
    }
    return root; // This node is the LCA
}

int main() {
    int N;
    printf("Enter the number of nodes in the BST: ");
    scanf("%d", &N);
    
    struct TreeNode* root = NULL;
    printf("Enter the values to insert into the BST: ");
    for (int i = 0; i < N; i++) {
        int value;
        scanf("%d", &value);
        root = insertIntoBST(root, value);
    }
    
    int n1, n2;
    printf("Enter the two node values to find their LCA: ");
    scanf("%d %d", &n1, &n2);
    
    struct TreeNode* lca = findLCA(root, n1, n2);
    if (lca != NULL) {
        printf("The LCA of %d and %d is: %d\n", n1, n2, lca->data);
    } else {
        printf("LCA does not exist for %d and %d\n", n1, n2);
    }
    
    return 0;
}
    