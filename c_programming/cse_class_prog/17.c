#include <stdlib.h>
#include <stdio.h>

int main() {
    /*
    int n = 0;
    scanf("%d", &n);
    double *p = (double *) calloc(n, sizeof(double));
    for (int i = 0; i < n; i++)
        scanf("%lg", &p[i]);

    for (int i = 0; i < n; i++)
        printf("%lg ", p[i]);

    free(p);
    p = NULL;
    */
    int a[2][4][5] = {
    {
        {11, 12, 13, 14, 15},
        {21, 2, 3, 4, 5},
        {31, 2, 3, 4, 5},
        {41, 2, 3, 4, 5},
    },{
        {51, 52, 53, 14, 15},
        {41, 2, 3, 47, 85},
        {31, 2, 3, 4, 5},
        {41, 2, 3, 4, 35},
    }
    };

    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 5; j++)
                printf("%d ", &a[k][i][j]);
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
