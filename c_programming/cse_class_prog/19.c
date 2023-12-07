#include <stdio.h>

typedef int * Array ;
Array a; // int *a;

typedef double(*Function)(double, double);
typedef int Length;
Function f1, f2, f3;

Length length;

double add(double x, double y) {
	return x + y;
}
double sub(double x, double y) {
	return x - y;
}

double mul(double x, double y) {
	return x * y;
}
double div(double x, double y) {
	return x / y;
}

Function inverse(Function function) {
    if (function == add) return sub;
    if (function == sub) return add;
    if (function == mul) return div;
    if (function == div) return mul;
    return NULL;
}

typedef int Length;
typedef double (*Anyname)(double x, double y);

int main() {
    Anyname anyname = add;
    Function f = add;
    printf("%lg\n", inverse(f)(2, 3));
    return 0;
}
