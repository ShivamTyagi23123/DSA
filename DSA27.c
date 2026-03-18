// Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print value of intersection node or 'No Intersection'

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 30 40 50

// Output:
// 30

// Explanation:
// Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.

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
int getLength(struct Node* head) {
    int length = 0;
    struct Node* current = head;
    while (current != NULL) {
        length++;
        current = current->next; // Move to next node
    }
    return length; // Return total length of list
}
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    
    // Advance pointer in longer list
    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++) {
            head1 = head1->next;
        }
    } else {
        for (int i = 0; i < len2 - len1; i++) {
            head2 = head2->next;
        }
    }
    
    // Traverse both lists simultaneously
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2) { // Intersection found
            return head1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    
    return NULL; // No intersection
}
int main() {
    int n, m;
    scanf("%d", &n);
    
    struct Node* head1 = NULL;
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insertAtEnd(&head1, data); // Insert each element at end of first list
    }
    
    scanf("%d", &m);
    
    struct Node* head2 = NULL;
    for (int i = 0; i < m; i++) {
        int data;
        scanf("%d", &data);
        insertAtEnd(&head2, data); // Insert each element at end of second list
    }
    
    struct Node* intersectionNode = findIntersection(head1, head2);
    if (intersectionNode != NULL) {
        printf("%d\n", intersectionNode->data); // Print value of intersection node
    } else {
        printf("No Intersection\n"); // Print if no intersection found
    }
    
    return 0;
}
