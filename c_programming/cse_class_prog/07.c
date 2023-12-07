#include <stdio.h>

unsigned int f(unsigned int a) {
    while (a > 9)
        a /= 10;
    return a;
}

int main() {
    unsigned int a = -9;
    printf("%u", f(a));
    return 0;
}
