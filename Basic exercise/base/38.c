#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool IsPalindrome(int num) {
    int digit = 0;
    int squre = num * num;
    int temp = squre;

    // 计算数字的位数
    while (temp != 0) {
        digit++;
        temp /= 10;
    }

    // 存储数字的每一位
    int *b = (int *)malloc(sizeof(int) * digit);
    for (int i = 0; i < digit; i++) {
        b[i] = squre % 10;
        squre /= 10;
    }

    // 检查是否是回文
    int i = 0;
    digit--;  // 从最后一位开始比较
    while (i < digit) {
        if (b[i++] != b[digit--]) {
            free(b);  // 释放内存
            return false;
        }
    }

    free(b);  // 释放内存
    return true;
}

// 判断一个数是否为回文数
bool is_palindrome(int num) {
    int reversed = 0, original = num, remainder;
    
    // 反转数字
    while (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }
    
    // 判断反转后的数字是否与原始数字相等
    return original == reversed;
}

int main() {
    // 遍历 1 到 255 之间的数
    for (int i = 1; i <= 255; i++) {
        if (IsPalindrome(i)) {
            printf("%d\n", i);  // 输出符合条件的数
        }
    }
    return 0;
}
