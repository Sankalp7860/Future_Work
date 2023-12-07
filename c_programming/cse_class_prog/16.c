#include <stdlib.h>
#include <stdio.h>

double average1(double *a, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++)
        sum += a[i];
    return sum / size;
}

double average2(double *a, int size) {
    double sum = 0.0;
    for (int copy = size; copy; copy--)
        sum += *a++;
    return sum / size;
}

int main() {
    int n = 0;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    double *a = calloc(n, sizeof (double));
    printf("Enter the marks for %d students: ", n);
    for (int i = 0; i < n; i++)
        scanf("%lg", &a[i]);

    for (int i = 0; i < n; i++)
        printf("%lg ", a[i]);

    printf("\nAverage: %lg %lg", average1(a, n), average2(a, n));

    free(a);
    a = NULL;
    return 0;
}

