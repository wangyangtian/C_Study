#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* my_strstr(char* haystack, char* neddle) {
    if (*neddle == '\0')
        return haystack;

    while (*haystack) {
        char* h = haystack;
        char* n = neddle;

        while (*h && *n && (*h == *n)) {
            h++;
            n++;
        }

        if (*n == '\0')
            return haystack;

        haystack++;
    }
    return NULL;
}

char* strstr(char* str1, char* str2) {
    int len1 = 0, len2 = 0;

    // 计算 str1 和 str2 的长度
    char* temp1 = str1;
    char* temp2 = str2;
    while (*temp1++ != '\0')
        len1++;
    while (*temp2++ != '\0')
        len2++;

    // 如果 str2 是空字符串，直接返回 str1
    if (len2 == 0)
        return str1;

    // 遍历 str1，查找是否包含 str2
    for (int i = 0; i <= len1 - len2; i++) {
        int match = 1;  // 匹配标志
        for (int j = 0; j < len2; j++) {
            if (str1[i + j] != str2[j]) {
                match = 0;
                break;
            }
        }
        if (match)
            return str1 + i;
    }

    // 如果未找到匹配的子串，返回 NULL
    return NULL;
}

int main() {
    return 0;
}