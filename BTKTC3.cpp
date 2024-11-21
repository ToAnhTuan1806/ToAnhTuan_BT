#include <stdio.h>

void inputMatrix(int mat[100][100], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &mat[i][j]);
}

void transposeMatrix(int src[100][100], int dest[100][100], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            dest[j][i] = src[i][j];
}

void multiplyMatrices(int a[100][100], int b[100][100], int res[100][100], int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            res[i][j] = 0;
            for (int k = 0; k < m; k++)
                res[i][j] += a[i][k] * b[k][j];
        }
}

void printMatrix(int mat[100][100], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            printf("%d%c", mat[i][j], j < size - 1 ? ' ' : '\n');
    }
}

int main() {
    int t, a[100][100], b[100][100], c[100][100], n, m;
    scanf("%d", &t);
    for (int test = 1; test <= t; test++) {
        scanf("%d %d", &n, &m);
        inputMatrix(a, n, m);
        transposeMatrix(a, b, n, m);
        multiplyMatrices(a, b, c, n, m);
        printf("Test %d:\n", test);
        printMatrix(c, n);
    }
    return 0;
}

