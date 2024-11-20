#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Graph {
    int adjMatrix[MAX][MAX];  // 邻接矩阵，1表示相邻，0表示不相邻
    char region[MAX];         // 地区
    int r_num;                // 地区数
} Graph;

bool check(Graph g, int colors[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (g.adjMatrix[i][j] && colors[i] == colors[j])
                return false;
        }
    }
    return true;
}

int main() {
    Graph g;
    g.r_num = 4;  // 图中节点数

    // 初始化邻接矩阵（示例图）
    int adjMatrix[MAX][MAX] = {
        {0, 1, 1, 0},  // 节点 0
        {1, 0, 0, 1},  // 节点 1
        {1, 0, 0, 1},  // 节点 2
        {0, 1, 1, 0}   // 节点 3
    };

    // 将邻接矩阵复制到图结构中
    for (int i = 0; i < g.r_num; i++) {
        for (int j = 0; j < g.r_num; j++) {
            g.adjMatrix[i][j] = adjMatrix[i][j];
        }
    }

    // 测试涂色方案
    int colors1[] = {1, 2, 2, 1};  // 合法的涂色方案
    int colors2[] = {1, 1, 2, 1};  // 非法的涂色方案

    // 检查涂色方案
    if (check(g, colors1, g.r_num)) {
        printf("colors1 是合法的涂色方案。\n");
    } else {
        printf("colors1 不是合法的涂色方案。\n");
    }

    if (check(g, colors2, g.r_num)) {
        printf("colors2 是合法的涂色方案。\n");
    } else {
        printf("colors2 不是合法的涂色方案。\n");
    }

    return 0;
}