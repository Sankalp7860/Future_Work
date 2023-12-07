#include <stdio.h>

int main() {
    int a[20], b;
    char d[20];

    int *p = (int *) calloc(5, sizeof (int));
    char *c = (char*) p;

    printf("%x %x \n", p, c);
    fflush(stdin);
    return 0;
}

int c(){
    return 0;
}
