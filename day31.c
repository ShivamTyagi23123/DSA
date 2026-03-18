// Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

// Input:
// - First line: integer n (number of operations)
// - Next n lines: operation type and value (if applicable)
//   - 1 value: push value
//   - 2: pop
//   - 3: display

// Output:
// - For display: print stack elements from top to bottom
// - For pop: print popped element or 'Stack Underflow'

// Example:
// Input:
// 5
// 1 10
// 1 20
// 3
// 2
// 3

// Output:
// 20 10
// 20
// 10

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
struct Stack {
    int arr[MAX_SIZE];
    int top;
};
void initStack(struct Stack* stack) {
    stack->top = -1; // Initialize top to -1 indicating empty stack
}
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1; // Stack is full if top reaches max index
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1; // Stack is empty if top is -1
}
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n"); // Cannot push if stack is full
        return;
    }
    stack->arr[++stack->top] = value; // Increment top and add value to stack
}
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n"); // Cannot pop if stack is empty
        return -1; // Return -1 to indicate underflow
    }
    return stack->arr[stack->top--]; // Return top value and decrement top
}
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n"); // No elements to display
        return;
    }
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]); // Print elements from top to bottom
    }
    printf("\n");
}
int main() {
    int n;
    scanf("%d", &n);
    
    struct Stack stack;
    initStack(&stack); // Initialize the stack
    
    for (int i = 0; i < n; i++) {
        int operation, value;
        scanf("%d", &operation);
        
        switch (operation) {
            case 1: // Push operation
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2: // Pop operation
                value = pop(&stack);
                if (value != -1) {
                    printf("%d\n", value); // Print popped value
                }
                break;
            case 3: // Display operation
                display(&stack);
                break;
            default:
                printf("Invalid operation\n"); // Handle invalid operations
        }
    }
    
    return 0;
}
