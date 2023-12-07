#include <stdio.h>
#include <stdlib.h>

int binarySearchIterative(int a[], int size, int element) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        printf("low = %d mid = %d high = %d a[mid] = %d\n", low, mid, high, a[mid]);
        if (a[mid] == element) return mid;
        else if (a[mid] < element) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int binarySearch(int a[], int low, int high, int element) {
    printf("binarySearch(%d, %d, %d)\n", low, high, element);
    if (low > high) return -1;
    int mid = (low + high) / 2;
    printf("low = %d mid = %d high = %d a[mid] = %d\n", low, mid, high, a[mid]);
    if (a[mid] == element) return mid;
    if (a[mid] < element) return binarySearch(a, mid + 1, high, element);
    return binarySearch(a, low, mid - 1, element);
}

void swap(int a[], int i, int j) {
    //a[i] ^= a[j];
    //a[j] ^= a[i];
    //a[i] ^= a[j];
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex])
                minIndex = j;
        }
        swap(a, i, minIndex);
    }
}

void printArray(int *a, int n, int aj, int aj_1) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("comparing %d with %d\n", aj, aj_1);
}

void bubbleSort(int a[], int n) {
    int swapped = 1;
    for (int i = 0; swapped && i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            printArray(a, n, a[j], a[j + 1]);
            if (a[j] > a[j + 1]) {
                swap(a, j, j + 1);
                swapped = 1;
            }
        }
        printf("\n");
    }
}

int main() {
    int a[] = {2, 8, 18, 22, 46, 78, 83, 96, 99};
    //int a[] = {15, 2, 35, 9, 14, 02, -15, -23, 58, -95, 0};
    int size = sizeof (a) / sizeof (a[0]);
    int element = 18;
    //int index = binarySearch(a, 0, size - 1, element);//binarySearchIterative(a, size, element);
    //printf("%d\n", index);
    bubbleSort(a, size);
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    return 0;
}
