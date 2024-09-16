#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

char* Lower(char *a) {
    char *p = a;
    while (*p != '\0') { // 判断字符串是否结束
        if (*p >= 'A' && *p <= 'Z') { // 只判断大写字母
            *p = *p + ('a' - 'A'); // 转换为小写
        }
        p++; // 移动指针
    }
    return a; // 返回修改后的字符串
}


int main() {
    char a[]="acgFFGj";
    printf("%s",Lower(a));
    return 0;
}