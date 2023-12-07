#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void printLeafNodesLeftToRight(struct Node* root) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
        printf("%d ", root->data);

    printLeafNodesLeftToRight(root->left);
    printLeafNodesLeftToRight(root->right);
}

void printLeafNodesRightToLeft(struct Node* root) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
        printf("%d ", root->data);

    printLeafNodesRightToLeft(root->right);
    printLeafNodesRightToLeft(root->left);
}

int countLeafNodes(struct Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

struct Node* buildTree() {
    int data;
    printf("Enter the data for the node (Enter -1 for NULL): ");
    scanf("%d", &data);

    if (data == -1)
        return NULL;

    struct Node* node = newNode(data);

    printf("Enter the left child of %d:\n", data);
    node->left = buildTree();

    printf("Enter the right child of %d:\n", data);
    node->right = buildTree();

    return node;
}

int main() {
    struct Node* root = NULL;

    printf("Building Binary Tree:\n");
    root = buildTree();

    printf("Leaf Nodes from Left to Right: ");
    printLeafNodesLeftToRight(root);

    printf("\nLeaf Nodes from Right to Left: ");
    printLeafNodesRightToLeft(root);

    int totalLeafNodes = countLeafNodes(root);
    printf("\nTotal number of Leaf Nodes: %d\n", totalLeafNodes);

    return 0;
}
