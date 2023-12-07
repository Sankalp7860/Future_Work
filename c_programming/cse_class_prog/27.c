#include <stdio.h>

void printMenu() {
    printf(
        "1 - Add two integers.\n"
        "2 - Sub two integers.\n"
        "3 - Exit.\n"
        "Enter your choice: "
    );
}

int f(int month, int day) {
    int d = 0;
    switch (month - 1) {
        case 11 : d += 30;
        case 10 : d += 31;
        case  9 : d += 30;
        case  8 : d += 31;
        case  7 : d += 31;
        case  6 : d += 30;
        case  5 : d += 31;
        case  4 : d += 30;
        case  3 : d += 31;
        case  2 : d += 28;
        case  1 : d += 31;
                  break;
        default : return -1;
    }
    return d + days;
}

void main() {
    do {
        printMenu();
        int n = 0;
        scanf("%d", &n);
        swtcih (n) {
            case 1: //add
                    break;
            case 2: // sub
                    break;

        }
    } while(1);
}

