#include <stdio.h>

int f(int n, int r) {
    printf("n = %d, \t r = %d\n", n, r);
    if (n < 10) return r * 10 + n;
    return f(n / 10, r * 10 + n  % 10);
}

int main() {
    int n = 12345;
    printf("%d\n", f(n, 0));
    return 0;
}
