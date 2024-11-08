#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 20

void Table(int n) {
    if (n % 2 != 0) {
        printf("人数应该为偶数！");
        exit(0);
    }

    int schedule[MAX_PLAYERS][MAX_PLAYERS - 1];
    int player[MAX_PLAYERS];

    for (int i = 0; i < n; i++) {
        player[i] = i + 1;
    }

    for (int day = 1; day <= n - 1; day++) {
        printf("第%d天比赛\n", day);

        for (int i = 0; i < n / 2; i++) {
            int p1 = player[i];
            int p2 = player[n - 1 - i];
            printf("选手%d vs 选手%d \n", p1, p2);
        }

        int last = player[n - 1];
        for (int i = n - 1; i > 1; i--) {
            player[i] = player[i - 1];
        }
        player[1] = last;
    }
}

int main() {
    int n;
    printf("请输入参加比赛的选手数量（偶数）：");
    scanf("%d", &n);
    Table(n);
    return 0;
}