#include <stdio.h>
#include<stdlib.h>
typedef struct Node_t Node_t;
typedef struct Node_t * Node;
struct Node_t
{
    Node prev;
    int data;
    Node next;
};

Node newNode(Node prev,int data, Node next){
    Node node=(Node)calloc(1,sizeof(Node_t));
    node->prev=prev;
    node->data=data;
    node->next=next;
    return node;
}

void addFirst(int data,Node * pnode){
(*pnode)=newNode(NULL,data,*pnode);
if (((*pnode)->next)!=NULL)
{
Node node=*pnode;
(node->next)->prev=(*pnode);
}

}
void addAt(int index,int data, Node * pnode){
    if (index==1)
    {
        addFirst(data,pnode);
        return;
    }
Node temp=*pnode;
for (int i = 0; i < index-2 && temp!=NULL; i++)
{
    temp=temp->next;
}
if (temp==NULL)
{
    return;
}
temp->next=newNode(temp,data,temp->next);
Node head=temp->next->next;
head->prev=temp->next;
}



void addLast(int data,Node * pnode){
    if ((*pnode)==NULL)
    {
        addFirst(data,pnode);
    }
    Node node =(*pnode);
    while (node->next)
    {
        node=node->next;
    }
    node->next=newNode(node,data,NULL);
}

int removeFirst(Node * pnode){
    Node temp=*pnode;
    *pnode=(*pnode)->next;
    (*pnode)->prev=NULL;
    int data=temp->data;
    free(temp);
    return data;
}
int removeAt(int index,Node * pnode){
    Node temp=*pnode;
    if (index==1)
    {
        return removeFirst(pnode);
    }
    
    for (int i = 0; i < index-2 && temp!=NULL; i++)
    {
        temp=temp->next;
    }
    if (temp==NULL)
    {
        return -1;
    }
    
    temp->next->next->prev=temp;
    Node head=temp;
    head=head->next;
    temp->next=head->next;
    int data=head->data;
    free(head);
    return data;
}
int removeLast(Node * pnode){
    Node temp=*pnode;
    while (temp->next->next)
    {
        temp=temp->next;
    }
    int data=temp->next->data;
    temp->next->prev=NULL;
    free(temp->next->next);
    temp->next=NULL;
    return data;
}

void printForwardList(Node pnode){
printf("NULL <-> ");
while (pnode)
{
    printf("%d <-> ",pnode->data);
    pnode=pnode->next;
}
printf("NULL\n");
}
void printBackwardList(Node pnode){
Node temp=pnode;
while (temp->next)
{
    temp=temp->next;
}
printf("NULL <-> ");
while (temp->prev)
{
    printf("%d <-> ",temp->data);
    temp=temp->prev;
}
printf("%d <-> ",temp->data);
printf("NULL\n");
}

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
        "Press 8: To print the list from forward order.\n"
        "Press 9: To print the list from backward order.\n"
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
     if (list==NULL)
     {
        printf("Empty Linked List!!!\n");
        continue;
     }
        
     del=removeFirst(&list);     
    printf("The removed value is: %d\n",del);
    }
    else if (n==5)
    {
     if (list==NULL)
     {
        printf("Empty Linked List!!!\n");
        continue;
     }
        
    printf("Please Enter the position at which you want to remove a number:");
    scanf("%d",&index);
     del=removeAt(index,&list);     
    printf("The removed value is: %d\n",del);
    }
    else if (n==6)
    {
     if (list==NULL)
     {
        printf("Empty Linked List!!!\n");
        continue;
     }
        
     del=removeLast(&list);     
    printf("The removed value is: %d\n",del);
    }
    else if (n==8)
    {
        printForwardList(list);
    }
    else if (n==9)
    {
        printBackwardList(list);
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