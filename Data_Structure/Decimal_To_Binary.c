#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int data;
    struct stack* next;
} Stack;

typedef struct queue {
    int data;
    struct queue* next;
} Queue;

void push(Stack** top, int data) {
    Stack* newNode = (Stack*)malloc(sizeof(Stack));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}
int pop(Stack** top) {
    if (*top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    int data = (*top)->data;
    Stack* temp = *top;
    *top = (*top)->next;
    free(temp);
    return data;
}void enqueue(Queue** front, int data) {
    Queue* newNode = (Queue*)malloc(sizeof(Queue));
    newNode->data = data;
    newNode->next = NULL;
    if (*front == NULL) {
        *front = newNode;
    } else {
        Queue* rear = *front;
        while (rear->next != NULL) {
            rear = rear->next;
        }
        rear->next = newNode;
    }
}

int dequeue(Queue** front) {
    if (*front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = (*front)->data;
    Queue* temp = *front;
    *front = (*front)->next;
    free(temp);
    return data;
}

void decimalToBinary(int decimal) {
    Stack* stack = NULL;
    Queue* queue = NULL;
    int quotient, remainder;

    quotient = decimal;
    if (decimal==0)
    {
        printf("0");
        return;
    }
    
    while (quotient != 0) {
        remainder = quotient % 2;
        push(&stack, remainder);
        quotient = quotient / 2;
    }

    while (stack != NULL) {
        remainder = pop(&stack);
        enqueue(&queue, remainder);
    }

    while (queue != NULL) {
        printf("%d", dequeue(&queue));
    }
    printf("\n");
}


int main() {
    int decimal;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    printf("Binary equivalent: ");
    decimalToBinary(decimal);

    return 0;
}






