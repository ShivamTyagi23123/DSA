// Problem: Implement push and pop operations on a stack and verify stack operations.

// Input:
// - First line: integer n
// - Second line: n integers to push
// - Third line: integer m (number of pops)

// Output:
// - Print remaining stack elements from top to bottom

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 30 20 10

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
        int value;
        scanf("%d", &value);
        push(&stack, value); // Push values onto the stack
    }
    
    int m;
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
        pop(&stack); // Pop values from the stack
    }
    
    display(&stack); // Display remaining stack elements
    return 0;
}