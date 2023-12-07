#include <stdio.h>

#ifndef LIB5
    #define LIB5
    int i = 0;
#endif // LIB5



#define OS 0
#define WINDOWS 2
#define LINUX 1

void main() {
    #if OS == WINDOWS
        printf("Windows\n");
    #elif OS == LINUX
        printf("LINUX\n");
    #else
        printf("UNKNOWN\n");
    #endif // OS

    #undef OS

    struct { struct {int i;} i; } i;;
    i.i.i = 2;
    printf("%d", i.i.i);
}
