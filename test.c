#include <stdbool.h>
#include <stdio.h>

typedef struct Loc {
    int x, y;
} Loc;

int board[8][8] = {0};  // 棋盘
Loc location[8];        // 用于存储每个皇后的位置
int count = 0;          // 记录解的数量

// 检查位置 l 是否安全
bool check(Loc l) {
    // 检查上方列
    for (int i = 0; i < l.x; i++) {
        if (board[i][l.y] != 0)
            return false;
    }

    // 检查左上对角线
    for (int i = l.x - 1, j = l.y - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] != 0)
            return false;
    }

    // 检查右上对角线
    for (int i = l.x - 1, j = l.y + 1; i >= 0 && j < 8; i--, j++) {
        if (board[i][j] != 0)
            return false;
    }

    return true;
}

// 递归回溯函数，逐行放置皇后
void solveNQueens(int row) {
    if (row == 8) {  // 如果成功放置8个皇后
        count++;
        printf("Solution %d:\n", count);
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                printf(board[i][j] == 1 ? "Q " : ". ");
            }
            printf("\n");
        }
        printf("\n");
        return;
    }

    for (int col = 0; col < 8; col++) {
        Loc l = {row, col};
        if (check(l)) {
            board[row][col] = 1;    // 放置皇后
            location[row] = l;      // 记录皇后位置
            solveNQueens(row + 1);  // 递归到下一行
            board[row][col] = 0;    // 撤销选择
        }
    }
}

int main() {
    solveNQueens(0);                         // 从第0行开始放置皇后
    printf("Total solutions: %d\n", count);  // 输出解的总数
    return 0;
}
