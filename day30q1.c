// Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of terms)
// - Next n lines: two integers (coefficient and exponent)

// Output:
// - Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

// Example:
// Input:
// 5
// 10 4
// 20 3
// 30 2
// 40 1
// 50 0

// Output:
// 10x^4 + 20x^3 + 30x^2 + 40x + 50

// Explanation:
// Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
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
void printPolynomial(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->exp == 0) {
            printf("%d", current->coeff); // Constant term
        } else if (current->exp == 1) {
            printf("%dx", current->coeff); // Linear term
        } else {
            printf("%dx^%d", current->coeff, current->exp); // Higher degree term
        }
        if (current->next != NULL) {
            printf(" + "); // Add plus sign between terms
        }
        current = current->next; // Move to next node
    }
    printf("\n");
}
int main() {
    int n;
    scanf("%d", &n);
    
    struct Node* head = NULL;
    
    for (int i = 0; i < n; i++) {
        int coeff, exp;
        scanf("%d %d", &coeff, &exp);
        insertAtEnd(&head, coeff, exp); // Insert each term at end of list
    }
    
    printPolynomial(head); // Print the polynomial in standard form
    return 0;
}
