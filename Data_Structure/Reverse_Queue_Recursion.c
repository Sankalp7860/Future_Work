#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int queue_arr[MAX];
int rear=-1;
int front=-1;

int isFull()
{
        if( rear==MAX-1 )
                return 1;
        else
                return 0;
}
int isEmpty()
{
        if( front==-1 || front==rear+1 )
                return 1;
        else
                return 0;
}
void insert(int item)
{
        if( isFull() )
        {
                printf("\nQueue Overflow\n");
                return;
        }
        if( front == -1 )
                front=0;
        rear=rear+1;
        queue_arr[rear]=item ;
}

int del()
{
        int item;
        if( isEmpty() )
        {
                printf("\nQueue Underflow\n");
                exit(1);
        }
        item=queue_arr[front];
        front=front+1;
        return item;
}
void reverseQueue() {
    if (isEmpty())
        return;

    int data = del();
    reverseQueue();
    insert(data);
}
void display()
{
        int i;
        if ( isEmpty() )
        {
                printf("\nQueue is empty\n");
                return;
        }
        printf("\nQueue is :\n");
        for(i=front;i<=rear;i++)
                printf("%d  ",queue_arr[i]);
        printf("\n");
}

int main()
{
        int choice,item;
        while(1)
        {
                printf("\n *** Welcome to Queue menu based program ***\n\n");
                printf("Press 1:To Insert in the queue.\n");
                printf("Press 2:To Delete from the queue.\n");
                printf("Press 3:To Display the elements of the queue\n");
                printf("Press 4:To reverse the elements of the queue\n");
                printf("Press 5:To Quit the program\n");
                printf("\n Please Enter your choice : ");
                scanf("%d",&choice);

                switch(choice)
                {
                case 1:
                        printf("\nInput the element for adding in queue : ");
                        scanf("%d",&item);
                        insert(item);
                        break;
                case 2:
                        item=del();
                        printf("\nDeleted element is  %d\n",item);
                        break;
                case 3:
                        display();
                        break;
                case 4:
                        reverseQueue();
                        printf("Queue Reverse Successfully!!!\n");
                        break;
                case 5:
                        printf("Thank You!!!");
                        exit(1);
                default:
                        printf("\nWrong choice\n");
                        printf("Please Try Again!!!\n");
                }
        }

        return 0;

}


