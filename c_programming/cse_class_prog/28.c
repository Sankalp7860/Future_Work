#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX_BUFFER_SIZE 500

char *scanString() {
    char buffer[MAX_BUFFER_SIZE];
    buffer[MAX_BUFFER_SIZE - 1] = '\0';
    //.scanf("%s", buffer);
    gets(buffer);
    if (buffer[MAX_BUFFER_SIZE - 1] != '\0')
        return -1;
    int length = strlen(buffer);
    char *string = (char *) calloc(length + 1, sizeof (char));
    strcpy(string, buffer);
    return string;
}

int mystrlen(char s[]) {
    int length = 0;
    while (s[length])
        length++;
    return length;
}

int mystrcmp(char s[], char t[]) {
    int i = 0;
    while (s[i] && t[i]) {
        printf("comparing %c and %c\n", s[i], t[i]);
        if (s[i] != t[i])
            return s[i] - t[i];
        i++;
    }
    return s[i] - t[i];
}

void mystrcpy1(char *target, char *source) {
    while (*source)
        *target++ = *source++;
}

void mystrcpy3(char *target, char *source) {
    while (*source) {
        *target = *source;
        source++;
        target++;
    }
}


void mystrcpy2(char *s, char *t) {
    int i = 0;
    for (; t[i] != '\0'; i++) {
        s[i] = t[i];
    }
    s[i] = '\0';
}

int main() {
    printf("Name: ");
    char *name = scanString();
    printf("Address: ");
    fflush(stdin);
    char *address = scanString();
    //printf("Name: %s\n", name);
    //printf("Address: %s\n", address);
    puts(name);
    puts(address);
    //strcpy(name, address);
    //puts(strcmp(name, address) == 0 ? "Same" : "Different");
    //puts(strcmp(name, address) ? "Different" : "Same");
    //puts(name);
    printf("%d\n", mystrcmp(name, address));
}







