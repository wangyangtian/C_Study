#include <stdio.h>
#include <stdlib.h>

// 矩阵大小
#define SIZE 5

// 交换两个数的值
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 对一维数组进行排序（冒泡排序）
void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// 将矩阵调整为目标形态
void adjustMatrix(int matrix[SIZE][SIZE]) {
    int temp[SIZE * SIZE];
    int index = 0;

    // 将矩阵元素复制到一维数组
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            temp[index++] = matrix[i][j];
        }
    }

    // 对一维数组排序
    bubbleSort(temp, SIZE * SIZE);

    // 重新填充矩阵
    index = 0;

    // 填充四个角
    matrix[0][0] = temp[index++];
    matrix[0][SIZE - 1] = temp[index++];
    matrix[SIZE - 1][0] = temp[index++];
    matrix[SIZE - 1][SIZE - 1] = temp[index++];

    // 填充中心最大值
    matrix[SIZE / 2][SIZE / 2] = temp[SIZE * SIZE - 1];

    // 填充其他位置
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // 跳过四个角和中心位置
            if ((i == 0 && j == 0) || (i == 0 && j == SIZE - 1) ||
                (i == SIZE - 1 && j == 0) || (i == SIZE - 1 && j == SIZE - 1) ||
                (i == SIZE / 2 && j == SIZE / 2)) {
                continue;
            }
            matrix[i][j] = temp[index++];
        }
    }
}

// 打印矩阵
void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// 测试函数
int main() {
    int matrix[SIZE][SIZE] = {
        {5, 12, 7, 1, 3},
        {8, 2, 14, 6, 4},
        {9, 11, 13, 10, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}};

    printf("原始矩阵：\n");
    printMatrix(matrix);

    adjustMatrix(matrix);

    printf("调整后的矩阵：\n");
    printMatrix(matrix);

    return 0;
}
