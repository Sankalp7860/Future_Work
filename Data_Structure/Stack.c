#include<stdio.h>
#include<stdlib.h>
int top=-1;
void push(int* stack,int num,int size){
    if (top==size)
    {
        printf("stack overflow!!!");
        return;
    }
    else
    {
        top++;
        stack[top]=num;
    }
        
}
int pop(int *stack){
int item;
if (top==-1)
{
    printf("stack underflow!!!\n");
    exit(0);
    
}
else{
    item=stack[top];
    top--;
    return item; 
    }

}
void PrintStack(int * stack,int size){
    for (int i = top; i !=-1; i--)
    {
        printf("%d ",stack[i]);
    }
printf("\n");
}
int main(){
int size,num,choice;
printf("Enter the size of the stack: ");
scanf("%d",&size);
int *stack=malloc(size*sizeof(int));
while (1)
{
    printf("\tWelcome to stack based Program!!!\n"
            "Press 1: To push a number into a stack\n"  
            "Press 2: To pop a number from a stack\n"  
            "Press 3: To dispay the stack\n"  
            "Press 4: To exit\n");
    printf("Please Enter your choice: ");
    scanf("%d",&choice);
    if (choice==1)
    {
        printf("Enter the number you want to push in the stack: ");
        scanf("%d",&num);
        push(stack,num,size);
    }
    else if (choice==2)
    {
        printf("The number which is popped out from the stack is %d\n",pop(stack));
    }
    else if (choice==3)
    {
        PrintStack(stack,size);
    }
    else if (choice==4)
    {
        printf("\n\tHave a nice Day!!!\n");
        exit(0);
    }
    else
    {
        printf("You have Entered a wrong choice!!!\n"
                "Please Try again!!!\n");
    }
    
    
}


return 0;
}