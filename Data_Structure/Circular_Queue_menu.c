#include <stdio.h>

#define MAX_SIZE 50

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} CircularQueue;

void initialize(CircularQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isFull(CircularQueue* queue) {
    if ((queue->front == 0 && queue->rear == MAX_SIZE - 1) ||
        (queue->front == queue->rear + 1))
        return 1;
    return 0;
}

int isEmpty(CircularQueue* queue) {
    if (queue->front == -1)
        return 1;
    return 0;
}

void insert(CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot insert element.\n");
        return;
    }

    if (isEmpty(queue))
        queue->front = 0;

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = value;
    printf("Element %d inserted successfully.\n", value);
}

void delete(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot delete element.\n");
        return;
    }

    int deletedItem = queue->items[queue->front];
    if (queue->front == queue->rear)
        initialize(queue);
    else
        queue->front = (queue->front + 1) % MAX_SIZE;

    printf("Element %d deleted successfully.\n", deletedItem);
}

void traversal(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Elements in the circular queue: ");
    int i;
    for (i = queue->front; i != queue->rear; i = (i + 1) % MAX_SIZE)
        printf("%d ", queue->items[i]);
    printf("%d\n", queue->items[i]);
}

void search(CircularQueue* queue, int value) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Element not found.\n");
        return;
    }

    int i;
    for (i = queue->front; i != queue->rear; i = (i + 1) % MAX_SIZE) {
        if (queue->items[i] == value) {
            printf("Element %d found at index %d.\n", value, i);
            return;
        }
    }

    if (queue->items[i] == value) {
        printf("Element %d found at index %d.\n", value, i);
        return;
    }

    printf("Element %d not found in the queue.\n", value);
}

int main() {
    CircularQueue queue;
    initialize(&queue);

    int choice, value;

    while (1) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Traverse\n");
        printf("4. Search\n");
        printf("5. isEmpty?\n");
        printf("6. isFull?\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &value);
                insert(&queue, value);
                break;
            case 2:
                delete(&queue);
                break;
            case 3:
                traversal(&queue);
                break;
            case 4:
                printf("Enter the element to search: ");
                scanf("%d", &value);
                search(&queue, value);
                break;
            case 5:
                if(isEmpty(&queue)){
                    printf("Queue is Empty!!!\n");
                }
                else
                {
                    printf("Queue is not Empty!!!\n");
                }
                
                break;
            case 6:
                if(isFull(&queue)){
                    printf("Queue is Full!!!\n");
                }
                else
                {
                    printf("Queue is not Full!!!\n");
                }
                
                break;

            case 7:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    }
}
