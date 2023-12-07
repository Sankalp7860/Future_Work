#include <stdio.h>
#include <stdlib.h>

typedef struct A_t{
    int i;
    char c;
    // ...
} A_t, *A;


A newA(int i, char c) {
    A a = (A) calloc(1, sizeof (A_t));
    a->i = i;
    a->c = c;
    // ...
    return a;
}

typedef struct B_t{
    int i;
    char c;
    A_t a;
    // ...
} B_t, *B;

B newB(int i, char c, A_t a) {
    B b = (B) calloc(1, sizeof (B_t));
    b->i = i;
    b->c = c;
    b->a = a;
    // ...
    return b;
}


typedef char *String;

struct Name_t {
    String first;
    String middle;
    String last;
};

struct Name_t {
    char first[100];
    char middle[100];
    char last[100];
};

typedef struct Name_t Name_t;
typedef struct Name_t *Name;


Name newName(String first, String middle, String last) {
    Name name = (Name) calloc(1, sizeof (Name_t));
    name->first = first;
    name->middle= middle;
    name->last = last;
    return name;
}

typedef struct ContactInformation_t {
    char *email;
    int mobile;
} ContactInformation_t, *ContactInformation;

ContactInformation newContactInformation(char *email, int mobile) {
    ContactInformation c_i = (ContactInformation) calloc(
        1, sizeof (ContactInformation_t)
    );
    c_i->email = email;
    c_i->mobile = mobile;
}

typedef struct Address_t {
    char *addr_line;
    int pin;
    char *city;
    char *state;
    ContactInformation con_info;
    /*struct ContactInformation_t {
        char *email;
        int mobile;
    } *con_info;*/
} Address_t, *Address;

Address newAddress(char *addr_line, int pin, char *city, char *state, ContactInformation con_info) {
    Address address = (Address) calloc(1, sizeof (Address_t));
    address->addr_line = addr_line;
    address->pin = pin;
    address->city = city;
    address->state = state;
    address->con_info = con_info;
    return address;
}

union P{
    int i;
    float j;
};

struct S {
    int i;
    union P p;
};

struct S s;
s.i = 210;
s.p.i = 10;
s.p.j **


int main() {
    Name name = newName("Hassan", "", "Ali");
    ContactInformation c_i = newContactInformation("has@iiitg.ac.in", 8949);
    Address address = newAddress("Pali", 306401, "Pali", "RJ", c_i);

}
