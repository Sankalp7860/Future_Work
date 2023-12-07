#include <stdio.h>
#include <math.h>

int isArmstrong(int n);
void printArmstrongNumbers(int a, int b);

int main() {
    int a = 10, b = 10000;
    printArmstrongNumbers(a, b);
    return 0;
}

int isArmstrong(int n) {
    int digits = 0, sum = 0;
    for (int m = n; m; m /= 10)
        digits++;
    for (int m = n; m; m /= 10)
        sum += (int) pow(m % 10, digits);
    if (sum == n) return 1;
    return 0;
}

void printArmstrongNumbers(int a, int b) {
    for (; a <= b; a++)
        if (isArmstrong(a))
            printf("%d\n", a);
}

