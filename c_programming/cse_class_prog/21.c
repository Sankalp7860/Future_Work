#include <stdio.h>
#include <stdlib.h>

int sum(int a[], int n){ // int *a <-> int a[]
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];

    a++;
    a--;
    a = a + 2;
    return sum;
}

int main() {
    int n = 0;
    scanf("%d", &n);
    int *p = (int *) calloc(n, sizeof (int));
    for (int i = 0; i < n; i++)
        scanf("%d", p + i); // p + i <-> &p[i] 5 <-> &i[p]

    //for (int i = n - 1; i >= 0; i--)
    //printf("%d ", p[i]); // *(p + i) <-> p[i] <-> i[p]

    printf("sum: %d\n", sum(p, n));
    return 0;
}
