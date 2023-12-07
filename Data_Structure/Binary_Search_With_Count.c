#include <stdio.h>

int binarySearchWithCount(int arr[], int size, int target, int *count) {
    int left = 0;
    int right = size - 1;
    int found = 0;
    *count = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            found = 1;
            *count += 1;

            int i = mid - 1;
            while (i >= left && arr[i] == target) {
                *count += 1;
                i--;
            }

            i = mid + 1;
            while (i <= right && arr[i] == target) {
                *count += 1;
                i++;
            }

            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    
    return -1;
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the sorted array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the target element: ");
    scanf("%d", &target);

    int count;
    int index = binarySearchWithCount(arr, size, target, &count);

    if (index != -1) {
        printf("Target element %d found at position %d\n", target, index+1);
        printf("Total count of occurrences: %d\n", count);

        int i = index - 1;
        while (i >= 0&& arr[i] == target) {
            printf("Position of occurrence: %d\n", i+1);
            i--;
        }

        i = index + 1;
        while (i < size && arr[i] == target) {
            printf("Position of occurrence: %d\n", i+1);
            i++;
        }
    }
    else {
        printf("Target element %d not found in the array\n", target);
    }

    return 0;
}