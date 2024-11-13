#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 100
#define MAX_COL 100

typedef struct Raster {
    int data[MAX_ROW][MAX_COL];
    int row;
    int col;
} Raster;

void FloodFill(Raster *r, int x, int y, int seed_color, int target_color) {
    if (r->data[x][y] != seed_color)
        return;
    if (x >= 0 && x < r->row && y >= 0 && y < r->col) {
        r->data[x][y] = target_color;
        FloodFill(r, x + 1, y, seed_color, target_color);
        FloodFill(r, x - 1, y, seed_color, target_color);
        FloodFill(r, x, y + 1, seed_color, target_color);
        FloodFill(r, x, y - 1, seed_color, target_color);
    }
}

int main() {
    // 示例代码：初始化栅格并测试 FloodFill
    Raster r = {.row = 5, .col = 5};

    // 初始化栅格数据，设置为全 0
    for (int i = 0; i < r.row; i++) {
        for (int j = 0; j < r.col; j++) {
            r.data[i][j] = 0;
        }
    }

    // 设置一个区域为 1
    r.data[1][1] = 1;
    r.data[1][2] = 1;
    r.data[2][1] = 1;
    r.data[2][2] = 1;

    // 调用 FloodFill 从 (1,1) 开始将颜色 1 填充为 2
    FloodFill(&r, 1, 1, 1, 2);

    // 输出结果
    for (int i = 0; i < r.row; i++) {
        for (int j = 0; j < r.col; j++) {
            printf("%d ", r.data[i][j]);
        }
        printf("\n");
    }

    return 0;
}