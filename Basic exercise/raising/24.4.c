#include <stdio.h>
#include <stdbool.h>

#define N 5

int maze[N][N] = {
    {0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {1, 0, 1, 0, 1},
    {1, 0, 1, 1, 1},
    {1, 0, 0, 1, 1}
};

bool isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 0);
}

bool solveMaze(int x, int y) {
    // 如果到达最后一行且在有效列内，说明找到了出口
    if (x == N - 1 && isSafe(x, y)) {
        printf("Exit found at (%d, %d)\n", x, y);
        return true;
    }

    // 检查当前位置是否合法
    if (isSafe(x, y)) {
        // 标记为已访问
        maze[x][y] = -1; // 使用 -1 表示已经访问过

        // 向下走
        if (solveMaze(x + 1, y)) {
            return true;
        }
        // 向右走
        if (solveMaze(x, y + 1)) {
            return true;
        }
        // 向上走
        if (solveMaze(x - 1, y)) {
            return true;
        }
        // 向左走
        if (solveMaze(x, y - 1)) {
            return true;
        }

        // 撤销标记，回溯
        maze[x][y] = 0; // 恢复为可走状态
    }

    return false; // 找不到出口
}

int main() {
    if (solveMaze(0, 0)) {
        printf("Path to exit found!\n");
    } else {
        printf("No exit found!\n");
    }

    return 0;
}
