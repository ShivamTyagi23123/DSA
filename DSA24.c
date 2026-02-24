// Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer key

// Output:
// - Print the linked list elements after deletion, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 30

// Output:
// 10 20 40 50

// Explanation:
// Traverse list, find first node with key, remove it by adjusting previous node's next pointer.

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Insert at end
struct Node* insertEnd(struct Node* head, int value) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL)
        return newNode;

    struct Node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;

    return head;
}

// Delete first occurrence of key
struct Node* deleteKey(struct Node* head, int key) {

    if(head == NULL)
        return head;

    // If key is at head
    if(head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* curr = head;

    while(curr->next != NULL) {

        if(curr->next->data == key) {
            struct Node* temp = curr->next;
            curr->next = temp->next;
            free(temp);
            break;
        }

        curr = curr->next;
    }

    return head;
}

// Print list
void printList(struct Node* head) {

    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {

    int n, key, x;
    struct Node* head = NULL;

    scanf("%d",&n);

    for(int i=0;i<n;i++) {
        scanf("%d",&x);
        head = insertEnd(head,x);
    }

    scanf("%d",&key);

    head = deleteKey(head,key);

    printList(head);

    return 0;
}
