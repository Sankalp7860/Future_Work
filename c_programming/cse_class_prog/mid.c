#include <stdio.h>

int reverse(int n, int v) {
    return n == 0 ? v : reverse(n / 10, v * 10 + n % 10);
}

int mirror(int n, int v) {
    int d = n % 10;
    d = d == 5 ? 2 : d;
    d = d == 2 ? 5 : d;
    return n == 0 ? v : mirror(n / 10, v * 10 + d);
}

int isPrime();

int isAlpha(int n) {
    for (int copy = n; copy; copy /= 10) {
        int d = copy % 10;
        if (d == 3 || d == 4 || d == 6 || d == 7 || d == 9)
            return 0;
    }
    if (
        isPrime(n) && isPrime(reverse(n, 0)) &&
        isPrime(mirror(n, 0)) && isPrime(reverse(mirror(n, 0), 0))
    ) return 1;
    return 0;
}

void main() {

}
