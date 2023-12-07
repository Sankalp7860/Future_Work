#include<stdio.h>

int sum(int *a, int n){ // int *a <-> int a[]
    printf("%p %p (inside sum)\n", a, &a);
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

void main() {
    int *q;
    int p[] = {1,2};
    int *r = {4,5};
    printf("%p %p \n", &r, r );
    int a[5] = {1, 2, 3, 4, 5}, b[500], n = 5;
    printf("sum: %d %p %p\n", sum(a, n), a, &a);
}
