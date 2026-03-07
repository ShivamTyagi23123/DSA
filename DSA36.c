// Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of elements to enqueue)
// - Second line: n space-separated integers
// - Third line: integer m (number of dequeue operations)

// Output:
// - Print queue elements from front to rear after operations, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 30 40 50 10 20

// Explanation:
// Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
struct CircularQueue {
    int arr[MAX_SIZE];
    int front;
    int rear;
    int size;
};
void initCircularQueue(struct CircularQueue* queue) {
    queue->front = 0; // Initialize front to 0
    queue->rear = -1; // Initialize rear to -1 indicating empty queue
    queue->size = 0; // Initialize size to 0
}
int isFull(struct CircularQueue* queue) {
    return queue->size == MAX_SIZE; // Queue is full if size reaches max
}
int isEmpty(struct CircularQueue* queue) {
    return queue->size == 0; // Queue is empty if size is 0
}
void enqueue(struct CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow\n"); // Cannot enqueue if queue is full
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE; // Move rear to next position with wrap-around
    queue->arr[queue->rear] = value; // Add value to queue
    queue->size++; // Increment size
}
void dequeue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n"); // Cannot dequeue if queue is empty
        return;
    }
    queue->front = (queue->front + 1) % MAX_SIZE; // Move front to next position with wrap-around
    queue->size--; // Decrement size
}
void display(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n"); // No elements to display
        return;
    }
    for (int i = 0; i < queue->size; i++) {
        int index = (queue->front + i) % MAX_SIZE; // Calculate index with wrap-around
        printf("%d ", queue->arr[index]); // Print elements from front to rear
    }
    printf("\n");
}
int main() {
    struct CircularQueue queue;
    initCircularQueue(&queue); // Initialize the circular queue
    int n, m;
    scanf("%d", &n); // Read number of elements to enqueue
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value); // Read each element
        enqueue(&queue, value); // Enqueue element to circular queue
    }
    scanf("%d", &m); // Read number of dequeue operations
    for (int i = 0; i < m; i++) {
        dequeue(&queue); // Dequeue element from circular queue
    }
    display(&queue); // Display remaining elements in circular queue from front to rear
    return 0;
}
