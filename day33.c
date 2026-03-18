// Problem: Convert an infix expression to postfix notation using stack.

// Input:
// - Single line: infix expression (operands are single characters)

// Output:
// - Print the postfix expression

// Example:
// Input:
// A+B*C

// Output:
// ABC*+

// Explanation:
// Operator precedence: * > +
// Use stack to handle operator precedence and associativity

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
struct Stack {
    char arr[MAX_SIZE];
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
void push(struct Stack* stack, char value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n"); // Cannot push if stack is full
        return;
    }
    stack->arr[++stack->top] = value; // Increment top and add value to stack
}
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n"); // Cannot pop if stack is empty
        return '\0'; // Return null character to indicate underflow
    }
    return stack->arr[stack->top--]; // Return top value and decrement top
}
int precedence(char op) {
    if (op == '+' || op == '-') return 1; // Lowest precedence
    if (op == '*' || op == '/') return 2; // Higher precedence
    return 0; // Non-operator characters
}
void infixToPostfix(char* infix, char* postfix) {
    struct Stack stack;
    initStack(&stack); // Initialize the stack
    int j = 0; // Index for postfix string
    
    for (int i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];
        
        if ((token >= 'A' && token <= 'Z') || (token >= 'a' && token <= 'z')) {
            postfix[j++] = token; // Append operands directly to postfix
        } else if (token == '(') {
            push(&stack, token); // Push '(' onto stack
        } else if (token == ')') {
            while (!isEmpty(&stack) && stack.arr[stack.top] != '(') {
                postfix[j++] = pop(&stack); // Pop until '(' is found
            }
            pop(&stack); // Pop the '(' from stack
        } else { // Operator
            while (!isEmpty(&stack) && precedence(stack.arr[stack.top]) >= precedence(token)) {
                postfix[j++] = pop(&stack); // Pop operators with higher or equal precedence
            }
            push(&stack, token); // Push current operator onto stack
        }
    }
    
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack); // Pop remaining operators from stack
    }
    postfix[j] = '\0'; // Null-terminate the postfix string
}
int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    
    scanf("%s", infix); // Read infix expression
    
    infixToPostfix(infix, postfix); // Convert to postfix
    
    printf("%s\n", postfix); // Print the postfix expression
    return 0;
}
