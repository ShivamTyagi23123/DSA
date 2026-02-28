// Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the circular linked list elements starting from head, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50

// Explanation:
// Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.

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
        newNode->next = *head; // Point to itself to form circular link
        return;
    }
    struct Node* current = *head;
    while (current->next != *head) {
        current = current->next; // Traverse to end of list
    }
    current->next = newNode; // Link last node to new node
    newNode->next = *head; // Link new node back to head
}
void traverseList(struct Node* head) {
    if (head == NULL) return; // Handle empty list
    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next; // Move to next node
    } while (current != head); // Stop when we return to head
    printf("\n");
}
int main() {
    int n;
    scanf("%d", &n);
    
    struct Node* head = NULL;
    
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insertAtEnd(&head, data); // Insert each element at end of circular linked list
    }
    
    traverseList(head); // Print circular linked list elements
    
    return 0;
}
