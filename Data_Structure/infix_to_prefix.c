# include <stdio.h>
# include <string.h>

int top=-1;
char stack[200];

void push(char symbol) {
	top++;
	stack[top]=symbol;
}

char pop() {
	char a;
	a=stack[top];
	top--;
	return a;
}
int isOperator(char symbol) {
	switch(symbol) {
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
		case '$':
		case '&':
		case '(':
		case ')':
		return 1;
		break;
		default:
		        return 0;
	}
}
int prcd( char symbol) 
 {
	switch(symbol) {
				case '+':
		        case '-':
		        return 2;
				break;
				case '*':
		        case '/':
		        return 4;
				break;
				case '$':
		        case '^':
		        return 6;
				break;
				case '#':
		        case '(':
		        case ')':
		        return 1;
				break;
	}
}
char * reverse(char array[30]) 
{
	int i,j;
	char temp[100];
	for (i=strlen(array)-1,j=0;i+1!=0;--i,++j) {
		temp[j]=array[i];
	}
	temp[j]='\0';
	strcpy(array,temp);
	return array;
}
void infixtoprefix(char infix[20],char prefix[20]) {
	int i,j=0;
	char symbol;
	stack[++top]='#';
	reverse(infix);
	for (i=0;i<strlen(infix);i++) {
		symbol=infix[i];
		if (isOperator(symbol)==0) {
			prefix[j]=symbol;
			j++;
		} else {
			if (symbol==')') {
				push(symbol);
			} else if(symbol == '(') {
				while (stack[top]!=')') {
					prefix[j]=pop();
					j++;
				}
				pop();
			} else {
				if (prcd(stack[top])<=prcd(symbol)) {
					push(symbol);
				} else {
					while(prcd(stack[top])>prcd(symbol)) {
						prefix[j]=pop();
						j++;
					}
					push(symbol);
				}
			}
		}
	}
	while (stack[top]!='#') {
		prefix[j]=pop();
		j++;
	}
	prefix[j]='\0';
}
int main() {
	char infix[20],prefix[20],temp;
	printf("Enter infix operation: ");
	fgets(infix,20,stdin);
	infixtoprefix(infix,prefix);
	reverse(prefix);
	puts((prefix));
    return 0;
}