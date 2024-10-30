#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 生成从 n 个元素中抽取 r 个元素的所有组合
// a[] 是字符数组，b[] 用于存储当前组合的下标，R 是固定的总的组合长度
void Combine(int n, int r, char a[], int b[], int R) {
    if (r == 0) {  // 当所有元素被选中时
        for (int i = 0; i < R; i++) {
            printf("%c ", a[b[i]]);  // 打印组合结果
        }
        printf("\n");
    } else {
        for (int j = n; j >= r; j--) {       // 从n中选r个元素
            b[r - 1] = j - 1;                // 选择第j-1个元素
            Combine(j - 1, r - 1, a, b, R);  // 递归处理剩余的组合
        }
    }
}

// 若m个数组成集合，求该集合的子集
int main() {
    int n = 4;
    char a[] = "abcd";
    int b[4];
    for (int i = 0; i < n; i++) {
        Combine(n, i, a, b, i);
    }
    return 0;
}