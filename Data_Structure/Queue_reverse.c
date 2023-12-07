#include <stdio.h>

#define MAX_SIZE 50

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} CircularQueue;

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void initializeQueue(CircularQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

void initializeStack(Stack* stack) {
    stack->top = -1;
}

int isQueueEmpty(CircularQueue* queue) {
    return (queue->front == -1);
}

int isStackEmpty(Stack* stack) {
    return (stack->top == -1);
}

int isQueueFull(CircularQueue* queue) {
    return ((queue->front == 0 && queue->rear == MAX_SIZE - 1) ||
            (queue->front == queue->rear + 1));
}

int isStackFull(Stack* stack) {
    return (stack->top == MAX_SIZE - 1);
}

void enqueue(CircularQueue* queue, int value) {
    if (isQueueFull(queue)) {
        printf("Queue is full. Cannot insert element.\n");
        return;
    }

    if (queue->front == -1)
        queue->front = 0;

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = value;
    printf("Element %d inserted successfully.\n", value);
}

int dequeue(CircularQueue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty. Cannot delete element.\n");
        return -1;
    }

    int deletedItem = queue->items[queue->front];
    if (queue->front == queue->rear)
        initializeQueue(queue);
    else
        queue->front = (queue->front + 1) % MAX_SIZE;

    return deletedItem;
}

void push(Stack* stack, int value) {
    if (isStackFull(stack)) {
        printf("Stack is full. Cannot push element.\n");
        return;
    }

    stack->top++;
    stack->items[stack->top] = value;
}

int pop(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty. Cannot pop element.\n");
        return -1;
    }

    int poppedItem = stack->items[stack->top];
    stack->top--;

    return poppedItem;
}

void reverseQueue(CircularQueue* queue) {
    Stack stack;
    initializeStack(&stack);

    while (!isQueueEmpty(queue)) {
        int item = dequeue(queue);
        push(&stack, item);
    }

    while (!isStackEmpty(&stack)) {
        int item = pop(&stack);
        enqueue(queue, item);
    }

    printf("Circular queue reversed successfully.\n");
}

void displayQueue(CircularQueue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Elements in the circular queue: ");
    int i;
    for (i = queue->front; i != queue->rear; i = (i + 1) % MAX_SIZE)
        printf("%d ", queue->items[i]);
    printf("%d\n", queue->items[i]);
}

int main() {
    CircularQueue queue;
    initializeQueue(&queue);

    int value;
    while (1) {
        printf("Enter a value to enqueue (or -1 to stop): ");
        scanf("%d", &value);
        if (value == -1)
            break;
        enqueue(&queue, value);
    }

    printf("Before reversing:\n");
    displayQueue(&queue);

    reverseQueue(&queue);

    printf("After reversing:\n");
    displayQueue(&queue);

    return 0;
}
