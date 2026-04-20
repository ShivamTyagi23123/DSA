// Problem Statement:
// Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 indicates NULL)

// Output Format:
// - Print traversal in zigzag order

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 1 3 2 4 5 6 7

// Explanation:
// Level 1 is printed left-to-right, level 2 right-to-left, and so on.

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
// Function to perform zigzag level order traversal
void zigzagTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return; // If the tree is empty, return
    }
    struct TreeNode** currentLevel = (struct TreeNode**)malloc(100 * sizeof(struct TreeNode*));
    struct TreeNode** nextLevel = (struct TreeNode**)malloc(100 * sizeof(struct TreeNode*));
    int currentCount = 0, nextCount = 0;
    int leftToRight = 1; // Start with left-to-right traversal
    currentLevel[currentCount++] = root; // Start with the root node
    while (currentCount > 0) {
        struct TreeNode* node = currentLevel[--currentCount]; // Get the last node in the current level
        printf("%d ", node->data); // Print the node's data
        if (leftToRight) {
            if (node->left) {
                nextLevel[nextCount++] = node->left; // Add left child to next level
            }
            if (node->right) {
                nextLevel[nextCount++] = node->right; // Add right child to next level
            }
        } else {
            if (node->right) {
                nextLevel[nextCount++] = node->right; // Add right child to next level
            }
            if (node->left) {
                nextLevel[nextCount++] = node->left; // Add left child to next level
            }
        }
        if (currentCount == 0) { // If we have finished the current level
            leftToRight = !leftToRight; // Toggle the traversal direction
            struct TreeNode** temp = currentLevel;
            currentLevel = nextLevel;
            nextLevel = temp; // Swap current and next level pointers
            nextCount = 0; // Reset next level count
        }
    }
    free(currentLevel); // Free memory allocated for current level
    free(nextLevel); // Free memory allocated for next level
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
    
    printf("Zigzag level order traversal of the binary tree is: ");
    zigzagTraversal(root);
    
    free(arr); // Free the array memory
    return 0;
}
