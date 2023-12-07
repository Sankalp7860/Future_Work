#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FranchiseOutlet {
    int FOUN; 
    char location[50]; 
    int seatingCapacity; 
    struct FranchiseOutlet* left;
    struct FranchiseOutlet* right;
};

struct FranchiseOutlet* createFranchiseOutlet(int FOUN, char location[], int seatingCapacity) {
    struct FranchiseOutlet* temp = (struct FranchiseOutlet*)malloc(sizeof(struct FranchiseOutlet));
    temp->FOUN = FOUN;
    temp->seatingCapacity = seatingCapacity;
    strcpy(temp->location, location);
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insertFranchiseOutlet(struct FranchiseOutlet** root, int FOUN, char location[], int seatingCapacity) {
    if (*root == NULL) {
        *root = createFranchiseOutlet(FOUN, location, seatingCapacity);
    }
    else if (FOUN == (*root)->FOUN) { 
        (*root)->seatingCapacity = seatingCapacity;
    }
    else if (FOUN < (*root)->FOUN) {
        insertFranchiseOutlet(&(*root)->left, FOUN, location, seatingCapacity);
    }
    else {
        insertFranchiseOutlet(&(*root)->right, FOUN, location, seatingCapacity);
    }
}

struct FranchiseOutlet* searchFranchiseOutlet(struct FranchiseOutlet* root, int FOUN) {
    if (root == NULL || root->FOUN == FOUN) {
        return root;
    }
    else if (root->FOUN > FOUN) {
        return searchFranchiseOutlet(root->left, FOUN);
    }
    else {
        return searchFranchiseOutlet(root->right, FOUN);
    }
}

void displayAllFranchiseOutlets(struct FranchiseOutlet* root) {
    if (root != NULL) {
        displayAllFranchiseOutlets(root->left);
        printf("FOUN: %d\nFranchise Outlet Location: %s\nSeating Capacity: %d\n\n", root->FOUN, root->location, root->seatingCapacity);
        displayAllFranchiseOutlets(root->right);
    }
}

void displayLowestLevelFranchiseOutlets(struct FranchiseOutlet* root, int level, int* maxLevel) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) { 
        if (level == *maxLevel) {
            printf("FOUN: %d\nFranchise Outlet Location: %s\nSeating Capacity: %d\n\n", root->FOUN, root->location, root->seatingCapacity);
        }
        else if (level > *maxLevel) {
            *maxLevel = level;
            printf("\nFranchise Outlet(s) at the lowest level of tree:\n");
            printf("FOUN: %d\nFranchise Outlet Location: %s\nSeating Capacity: %d\n\n", root->FOUN, root->location, root->seatingCapacity);
        }
    }
    else {
        displayLowestLevelFranchiseOutlets(root->left, level + 1, maxLevel);
        displayLowestLevelFranchiseOutlets(root->right, level + 1, maxLevel);
    }
}

void updateSeatingCapacity(struct FranchiseOutlet* root, int FOUN, int newSeatingCapacity) {
    struct FranchiseOutlet* temp = searchFranchiseOutlet(root, FOUN);
    if (temp != NULL) {
        temp->seatingCapacity = newSeatingCapacity;
        printf("Franchise outlet with FOUN %d has been updated with new seating capacity %d.\n", FOUN, newSeatingCapacity);
    }
    else {
        printf("Franchise outlet with FOUN %d not found.\n", FOUN);
    }
}

struct FranchiseOutlet* findMinFranchiseOutlet(struct FranchiseOutlet* node) {
    struct FranchiseOutlet* current = node;

    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

struct FranchiseOutlet* removeFranchiseOutlet(struct FranchiseOutlet* root, int FOUN) {
    if (root == NULL) {
        return NULL;
    }
    if (FOUN < root->FOUN) {
        root->left = removeFranchiseOutlet(root->left, FOUN);
    }
    else if (FOUN > root->FOUN) {
        root->right = removeFranchiseOutlet(root->right, FOUN);
    }
    else {
        if (root->left == NULL) {
            struct FranchiseOutlet* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct FranchiseOutlet* temp = root->left;
            free(root);
            return temp;
        }

        struct FranchiseOutlet* temp = findMinFranchiseOutlet(root->right);

        root->FOUN = temp->FOUN;
        strcpy(root->location, temp->location);
        root->seatingCapacity = temp->seatingCapacity;

        root->right = removeFranchiseOutlet(root->right, temp->FOUN);
    }
    return root;
}

int main() {
    struct FranchiseOutlet* root = NULL;
    int choice, FOUN, seatingCapacity, maxLevel = 0;
    char location[50];

    do {
        printf("\nPlease choose one of the following options:\n");
        printf("1. Insert a Franchise Outlet\n");
        printf("2. Search for a Franchise Outlet\n");
        printf("3. Display All Franchise Outlets\n");
        printf("4. Display All Franchise Outlets that are at the lowest level in the BST\n");
        printf("5. Update Seating Capacity\n");
        printf("6. Remove a Franchise Outlet\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter FOUN of the Franchise Outlet: ");
                scanf("%d", &FOUN);
                printf("Enter the Franchise Outlet Location: ");
                scanf("%s", location);
                printf("Enter the Seating Capacity: ");
                scanf("%d", &seatingCapacity);
                insertFranchiseOutlet(&root, FOUN, location, seatingCapacity);
                break;
            case 2:
                printf("Enter FOUN of the Franchise Outlet to search for: ");
                scanf("%d", &FOUN);
                struct FranchiseOutlet* temp;
                temp = searchFranchiseOutlet(root, FOUN);
                if (temp != NULL) {
                    printf("FOUN: %d\nFranchise Outlet Location: %s\nSeating Capacity: %d\n\n", temp->FOUN, temp->location, temp->seatingCapacity);
                }
                else {
                    printf("Franchise outlet with FOUN %d not found.\n", FOUN);
                }
                break;
            case 3:
                printf("\nAll Franchise Outlets in the BST:\n");
                displayAllFranchiseOutlets(root);
                break;
            case 4:
                printf("\nSearching for franchise outlets at the lowest level in the BST...\n");
                displayLowestLevelFranchiseOutlets(root, 1, &maxLevel);
                break;
            case 5:
                printf("Enter FOUN of the Franchise Outlet to update seating capacity: ");
                scanf("%d", &FOUN);
                printf("Enter new Seating Capacity: ");
                scanf("%d", &seatingCapacity);
                updateSeatingCapacity(root, FOUN, seatingCapacity);
                break;
            case 6:
                printf("Enter FOUN of the Franchise Outlet to remove from the system: ");
                scanf("%d", &FOUN);
                root = removeFranchiseOutlet(root, FOUN);
                printf("Franchise outlet with FOUN %d has been removed from the system.\n", FOUN);
                break;
            case 7:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
                break;
        }
    } while (choice != 7);

    return 0;
}
