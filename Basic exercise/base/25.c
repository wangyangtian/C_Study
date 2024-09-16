#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int **Transpose(int **a, int m, int n) {
    int **transpose = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        transpose[i] = (int *)malloc(m * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            transpose[j][i] = a[i][j];
        }
    }

    return transpose;
}

void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m = 3, n = 2;
    int **a = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        a[i] = (int *)malloc(n * sizeof(int));
    }

    // 初始化矩阵
    int count = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = count++;
        }
    }

    printf("Original matrix:\n");
    printMatrix(a, m, n);

    int **transposed = Transpose(a, m, n);

    printf("Transposed matrix:\n");
    printMatrix(transposed, n, m);

    // 释放内存
    for (int i = 0; i < m; i++) {
        free(a[i]);
    }
    free(a);

    for (int i = 0; i < n; i++) {
        free(transposed[i]);
    }
    free(transposed);

    return 0;
}
