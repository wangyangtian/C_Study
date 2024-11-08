#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 10
#define MAX_COLOR 4

int adjMatrix[MAX_N][MAX_N];
int colors[MAX_N] = {0};
int N;
int count = 0;

bool isValid(int region, int color) {
    for (int i = 0; i < N; i++) {
        if (adjMatrix[region][i] && colors[i] == color)
            return false;
    }
    return true;
}

void colorGraph(int region) {
    if (region == N) {
        count++;
        printf("第%d组涂色方案\n", count);
        for (int i = 0; i < N; i++) {
            printf("区域%d涂%d ", i + 1, colors[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 1; i <= MAX_COLOR; i++) {
        if (isValid(region, i)) {
            colors[region] = i;
            colorGraph(region + 1);
            colors[region] = 0;
        }
    }
}

int main() {
    // printf("输入区域数:\n");
    // scanf("%d", &N);
    // printf("输入邻接矩阵:\n");

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++)
    //         scanf("%d", &adjMatrix[i][j]);
    // }
    N = 5;  // 区域数量
    int adjMatrixExample[5][5] = {
        {0, 1, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 0}};

    // 将示例邻接矩阵复制到全局的 adjMatrix 中
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            adjMatrix[i][j] = adjMatrixExample[i][j];
        }
    }

    colorGraph(0);
    printf("共%d中涂色方案\n", count);
    return 0;
}