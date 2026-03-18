// Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer k

// Output:
// - Print the linked list elements after rotation, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 40 50 10 20 30

// Explanation:
// Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode; // First node becomes head
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next; // Traverse to end of list
    }
    current->next = newNode; // Link last node to new node
}
void rotateRight(struct Node** head, int k) {
    if (*head == NULL || k <= 0) return; // Handle empty list or non-positive k
    
    // Count the number of nodes in the list
    struct Node* current = *head;
    int length = 1; // Start counting from head
    while (current->next != NULL) {
        current = current->next;
        length++;
    }
    
    // Connect last node to head to form circular list
    current->next = *head;
    
    // Calculate effective rotations needed
    k = k % length; // In case k is greater than length
    int stepsToNewHead = length - k; // Steps to new head from current head
    
    // Traverse to the new tail node (stepsToNewHead - 1)
    for (int i = 0; i < stepsToNewHead - 1; i++) {
        current = current->next;
    }
    
    // Set new head and break the circular link
    *head = current->next; // New head is next of current
    current->next = NULL; // Break the circular link
}
void traverseList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next; // Move to next node
    }
    printf("\n");
}
int main() {
    int n, k;
    scanf("%d", &n);
    
    struct Node* head = NULL;
    
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insertAtEnd(&head, data); // Insert each element at end of list
    }
    
    scanf("%d", &k);
    
    rotateRight(&head, k); // Rotate the linked list to the right by k places
    
    traverseList(head); // Print the rotated linked list elements
    
    return 0;
}
