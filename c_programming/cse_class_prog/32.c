#include <stdio.h>
#pragma pack (1)
struct S {
    int i;
    double d;
};

union U {
    int i;
    double d;
};





typedef struct Person {
    char name[100];
    union Whatever {
        struct Employee {
            char employee_id[20];
            //char name[100];
            double basic_pay;
            double da;
        } e;
        struct Student {
            int roll;
            //char name[100];
            // ...
        } s;
    } u;
    int isStudent;
} Person;

int main() {
    struct S s = {1, 3.6};
    union U u = {0};
    printf("s.i = %d s.d = %lg\n", s.i, s.d);
    printf("&s = %p &s.i = %p &s.d = %p\n", &s, &s.i, &s.d);
    u.d = 1;
    printf("u.i = %d u.d = %lg\n", u.i, u.d);
    printf("&u = %p &u.i = %p &u.d = %p\n", &u, &u.i, &u.d);
    for (char *c = &u, i = 0; i < sizeof (double); c++, i++)
        printf("%u %c\n", (unsigned char)*c, *c);

    Person p = {0}, *pp = &p;
    p.u.e.da = 3000;
    printf("%lg\n", p.u.e.da);
    printf("%lg\n", pp->u.e.da);
    printf("%lg\n", (*pp).u.e.da);
    return  0;
}
