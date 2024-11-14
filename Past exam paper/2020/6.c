#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef struct _Map {
    int elev[MAXSIZE][MAXSIZE];
    int col, row;
} Map;

// 检查(x, y)是否越界
int inBounds(Map m, int x, int y) {
    return x >= 0 && x < m.row && y >= 0 && y < m.col;
}

int Area(Map *m, int x, int y) {
    // 越界或已经访问过，或者当前点是0，返回0
    if (!inBounds(*m, x, y) || m->elev[x][y] == 0) {
        return 0;
    }
    // 标记当前位置为已访问
    m->elev[x][y] = 0;

    return 1 + Area(m, x, y + 1) + Area(m, x, y - 1) + Area(m, x + 1, y) + Area(m, x - 1, y);
}

int main() {
    // 初始化Map结构体
    Map m = {
        .row = 5,
        .col = 5,
        .elev = {
            {1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 1, 1, 1},
            {0, 0, 1, 1, 0},
            {0, 0, 0, 0, 0}}};

    // 测试从(0, 0)开始的区域面积
    int x = 0, y = 0;
    printf("Area starting at (%d, %d) is: %d\n", x, y, Area(&m, x, y));

    // 测试从(2, 2)开始的区域面积
    x = 2, y = 2;
    printf("Area starting at (%d, %d) is: %d\n", x, y, Area(&m, x, y));

    return 0;
}