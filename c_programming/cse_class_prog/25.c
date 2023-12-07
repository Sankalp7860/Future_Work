#include <stdio.h>
#include <float.h>
#include <limits.h>

void insert(int *a, int n, int item) {
    int i = n - 1;
    for (; i >= 0; i--) {
        if (a[i] > item)
            a[i + 1] = a[i];
        else
            break;
    }
    a[i + 1] = item;
}

int subarraySum(int *a, int n) {
    if (n <= 0) return 0;
    int bestSum = a[0];
    for (int i = 0; i < n; i++) {
        int currentSum = 0;
        for (int j = i; j < n; j++) {
            currentSum += a[j];
        }
        if (currentSum > bestSum)
            bestSum = currentSum;
    }
    return bestSum;
}

int max(int x, int y) {
    return x > y ? x : y;
}

int min(int x, int y) {
    return x < y ? x : y;
}

int subarraySum2(int *a, int n) {
    if (n == 1) return a[0];
    int bestSum = a[0], currentSum = a[0];
    for (int i = 1; i < n; i++) {
        currentSum = max(currentSum + a[i], a[i]);
        bestSum = max(bestSum, currentSum);
    }
    return bestSum;
}

int circularsubarraySum(int *a, int n) {
    if (n == 1) return a[0];
    int bestMax = a[0], currentMax = a[0], bestMin = a[0],
        currentMin = a[0], sum = a[0];
    for (int i = 1; i < n; i++) {
        currentMax = max(currentMax + a[i], a[i]);
        bestMax = max(bestMax, currentMax);

        currentMin = min(currentMin + a[i], a[i]);
        bestMin = min(bestMin, currentMin);

        sum += a[i];
    }

    if (bestMin == sum) return bestMax;

    return max(bestMax, sum - bestMin);
}

int equals(int *a, int *b, int n) {
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}

int f(int *a, int na, int *b, int nb) {
    for (int i = 0; i < na - nb; i++) {
        if (equals(a + i, b, nb))
            return 1;
    }
    return 0;
}

void g(int *a, int n) {
    int lastNonZeroIndex = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0)
            a[++lastNonZeroIndex] = a[i];
    }
    for (int i = lastNonZeroIndex + 1; i < n; i++)
        a[i] = 0;
}

int linerSearch(int *a, int n , int item) {
    for (int i = 0; i < n; i++)
        if (a[i] == item)
            return i;
    return -1;
}

int linearSearchRecursive(int *a, int n, int item) {
    if (n == 0) return -1; // never found
    if (*a == item) return 0; // found
    return 1 + linearSearchRecursive(a++, n--, item); //not found
}

linearSearchRecursive(a, na, item, 0);


void main(){
    int a[] = {2, 5, 8, 10, 12, 14, 17, 0};
    int n = 7;
    insert(a, n, 13);
    for (int i = 0; i < n + 1; i++)
        printf("%d ", a[i]);
}
