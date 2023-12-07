#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> left(n1);
    vector<int> right(n2);

    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (int i = 0; i < n2; i++)
        right[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSortTwoWay(vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSortTwoWay(arr, low, mid);
        mergeSortTwoWay(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void mergeFour(vector<int>& arr, int low, int mid1, int mid2, int mid3, int high) {
    int n1 = mid1 - low + 1;
    int n2 = mid2 - mid1;
    int n3 = mid3 - mid2;
    int n4 = high - mid3;

    vector<int> left(n1);
    vector<int> middle1(n2);
    vector<int> middle2(n3);
    vector<int> right(n4);

    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (int i = 0; i < n2; i++)
        middle1[i] = arr[mid1 + 1 + i];
    for (int i = 0; i < n3; i++)
        middle2[i] = arr[mid2 + 1 + i];
    for (int i = 0; i < n4; i++)
        right[i] = arr[mid3 + 1 + i];

    int i = 0, j = 0, k = 0, l = 0, m = low;

    while (i < n1 && j < n2 && k < n3 && l < n4) {
        if (left[i] <= middle1[j] && left[i] <= middle2[k] && left[i] <= right[l]) {
            arr[m] = left[i];
            i++;
        } else if (middle1[j] <= left[i] && middle1[j] <= middle2[k] && middle1[j] <= right[l]) {
            arr[m] = middle1[j];
            j++;
        } else if (middle2[k] <= left[i] && middle2[k] <= middle1[j] && middle2[k] <= right[l]) {
            arr[m] = middle2[k];
            k++;
        } else {
            arr[m] = right[l];
            l++;
        }
        m++;
    }

    while (i < n1) {
        arr[m] = left[i];
        i++;
        m++;
    }

    while (j < n2) {
        arr[m] = middle1[j];
        j++;
        m++;
    }

    while (k < n3) {
        arr[m] = middle2[k];
        k++;
        m++;
    }

    while (l < n4) {
        arr[m] = right[l];
        l++;
        m++;
    }
}

void mergeSortFourWay(vector<int>& arr, int low, int high) {
    if (low < high) {
        int n = high - low + 1;
        if (n > 1) {
            int mid1 = low + (n - 1) / 4;
            int mid2 = low + (n - 1) / 2;
            int mid3 = low + (3 * (n - 1)) / 4;
            mergeSortFourWay(arr, low, mid1);
            mergeSortFourWay(arr, mid1 + 1, mid2);
            mergeSortFourWay(arr, mid2 + 1, mid3);
            mergeSortFourWay(arr, mid3 + 1, high);
            mergeFour(arr, low, mid1, mid2, mid3, high);
        }
    }
}

int main() {
    vector<int> arr(6);
    cout<<"Enter Elements in arr: ";
    for (int i = 0; i < 6; i++)
    {
        cin>>arr[i];
    }
    

    int n = arr.size();

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergeSortTwoWay(arr, 0, n - 1);

    cout << "Sorted array using two-way merge: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    vector<int> arr2(6);
    cout<<"Enter Elements in arr2: ";
    for (int i = 0; i < 6; i++)
    {
        cin>>arr2[i];
    }
    mergeSortFourWay(arr2, 0, n - 1);

    cout << "Sorted array using four-way merge: ";
    for (int i = 0; i < n; i++)
        cout << arr2[i] << " ";
    cout << endl;

    return 0;
}











