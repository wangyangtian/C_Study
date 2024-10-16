#include <stdio.h>

#define N 5

int maze[N][N] = {{0, 0, 0, 0, 1},
                  {1, 0, 0, 0, 1},
                  {1, 0, 1, 0, 1},
                  {1, 0, 1, 1, 1},
                  {1, 0, 0, 1, 1}};

int visited[N][N] = {0};  // 记录已访问的格子

// 判断当前点是否是有效位置（在迷宫内，且是可走的路）
int isValid(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 0 &&
            visited[x][y] == 0);
}

// 递归函数查找路径
int findPath(int x, int y) {
    // 如果到达最后一行且当前点是出口，返回1表示找到出口
    if (x == N - 1 && maze[x][y] == 0) {
        printf("出口位置: (%d, %d)\n", x, y);
        return 1;
    }

    // 标记当前点为已访问
    visited[x][y] = 1;

    // 定义四个移动方向：右、下、左、上
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    // 尝试四个方向
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isValid(newX, newY)) {
            if (findPath(newX, newY)) {
                return 1;  // 找到路径则返回
            }
        }
    }

    // 如果没有找到出口，回溯并取消当前点的访问标记
    visited[x][y] = 0;
    return 0;
}

int main() {
    if (!findPath(0, 0)) {
        printf("没有找到通往出口的路径。\n");
    }
    return 0;
}
