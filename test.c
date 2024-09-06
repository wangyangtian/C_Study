#include <stdio.h>

// 计算换法的函数
int countWays(int amount, int coins[], int n) {
    // 创建一个二维数组 dp，其中 dp[i][j] 表示用前 i 种硬币凑出金额 j 的方法数
    int dp[n + 1][amount + 1];

    // 初始化第一列，即金额为 0 时，只有一种换法：不使用任何硬币
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    // 初始化第一行，即没有硬币时，凑任何正金额都没有换法
    for (int j = 1; j <= amount; j++) {
        dp[0][j] = 0;
    }

    // 填充 dp 数组
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= amount; j++) {
            if (j >= coins[i - 1]) {
                // 如果当前金额 j 大于等于当前硬币面额 coins[i - 1]
                // 方法数为：包括当前硬币的情况 + 不包括当前硬币的情况
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
            } else {
                // 否则，只能使用前 i-1 种硬币
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // 返回用所有硬币凑出目标金额的方法数
    return dp[n][amount];
}

int main() {
    int coins[] = {1, 2, 5};  // 硬币面额
    int amount = 100;         // 目标金额
    int n = sizeof(coins) / sizeof(coins[0]); // 硬币种类数量

    int ways = countWays(amount, coins, n);
    printf("共有 %d 种换法。\n", ways);

    return 0;
}
