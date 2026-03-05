// Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

// Input:
// - Postfix expression with operands and operators

// Output:
// - Print the integer result

// Example:
// Input:
// 2 3 1 * + 9 -

// Output:
// -4

// Explanation:
// Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.

#include <stdio.h>  
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Stack {
    struct Node* top;
};
void initStack(struct Stack* stack) {
    stack->top = NULL; // Initialize top to NULL indicating empty stack
}
int isEmpty(struct Stack* stack) {
    return stack->top == NULL; // Stack is empty if top is NULL
}
void push(struct Stack* stack, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for new node
    newNode->data = value; // Set data to value
    newNode->next = stack->top; // Point new node to current top
    stack->top = newNode; // Update top to new node
}
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n"); // Cannot pop if stack is empty
        return -1; // Return -1 to indicate underflow
    }
    struct Node* temp = stack->top; // Store current top node
    int value = temp->data; // Get data from top node
    stack->top = stack->top->next; // Update top to next node
    free(temp); // Free memory of popped node
    return value; // Return popped value
}
int evaluatePostfix(char* expression) {
    struct Stack stack;
    initStack(&stack); // Initialize the stack
    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];
        if (ch >= '0' && ch <= '9') { // If character is an operand
            push(&stack, ch - '0'); // Convert char to int and push to stack
        } else { // If character is an operator
            int val2 = pop(&stack); // Pop second operand
            int val1 = pop(&stack); // Pop first operand
            switch (ch) {
                case '+': push(&stack, val1 + val2); break; // Push result of addition
                case '-': push(&stack, val1 - val2); break; // Push result of subtraction
                case '*': push(&stack, val1 * val2); break; // Push result of multiplication
                case '/': push(&stack, val1 / val2); break; // Push result of division
            }
        }
    }
    return pop(&stack); // Final result is at top of stack
}
int main() {
    char expression[100];
    scanf("%s", expression); // Read postfix expression
    int result = evaluatePostfix(expression); // Evaluate the expression
    printf("%d\n", result); // Print the result
    return 0;
}
