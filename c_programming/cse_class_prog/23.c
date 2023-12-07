#include<stdio.h>


int findMin(int *a, int n) {
    int min = a[0];
    for (int i = 1; i < n; i++)
        min = min > a[i] ? a[i] : min;
        //if (min > a[i]) min = a[i];
    return min;
}

int *copy(int *a, int n) {
    int *b = (int *) calloc(n, sizeof (int));
    for (int i = 0; i < n; i++)
        b[i] = a[i];
    return b;
}

int countDuplicates(int *a, int n) {
    int *flags = (int *) calloc(n, sizeof (int));
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (flags[i]) continue;
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j])
                flags[i] = flags[j] = 1;
        }
        if (flags[i]) count++;
        printf("%d\n", a[i]);
    }
    free(flags);
    return count;
}

int *mergeDescendingArrays(int *a, int na, int *b, int nb) {
    int *c = (int *) calloc(na + nb, sizeof (int));
    int ia = 0, ib = 0,ic = 0;
    while (ia < na && ib < nb && ic < na + nb) {
        //c[ic++] = a[ia] > b[ib] ? a[ia++] : b[ib++];
        if (a[ia] > b[ib]) {
            c[ic++] = a[ia++];
        } else {
            c[ic++] = b[ib++];
        }
    }
    while (ia < na)
        c[ic++] = a[ia++];
    while (ib < nb)
        c[ic++] = b[ib++];
    return c;
}

int *findFrequencies(int *a, int n) {
    int *f = (int *) calloc(n, sizeof (int));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            //f[i] = a[i] == a[j] ? f[i] + 1 : f[i];
            if (a[i] == a[j]) f[i]++;
    return f;
}

int **evenOffSeparator1(int *a, int n) {

}

void evenOffSeparator2(int *a, int n, int **ppEven, int **ppOdd, int *pnEven, int *pnOdd) {
    int nO = 0;
    for (int i = 0; i < n; i++)
        if (a[i] % 2 == 1)
            nO++;
    int nE = n - nO;
    int *pOdd = (int *) calloc(nO, sizeof (int));
    int *pEven = (int *) calloc(nE, sizeof (int));
    for (int i = 0, iO = 0, iE = 0; i < n; i++)
        if (a[i] % 2 == 1)
            pOdd[iO++] = a[i];
        else
            pEven[iE++] = a[i];

    *ppOdd = pOdd;
    *ppEven = pEven;
    *pnOdd = nO;
    *pnEven = nE;
}

void main() {
    int a[] = {2, 3, 2, 2, 3, 4, 1}, b[] = {9, 7, 6, 5, 1, 0};
    int na = sizeof (a) / sizeof(int);
    int nb = sizeof (b) / sizeof(int);

    //printf("REMOVE THIS: %d\n", countDuplicates(a, n));

    int *pEven, *pOdd, nEven, nOdd;
    void evenOffSeparator2(a, na, &pEven, &pOdd, &nEven, &nOdd);

    int *c = findFrequencies(a, na);
    for (int i = 0; i < na; i++)
        printf("%d %d\n", a[i], c[i]);
    free(c);
    c = NULL;
}
