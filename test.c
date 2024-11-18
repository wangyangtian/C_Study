#include <stdio.h>

void Combine(int n, int r, int comb[], int R) {
    if (r == 0) {
        for (int i = 0; i < R; i++) {
            printf("%d ", comb[i]);
        }
        printf("\n");
        return;  // 终止递归
    }

    for (int j = n; j >= r; j--) {
        comb[r - 1] = j;                 // 当前组合存储在 comb[r-1]
        Combine(j - 1, r - 1, comb, R);  // 递归选择下一个数字
    }
}

int main() {
    int a[10];  // 用于存储组合的数组
    int n = 5, r = 3;

    printf("All combinations of %d choose %d:\n", n, r);
    Combine(n, r, a, r);
    return 0;
}
