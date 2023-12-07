#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

int isFull(struct Stack* stack) {
    return (stack->top == stack->capacity - 1);
}

void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

int count(int temp){
    int num=temp;
    int cout=0;
    for (int i = 0; num!=0; i++)
    {
        num/=10;
        cout++;
    }
    return cout;
}
int truncateNumber(int number, int k) {
    struct Stack* stack = createStack(11);
    int temp = number;
    int cout=count(number);
    int z=cout-k;
    
    while (temp != 0) {
        push(stack, temp % 10);
        temp /= 10;
    }
    int truncatedNumber = 0;
    while (z) {
        truncatedNumber = truncatedNumber * 10 + pop(stack);
        z--;
    }

    return truncatedNumber;
}
int main() {
    int number, k;

    printf("Enter number: ");
    scanf("%d", &number);

    printf("Enter number of digits to be truncated from the right: ");
    scanf("%d", &k);
    int cout=count(number);
    int z=cout-k;
    if (z<0)
    {
        printf("Invalid input!!!");
        exit(1);
    }
    
    int truncatedNumber = truncateNumber(number, k);
    
    printf("Number after truncation: %d\n", truncatedNumber);

    return 0;
}
