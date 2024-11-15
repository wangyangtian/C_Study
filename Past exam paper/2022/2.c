#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

int judge(int a[N][N]) {
    int row_total = 0, col_total = 0, diag1 = 0, diag2 = 0;

    for (int i = 0; i < N; i++) {
        row_total += a[0][i];
        col_total += a[i][0];
        diag1 += a[i][i];
        diag2 += a[i][N - 1 - i];
    }

    if (diag1 != diag2)
        return 0;

    for (int i = 0; i < N; i++) {
        int temp_row = 0, temp_col = 0;

        for (int j = 0; j < N; j++) {
            temp_row += a[i][j];
            temp_col += a[j][i];
        }
        if (temp_row != row_total || temp_col != col_total)
            return 0;
    }
    return 1;
}

int main() {
    int matrix[N][N] = {
        {17, 24, 1, 8, 15},
        {23, 5, 7, 14, 16},
        {4, 6, 13, 20, 22},
        {10, 12, 19, 21, 3},
        {11, 18, 25, 2, 9}};

    char path[] = "result.txt";
    FILE *fp = fopen(path, "w");

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
            fprintf(fp, "%d ", matrix[i][j]);
        }
        printf("\n");
        fprintf(fp, "\n");
    }

    if (judge(matrix)) {
        printf("该矩阵是魔幻矩阵\n");
        fprintf(fp, "该矩阵是魔幻矩阵\n");
    } else {
        printf("该矩阵不是魔幻矩阵\n");
        fprintf(fp, "该矩阵不是魔幻矩阵\n");
    }
    fclose(fp);
    return 0;
}