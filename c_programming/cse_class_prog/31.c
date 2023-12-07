#include <stdio.h>
#pragma pack (1)
struct Student {
    int roll;
    char name[50];
    char address[100];
    double gpa;
};

struct Student2 {
    int roll;
    char* name;
    char* address;
    double gpa;
};

int main() {
    struct Student2 s[2] = {
        {218, "Ujjwal", "Ajmer", 9.5},
        {208, "Sumit",  "Gaya",  9.4}
    };
    //s[0] = s[1];
    for (int i = 0; i < 2; i++)
        printf("%d %s %s %lg\n", s[i].roll, s[i].name, s[i].address, s[i].gpa);
    struct Student p = {218, "Ujjwal", "Ajmer", 9.5};
    scanf("%d%s%s%lg", &p.roll, &p.name, &p.address, &p.gpa);
    printf("%d %s %s %lg\n", p.roll, p.name, p.address, p.gpa);
    //printf("%d %d %d %d %d %d\n", &p, &p.roll, &p.name, &p.address, &p.gpa, sizeof (p));
    return 0;
}
