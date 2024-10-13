#include <stdbool.h>
#include <stdio.h>

int board[8][8] = {0};  // 棋盘
int count = 0;          // 记录解的数量

// 检查在第row行的col列放置是否安全
bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        // 检查列冲突
        if (board[i][col] == 1)
            return false;
        // 检查左上对角线冲突
        if (col - (row - i) >= 0 && board[i][col - (row - i)] == 1)
            return false;
        // 检查右上对角线冲突
        if (col + (row - i) < 8 && board[i][col + (row - i)] == 1)
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
        if (isSafe(row, col)) {
            board[row][col] = 1;    // 放置皇后
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
