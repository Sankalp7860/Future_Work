#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)calloc(1,sizeof(struct Node));
    node->left = NULL;
    node->data = data;
    node->right = NULL;
    return node;
}

struct Node* Build_BinaryTree() {
    int data;
    printf("Please Enter the data for the node (Enter -1 for NULL): ");
    scanf("%d", &data);

    if (data == -1)
        return NULL;
    struct Node* node = newNode(data);
    printf("Please Enter the left child of %d:\n", data);
    node->left = Build_BinaryTree();

    printf("Please Enter the right child of %d:\n", data);
    node->right = Build_BinaryTree();

    return node;
}

int Diameter(struct Node* root, int* height) {
    if (root == NULL) {
        *height = 0;
        return 0;
    }
    int leftHeight = 0, rightHeight = 0;
    int leftDiameter = Diameter(root->left, &leftHeight);
    int rightDiameter =Diameter(root->right, &rightHeight);

    *height = 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
    return ((leftHeight + rightHeight > leftDiameter) ? leftHeight + rightHeight : leftDiameter) > rightDiameter ?
           (leftHeight + rightHeight) : rightDiameter;
}


void MaxValue(struct Node* node, int maxVals[], int level) {
    if (node == NULL) {
        return;
    }

    if (node->data > maxVals[level]) {
        maxVals[level] = node->data;
    }

    MaxValue(node->left, maxVals, level+1);
    MaxValue(node->right, maxVals, level+1);
}
void largest_value_level(struct Node* root) {
    if (root == NULL) {
        printf("The Tree is Empty!!!\n");
        return;
    }
    int *arr=(int*)calloc(100,sizeof(int));
    for (int i = 0; i < 100; i++) {
        arr[i] = -1;    
    }

    int level = 0;
    MaxValue(root, arr, level);   

    printf("The Maximum values at each level are: ");
    for (int i = 0; i < 100; i++) {
        if (arr[i] != -1) {  
            printf("%d ", arr[i]);
        } else {
            break; 
        }
    }
}

int main() {
    struct Node* root = NULL;
    int hieght=0;
    printf("\t*** Building Binary Tree ***\n\n");
    root = Build_BinaryTree();
    //diameter(root);
    largest_value_level(root);
    printf("\nThe diameter of the tree is: %d",Diameter(root,&hieght)+1);
    return 0;
}


















