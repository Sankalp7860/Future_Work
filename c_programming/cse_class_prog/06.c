#include <stdio.h>
#include <math.h>

int largest(int a, int b, int c) {
    return a > b ? (a > c ? a : c)
                 : (b > c ? b : c);
}

int main() {
    int a = 10, b = 10000, c= 18;
    printf("%d", largest(a, b, c));
    return 0;
}


