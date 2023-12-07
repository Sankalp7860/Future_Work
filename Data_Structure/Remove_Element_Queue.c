#include <stdio.h>

#define MAX_QUEUE_SIZE 100

int queue[MAX_QUEUE_SIZE];
int front = -1, rear = -1;

void enqueue(int element) {
    if (rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue overflow!\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = element;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow!\n");
        return -1;
    }
    int element = queue[front];
    front++;
    return element;
}

void remove_element(int element) {
    for (int i = 0; i < rear; i++)
    {
        if (queue[i]==element  )
        {
            break;
        }
        else if ((i==rear-1)&& queue[i]!=element)
        {
            printf("Your Element is not in  the queue!!!\n");
        }
    }
    
    int temp_rear = rear;
    int temp_element;
    while (front <= temp_rear) {
        temp_element = dequeue();
        if (temp_element == element) {
            continue;
        }
        enqueue(temp_element);
    }
}

void display_queue() {
    int i;
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements are:\n");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int num,num2;
    while(1){
                printf("Press 1:To Insert in the queue.\n");
                printf("Press 2:To Delete the number from the queue.\n");
                printf("Press 3:To Display the elements of the queue\n");
                printf("\n Please Enter your choice : ");
                scanf("%d",&num);
                if (num==1)
                {
                    printf("Please Enter the number which you want to insert: ");
                    scanf("%d",&num2);
                    enqueue(num2);
                }
                else if (num==2)
                {
                    printf("Please Enter the Element Which you want to delete: ");
                    scanf("%d",&num2);
                    remove_element(num2);
                }
                else if (num==3)
                {
                    display_queue();
                    
                }
    }
    return 0;
}
