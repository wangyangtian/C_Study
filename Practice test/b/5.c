#include <stdio.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

int path[ROWS * COLS][2];  // 保存路径坐标
int pathLen = 0;           // 当前路径长度

// 判断当前位置是否可以走
int isSafe(int x, int y) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS && maze[x][y] == 0);
}

// 递归查找路径
void findPath(int x, int y, int endX, int endY) {
    // 到达终点
    if (x == endX && y == endY) {
        path[pathLen][0] = x;
        path[pathLen][1] = y;
        pathLen++;
        // 打印路径
        for (int i = 0; i < pathLen; i++) {
            printf("(%d, %d), ", path[i][0], path[i][1]);
        }
        printf("\n");
        pathLen--;
        return;
    }

    // 标记当前位置
    maze[x][y] = 2;  // 2表示已访问
    path[pathLen][0] = x;
    path[pathLen][1] = y;
    pathLen++;

    // 避免越界，检查 pathLen 是否超出数组大小
    if (pathLen >= ROWS * COLS) {
        pathLen--;       // 防止数组越界
        maze[x][y] = 0;  // 恢复状态
        return;
    }

    // 尝试四个方向
    if (isSafe(x - 1, y)) {  // 上
        findPath(x - 1, y, endX, endY);
    }
    if (isSafe(x + 1, y)) {  // 下
        findPath(x + 1, y, endX, endY);
    }
    if (isSafe(x, y - 1)) {  // 左
        findPath(x, y - 1, endX, endY);
    }
    if (isSafe(x, y + 1)) {  // 右
        findPath(x, y + 1, endX, endY);
    }

    // 回溯，恢复状态
    maze[x][y] = 0;
    pathLen--;
}

int main() {
    int startX = 1, startY = 1;  // 入口
    int endX = 8, endY = 8;      // 出口
    findPath(startX, startY, endX, endY);
    return 0;
}
