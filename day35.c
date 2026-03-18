// Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of elements)
// - Second line: n space-separated integers

// Output:
// - Print queue elements from front to rear, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50

// Explanation:
// Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
struct Queue {
    int arr[MAX_SIZE];
    int front;
    int rear;
};
void initQueue(struct Queue* queue) {
    queue->front = 0; // Initialize front to 0
    queue->rear = -1; // Initialize rear to -1 indicating empty queue
}
int isFull(struct Queue* queue) {
    return queue->rear == MAX_SIZE - 1; // Queue is full if rear reaches max index
}
int isEmpty(struct Queue* queue) {
    return queue->front > queue->rear; // Queue is empty if front exceeds rear
}
void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow\n"); // Cannot enqueue if queue is full
        return;
    }
    queue->arr[++queue->rear] = value; // Increment rear and add value to queue
}
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n"); // No elements to display
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]); // Print elements from front to rear
    }
    printf("\n");
}
int main() {
    struct Queue queue;
    initQueue(&queue); // Initialize the queue
    int n;
    scanf("%d", &n); // Read number of elements
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value); // Read each element
        enqueue(&queue, value); // Enqueue element to queue
    }
    display(&queue); // Display queue elements from front to rear
    return 0;
}
