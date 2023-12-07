#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int houseId;
};

struct Student* createStudent(char name[], int houseId) {
    struct Student* student = (struct Student*)malloc(sizeof(struct Student));
    strcpy(student->name, name);
    student->houseId = houseId;
    return student;
}

void swap(struct Student** first, struct Student** second) {
    struct Student* temp = *first;
    *first = *second;
    *second = temp;
}

int partition(struct Student* students[], int low, int high) {
    int pivot = students[high]->houseId;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (students[j]->houseId <= pivot) {
            i++;
            swap(&students[i], &students[j]);
        }
    }

    swap(&students[i + 1], &students[high]);
    return i + 1;
}

void quickSort(struct Student* students[], int low, int high) {
    if (low < high) {
        int pi = partition(students, low, high);

        quickSort(students, low, pi - 1);
        quickSort(students, pi + 1, high);
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student* students[n];

    for (int i = 0; i < n; i++) {
        char name[50];
        int houseId;
        getchar();
        printf("Enter the name of student %d: ", i+1);
        fgets(name,50,stdin);
        printf("Enter the house Id of student %d: ", i+1);
        scanf("%d", &houseId);
        students[i] = createStudent(name, houseId);
    }

    quickSort(students, 0, n - 1);

    printf("\nSorted list of students according to their house ID:\n");

    int countRitchie = 0, countBabbage = 0, countTuring = 0, countDijkstra = 0;

    for (int i = 0; i < n; i++) {
        printf("%-20s House %d\n", students[i]->name, students[i]->houseId);
        
        switch (students[i]->houseId) {
            case 1:
                countRitchie++;
                break;
            case 2:
                countBabbage++;
                break;
            case 4:
                countTuring++;
                break;
            case 8:
                countDijkstra++;
                break;
            default:
                break;
        }
    }

    printf("\nNumber of students in each house:\n");
    printf("Ritchie House: %d\n", countRitchie);
    printf("Babbage House: %d\n", countBabbage);
    printf("Turing House: %d\n", countTuring);
    printf("Dijkstra House: %d\n", countDijkstra);

    return 0;
}
