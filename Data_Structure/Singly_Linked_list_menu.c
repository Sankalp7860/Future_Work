#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>
 typedef struct Node_t Node_t;
 typedef struct Node_t * Node;
 
 struct Node_t{
    int data;
    Node next;
};
Node newNode(int data, Node next){
Node node=(Node)calloc(1,sizeof(Node_t));
node->data=data;
node->next=next;
return node;
}
void addFirst(int data,Node * pnode){
*pnode=newNode(data,*pnode);}



void addAt(int index,int data,Node * pnode){
Node node=*pnode;
if (index==1){
addFirst(data,pnode);
    return;}


for(int i=0 ; i<index-2 && node!=NULL ; i++)
{
    node=node->next;
}
if (node==NULL){
    return;}
node->next=newNode(data,node->next);
}


void addLast(int data,Node * pnode){
    if (*pnode==NULL){
        addFirst(data,pnode);
        return;}
    Node node = *pnode;
    while (node->next)
        node = node->next;
    node->next = newNode(data, NULL);
}

int removeFirst(Node * pnode){
    Node node=(*pnode);
    (*pnode)=(*pnode)->next;
    int data=node->data;
    free(node);
    return data;
}

int removeAt(int index,Node * pnode){
    Node node=(*pnode);
    if (index==1){
        removeFirst(pnode);}
    for (int i = 0; i <index-2 && node!=NULL; i++){
        node=node->next;}
        if (node==NULL)
        {
            return -1;
        }
        
        int data=(node->next)->data;
    Node temp=node->next;
    node->next=(node->next)->next;
    free(temp);
    return data;
}

int removeLast(Node * pnode){
    Node node=(*pnode);
    while (((node->next)->next)!=NULL){
        node=node->next;
    }
    int data=((node->next)->data);
    free(((node->next)->next));
    node->next=NULL;
    return data; 
}
void printList(Node  node){
while(node){
    printf("%d->",node->data);
    node=node->next;
}
printf("NULL\n");
}
// void slowPrint(char * s){
// while (*s)
// {
//     printf("%c",*s++);
//     Sleep(50);
// }

// }

int main()
{
int n,data,index,del;
Node list= NULL;
printf("\t*** Welcome to Linked List Menu Based Program *** \n"
        "Press 1: To add Number in the begining of the list.\n"
        "Press 2: To add Number at the nth position of the list.\n"
        "Press 3: To add Number at the last of the list.\n"
        "Press 4: To remove Number in the begining of the list.\n"
        "Press 5: To remove Number at the nth position of the list.\n"
        "Press 6: To remove Number at the last of the list.\n"
        "Press 9: To print the list.\n"
        "Press 0: To exit from the Program.\n\n");
while(1){
    printf("Please Enter Your Choice:");
    scanf("%d",&n);
    if (n==0){
        printf("\tThank You\n");
        printf("\tHave a nice day\n");
        exit(0);}
    else if (n==1)
    {
    printf("Please Enter the Number which you want to add in the begining:");
    scanf("%d",&data);
     addFirst(data,&list);     
    }
    else if (n==2)
    {
    printf("Please Enter the position at which you want to add a number:");
    scanf("%d",&index);
    printf("Please Enter the Number which you want to add at the %d position of the list:",index);
    scanf("%d",&data);
     addAt(index,data,&list);     
    }
    else if (n==3)
    {
    printf("Please Enter the Number which you want to add at the last:");
    scanf("%d",&data);
     addLast(data,&list);     
    }
    else if (n==4)
    {
     del=removeFirst(&list);     
    printf("The removed value is: %d\n",del);
    }
    else if (n==5)
    {
    printf("Please Enter the position at which you want to remove a number:");
    scanf("%d",&index);
     del=removeAt(index,&list);     
    printf("The removed value is: %d\n",del);
    }
    else if (n==6)
    {
     del=removeLast(&list);     
    printf("The removed value is: %d\n",del);
    }
    else if (n==9)
    {
        printList(list);
    }
    else
    {
        printf("You Have Entered a Wrong choice!!!\n"
                "Please Try Again.");
    }
    getchar();

    }

    return 0;
}