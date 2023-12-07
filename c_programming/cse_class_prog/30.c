#include <stdio.h>
#include <string.h>
#include <stdio.h>

void helper(int m, char *buffer, char *type) {
    char *_1[] = {
        "", "One ", "Two ", "Three ", "Four ", "Five ", "Six ",
        "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ",
        "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ",
        "Seventeen ", "Eighteen ", "Nineteen "
    };
    char *_10[] = {
        "", "", "Twenty ", "Thirty ", "Forty ", "Fifty ",
        "Sixty ", "Seventy ", "Eighty ", "Ninety "
    };
    if (m < 20) {
        strcat(buffer, _1[m]);
    } else {
        strcat(buffer, _10[m / 10]);
        strcat(buffer, _1 [m % 10]);
    }
    if (m != 0)
        strcat(buffer, type);
}

char *toWords(int n) {
    char buffer[1000] = "";
    int m = n / 10000000;
    helper(m, buffer, "Crore ");
    m = (n % 10000000) / 100000;
    helper(m, buffer, "Lakh ");
    m = (n % 100000) / 1000;
    helper(m, buffer, "Thousand ");
    m = (n % 1000) / 100;
    helper(m, buffer, "Hundred ");
    m = n % 100;
    helper(m, buffer, "");
    if (n == 0)
        strcpy(buffer, "Zero ");
    int length = strlen(buffer);
    buffer[length - 1] = '\0';
    char * words = (char *) calloc(length, sizeof (char));
    strcpy(words, buffer);
    return words;
}

int main() {
    int n = 19450274;
    char *words = toWords(n);
    puts(words);
    free(words);
    words = NULL;
    return 0;
}
