#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef struct Grid {
    int data[MAXSIZE][MAXSIZE];
    int col, row;
} Grid;

void Land(Grid *g, int x, int y) {
    if (x < 0 || x >= g->row || y < 0 || y >= g->col || g->data[x][y] != 1) {
        return;
    }
    // 将当前部分标记为访问过
    g->data[x][y] = -1;

    // 递归检查上下左右
    Land(g, x + 1, y);  // 下
    Land(g, x - 1, y);  // 上
    Land(g, x, y + 1);  // 右
    Land(g, x, y - 1);  // 左
}

int totalLand(Grid g) {
    int total = 0;
    for (int i = 0; i < g.row; i++) {
        for (int j = 0; j < g.col; j++) {
            if (g.data[i][j] == 1) {
                total++;
                Land(&g, i, j);
            }
        }
    }
    return total;
}

int main() {
    Grid g = {.col = 4,
              .row = 5,
              .data = {{1, 1, 0, 0, 0},
                       {1, 1, 0, 0, 0},
                       {0, 0, 1, 0, 0},
                       {0, 0, 0, 1, 1}}};
    printf("%d", totalLand(g));
    return 0;
}