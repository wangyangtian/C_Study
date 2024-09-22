#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
    创建并初始化数组表示每个人的状态。
    通过环形遍历数组，根据规则逐一淘汰人。
    在剩下最后一人时，返回他的编号。
*/
int josephus(int n, int m) {
    int* a = (int*)malloc(sizeof(int) * n);
    int remain = n;
    int count = 0;
    int i, j=0;
    for (int i = 0; i < n; i++)
        a[i] = 1;

    // 当剩余人数大于1时，不断淘汰
    while (remain > 1) {
        for (i = 0; i < n; i++) {
            if (a[j] == 1) {  // 如果当前位置的人还在圈里
                count++;
                if (count == m) {  // 如果计数到 m，淘汰此人
                    a[j] = 0;  // 淘汰
                    remain--;  // 剩余人数减少
                    count = 0; // 重置计数器
                }
            }
            j = (j + 1) % n;  // 循环移动到下一个人
        }
    }

    // 找到最后剩下的那个人
    for (i = 0; i < n; i++) {
        if (a[i] == 1) {
            free(a);  // 释放分配的内存
            return i + 1;  // 返回最后一个人的位置（假设位置从1开始）
        }
    }

    free(a);  // 释放内存
    return -1; // 如果出错，返回 -1    
}

int main() {
    printf("%d",josephus(5,3));
    return 0;
}