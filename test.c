#include <stdio.h>

#define MAX_PLAYERS 20  // 最大选手数量，可以调整

void generateSchedule(int n) {
    if (n % 2 != 0) {
        printf("选手数量必须为偶数！\n");
        return;
    }

    int schedule[MAX_PLAYERS][MAX_PLAYERS - 1];  // 存储比赛日程
    int players[MAX_PLAYERS];                    // 选手数组

    // 初始化选手数组
    for (int i = 0; i < n; i++) {
        players[i] = i + 1;
    }

    // 生成比赛日程
    for (int day = 0; day < n - 1; day++) {
        printf("第%d天比赛：\n", day + 1);
        for (int i = 0; i < n / 2; i++) {
            int player1 = players[i];
            int player2 = players[n / 2 + i];
            printf("选手%d vs 选手%d\n", player1, player2);
        }

        // 将选手按顺时针轮转，选手1保持不动
        int last = players[n - 1];
        for (int i = n - 1; i > 1; i--) {
            players[i] = players[i - 1];
        }
        players[1] = last;
    }
}

int main() {
    int n;
    printf("请输入参加比赛的选手数量（偶数）：");
    scanf("%d", &n);
    generateSchedule(n);
    return 0;
}
