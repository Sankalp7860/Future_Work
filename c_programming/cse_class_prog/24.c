/*
1. Allocate memory for 2D amtrix.
2. Scan a 2D matrix
3. free a 2D matrix
4. add to matrices
5. sub ''
6. multi
7. transpose.
*/
#include<stdlib.h>
#include<stdio.h>

double **createMatrix(int r, int c) {
    double **matrix = (double **) calloc(r, sizeof (double *));
    for (int i = 0; i < r; i++)
        matrix[i] = (double *) calloc(c, sizeof (double));
    return matrix;
}

double **deleteMatrix(double** matrix, int r) {
    for (int i = 0; i < r; i++)
        free(matrix[i]);
    free(matrix);
    return NULL;
}

void scanMatrix(double **matrix, int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%lg", &matrix[i][j]);
}

void printMatrix(double **matrix, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%lg \t ", matrix[i][j]);
        printf("\n");
    }
}

double **addMatrix(double **a, double **b, int r, int c) {
    double **mat = createMatrix(r, c);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            mat[i][j] = a[i][j] + b[i][j];
    return mat;
}

double **subMatrix(double **a, double **b, int r, int c) {
    double **mat = createMatrix(r, c);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            mat[i][j] = a[i][j] - b[i][j];
    return mat;
}

double **transpose(double **a, int r, int c) {
    double **mat = createMatrix(c, r);
    for (int i = 0; i < c; i++)
        for (int j = 0; j < r; j++)
            mat[i][j] = a[j][i];
    return mat;
}

double **mulMatrix(double **a, double **b, int m, int n, int p) {
    double **mat = createMatrix(m, p);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++) {
            mat[i][j] = 0.0;
            for (int k = 0; k < n; k++)
                mat[i][j] += a[i][k] * b[k][j];
        }
    return mat;
}

int main() {
    int m = 0, n = 0;
    scanf("%d%d", &m, &n);
    double **a = createMatrix(m, n);
    double **b = createMatrix(m, n);

    scanMatrix(a, m, n);
    scanMatrix(b, m, n);
    double **c = subMatrix(a, b, m, n);
    printf("C:\n");
    printMatrix(c, m, n);

    a = deleteMatrix(a, m);
    b = deleteMatrix(b, m);
    c = deleteMatrix(c, m);
    return 0;
}

