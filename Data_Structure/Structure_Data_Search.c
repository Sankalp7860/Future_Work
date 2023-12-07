#include <stdio.h>
#include <string.h>

#define MAX_ARRAY_SIZE 100

struct Student {
    char name[50];
    unsigned int jeeRank;
    char college[50];
};

void swap(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(struct Student arr[], int size, int field) {
    int i, j;

    for (i = 1; i < size; i++) {
        struct Student key = arr[i];
        j = i - 1;

        switch (field) {
            case 1: 
                while (j >= 0 && strcmp(arr[j].name, key.name) > 0) {
                    arr[j + 1] = arr[j];
                    j--;
                }
                break;
            case 2: 
                while (j >= 0 && arr[j].jeeRank > key.jeeRank) {
                    arr[j + 1] = arr[j];
                    j--;
                }
                break;
            case 3: 
                while (j >= 0 && strcmp(arr[j].college, key.college) > 0) {
                    arr[j + 1] = arr[j];
                    j--;
                }
                break;
        }

        arr[j + 1] = key;
    }
}

int main() {
    struct Student students[MAX_ARRAY_SIZE];
    int size, i, field;

    printf("Enter the number of students (max %d): ", MAX_ARRAY_SIZE);
    scanf("%d", &size);

    if (size <= 0 || size > MAX_ARRAY_SIZE) {
        printf("Invalid array size.\n");
        return 0;
    }

    printf("Enter the details of each student:\n");

    for (i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("JEE Rank: ");
        scanf("%d", &students[i].jeeRank);
        printf("College: ");
        scanf("%s", students[i].college);
    }

    printf("Sort by field:\n");
    printf("1. Name\n");
    printf("2. JEE Rank\n");
    printf("3. College\n");
    printf("Enter the field number to sort by: ");
    scanf("%d", &field);

    insertionSort(students, size, field);

    printf("\nSorted array of students:\n");
    for (i = 0; i < size; i++) {
        printf("Student %d\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("JEE Rank: %d\n", students[i].jeeRank);
        printf("College: %s\n", students[i].college);
        printf("-------------------\n");
    }

    return 0;
}
