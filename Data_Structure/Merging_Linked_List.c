#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    if (l1->val <= l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0)
        return NULL;
    if (listsSize == 1)
        return lists[0];
    if (listsSize == 2)
        return mergeTwoLists(lists[0], lists[1]);
    int mid = listsSize / 2;
    struct ListNode* left = mergeKLists(lists, mid);
    struct ListNode* right = mergeKLists(lists + mid, listsSize - mid);
    return mergeTwoLists(left, right);
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

void freeLists(struct ListNode** lists, int listsSize) {
    for (int i = 0; i < listsSize; i++) {
        struct ListNode* curr = lists[i];
        while (curr != NULL) {
            struct ListNode* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(lists);
}

int main() {
    int k;
    printf("Enter the number of linked lists: ");
    if (scanf("%d", &k) != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        return 1;
    }

    struct ListNode** lists = malloc(k * sizeof(struct ListNode*));
    if (lists == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    for (int i = 0; i < k; i++) {
        int size;
        printf("Enter the size of linked list %d: ", i + 1);
        if (scanf("%d", &size) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            freeLists(lists, i); 
            free(lists); 
            return 1;
        }

        struct ListNode* head = NULL;
        struct ListNode* tail = NULL;

        for (int j = 0; j < size; j++) {
            int val;
            printf("Enter the value of node %d: ", j + 1);
            if (scanf("%d", &val) != 1) {
                printf("Invalid input. Please enter a valid number.\n");
                freeLists(lists, i); 
                free(lists); 
                return 1;
            }

            struct ListNode* newNode = malloc(sizeof(struct ListNode));
            if (newNode == NULL) {
                printf("Memory allocation failed. Exiting...\n");
                freeLists(lists, i); 
                free(lists); 
                return 1;
            }
            newNode->val = val;
            newNode->next = NULL;

            if (head == NULL) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        lists[i] = head;
    }

    struct ListNode* mergedList = mergeKLists(lists, k);

    printf("Merged list: ");
    printList(mergedList);

    return 0;
}
