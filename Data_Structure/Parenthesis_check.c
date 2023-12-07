#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int top = -1;

void push(char data,int n,char* stack) {
    if (top == n - 1) {
        printf("Overflow stack!\n");
        return;
    }
    top++;
    stack[top] = data;
}

char pop(char* stack) {
    if (top == -1) {
        printf("Empty stack!\n");
        return ' ';
    }
    char data = stack[top];
    top--;
    return data;
}

int isMatchingPair(char char1, char char2) {
    if (char1 == '(' && char2 == ')') {
        return 1;
    } else if (char1 == '[' && char2 == ']') {
        return 1;
    } else if (char1 == '{' && char2 == '}') {
        return 1;
    } else {
        return 0;
    }
}
int isBalanced(char* str,char* stack) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            push(str[i],strlen(str),stack);
        } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (top == -1) {
                return 0;
            } else if (!isMatchingPair(pop(stack), str[i])) {
                return 0;
            }
        }
    }
    if (top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {

    int n,z,j=0,top=-1;
    printf("Enter the maximum size of the Expression: ");
    scanf("%d",&n);
    getchar();
    char* str=(char*)calloc(n,sizeof(char));
    printf("Enter the Expression: ");
    fgets(str,n,stdin);
    z=strlen(str)-1;
    char* stack=(char*)calloc(z+1,sizeof(char));
   if (isBalanced(str,stack)!=0) {
       printf("The expression is balanced.\n");
   } 
   else {
       printf("The expression is not balanced.\n");
   }
   return 0;
}
