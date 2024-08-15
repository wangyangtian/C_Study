#include <stdio.h>

void findSpecialElements(int A[][100], int m, int n) {
    // 遍历矩阵中的每个元素
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int current = A[i][j];
            
            // 查找所在行的最小值和最大值
            int rowMin = A[i][0], rowMax = A[i][0];
            for (int k = 1; k < n; k++) {
                if (A[i][k] < rowMin) rowMin = A[i][k];
                if (A[i][k] > rowMax) rowMax = A[i][k];
            }
            
            // 查找所在列的最小值和最大值
            int colMin = A[0][j], colMax = A[0][j];
            for (int k = 1; k < m; k++) {
                if (A[k][j] < colMin) colMin = A[k][j];
                if (A[k][j] > colMax) colMax = A[k][j];
            }
            
            // 判断是否满足条件1：既是所在行中的最小值，又是所在列中的最小值
            if (current == rowMin && current == colMin) {
                printf("元素(%d, %d) = %d 是行和列的最小值\n", i, j, current);
            }
            
            // 判断是否满足条件2：既是所在行中的最大值，又是所在列中的最大值
            if (current == rowMax && current == colMax) {
                printf("元素(%d, %d) = %d 是行和列的最大值\n", i, j, current);
            }
        }
    }
}

int main() {
    int A[100][100] = {
        {10, 2, 5},
        {3, 7, 9},
        {8, 6, 4}
    };
    int m = 3, n = 3;
    
    findSpecialElements(A, m, n);
    
    return 0;
}
