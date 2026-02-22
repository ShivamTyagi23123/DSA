// Problem: Count Nodes in Linked List

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the result

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50

#include <stdio.h>
#include <stdlib.h>

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

// Count nodes
int countNodes(struct Node* head) {

    int count = 0;

    while(head != NULL) {
        count++;
        head = head->next;
    }

    return count;
}

int main() {

    int n;
    scanf("%d",&n);

    struct Node* head = NULL;

    for(int i=0;i<n;i++) {
        int x;
        scanf("%d",&x);
        head = insertEnd(head,x);
    }

    int result = countNodes(head);

    printf("%d",result);

    return 0;
}
