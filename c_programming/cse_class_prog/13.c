#include <stdio.h>

void swap(int a[], int b[]) {
    //printf("a = %d b = %d\n", a, b);
    //printf("*a = %d *b = %d\n", *a, *b);
    printf("%d %d %d %d\n", b[0], b[1], a[-1], a[0]);
    int t = a[0];
    a[0] = b[0];
    b[0] = t;
    printf("*a = %d *b = %d\n", *a, *b);
}

int main() {
    int x = 1, y = 2;
    printf("&x = %d &y = %d\n", &x, &y);
    swap(&x, &y);
    //printf("&x = %d &y = %d\n", &x, &y);
    printf("x = %d y = %d\n", x, y);
    return 0;
}
