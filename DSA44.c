// Problem Statement:
// Perform inorder, preorder, and postorder traversals of a given binary tree.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 represents NULL)

// Output Format:
// - Print inorder, preorder, and postorder traversals

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 4 2 5 1 6 3 7
// 1 2 4 5 3 6 7
// 4 5 2 6 7 3 1

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

void preorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
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

    printf("Inorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\n");

    return 0;
}
