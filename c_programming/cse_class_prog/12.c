#include <stdio.h>

const double PI = 3.14;

void wrongSwap(int a, int b) {
    int t = a;
    a = b;
    b = t;
}

void swap(int *pa, int *pb) {
    int t = *pa;
    printf("SWAP: pa = %d \t pb = %d \t &t = %d\n", pa, pb, &t);
    *pa = *pb;
    *pb = t;
}

int main() {
    int array[5];
    for (int i = 0; i < 5; i++) {
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    array[0] = 16;
    return 0;
}

int main2() {
    int a = 2;
    int b = 3;
    int array[5];
    array[0] = 1;
    array[2] = 5;


    printf("MAIN: &a = %d \t &b = %d\n", &a, &b);
    swap(&a, &b);
    printf("%d %d\n", a, b);

    return 0;
}
