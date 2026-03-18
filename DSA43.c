// Problem Statement:
// Construct a Binary Tree from the given level-order traversal.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers (-1 represents NULL)

// Output Format:
// - Print inorder traversal of the constructed tree

// Example:
// Input:
// 7
// 1 2 3 4 5 -1 6

// Output:
// 4 2 5 1 3 6

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = NULL;
    struct TreeNode* queue[n];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == -1)
            continue;

        struct TreeNode* newNode = createNode(arr[i]);

        if (root == NULL) {
            root = newNode;
        } else {
            struct TreeNode* parent = queue[front++];
            if (parent->left == NULL) {
                parent->left = newNode;
            } else {
                parent->right = newNode;
            }
        }

        queue[rear++] = newNode;
    }

    inorder(root);
    return 0;
}
