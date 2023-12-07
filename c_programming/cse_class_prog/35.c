#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t Node_t;
typedef struct Node_t *Node;
typedef void *Object;
typedef Node List;

struct Node_t {
    Object data;
    Node next;
};

Node newNode(Object data, Node next) {
    Node node = (Node) calloc(1, sizeof (Node_t));
    node->data = data;
    node->next = next;
    //printf("newNode: node: %d   data: %d   next: %d\n", node, data, next);
    return node;
}

void addFirst(Node *pnode, Object data) {
    //printf("addFirst (before call): pnode: %d   data: %d \n", pnode, data);
    *pnode = newNode(data, *pnode);
    //printf("addFirst (after call): pnode: %d   data: %d \n", pnode, data);
}

void addLast(Node *pnode, Object data) {
    if (*pnode == NULL) {
        addFirst(pnode, data);
        return;
    }
    Node node = *pnode;
    while (node->next)
        node = node->next;
    node->next = newNode(data, NULL);
}

int addAt(Node *pnode, Object data, unsigned int index) {
    if (index == 0) {
        addFirst(pnode, data);
        return 1;
    }
    Node node = *pnode;
    index--;
    while (index > 0 && node != NULL) {
        index--;
        node = node->next;
    }
    if (node == NULL)
        return 0;
    node->next = newNode(data, node->next);
    return 1;
}

Object removeFirst(Node *pnode) {
    if (*pnode == NULL)
        return NULL;
    Node node = *pnode;
    *pnode = (*pnode)->next;
    Object data = node->data;
    free(node);
    return data;
}


Object removeLast(Node *pnode) {
    if (*pnode == NULL || (*pnode)->next == NULL)
        return removeFirst(pnode);

    Node node = *pnode;
    while (node->next->next)
        node = node->next;
    Object data = node->next->data;
    free(node->next);
    node->next = NULL;
    return data;
}

Object removeFrom(Node *pnode, unsigned int index) {
    if (*pnode == NULL || index == 0)
        return removeFirst(pnode);
    Node node = *pnode;
    index--;
    while (node && index) {
        node = node->next;
        index --;
    }
    if (node == NULL || node->next == NULL)
        return NULL;
    Node tempNode = node->next;
    node->next = tempNode->next;
    Object data = tempNode->data;
    free(tempNode);
    return data;
}


void printList(Node node) {
    //for (; node; node = node->next)
    //    printf("%s -> ", node->data);
    while (node) {
        printf("%s -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    Node list = NULL;
    Object data = "Sumit";
    //printf("main (before call): list: %d   data: %d &list: %d\n", list, data, &list);
    addFirst(&list, data);
    //printf("main (after call): list: %d   data: %d &list: %d\n", list, data, &list);
    //addFirst(&list, "Shripad");
    addLast(&list, "Saurya");
    addFirst(&list, "Atul");
    addAt(&list, "A", 2);
    printList(list);
    //data = removeLast(&list);
    //printf("Removed: %s\n", data);
    //printList(list);
    int index = 4;
    data = removeFrom(&list, index);
    printf("Removed: %d from %d\n", data, index);

    //int i = 5;
    //addFirst(&list, &i);
    printList(list);
}

/*
for (int i = 0; i < n; i++)
        //body;

while (node) {
    // body
    node = node->next;
}

for (; node; node = node->next)
        //body;
        */
void f() {
    int i = 5, j = 8;
    printf("%d,", i);
}

void g() {
    int i, j;
    printf("%d, %d", i, j);
}

void main3() {
    f();
    g();
}
