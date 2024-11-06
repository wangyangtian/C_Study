#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 255

typedef struct string {
    char ch[MAXLEN];
    int length;
} SString;

typedef struct {
    char* ch;    // 按串长分配存储区，ch指向串的基地址
    int length;  // 串的长度
} HString;

// 字符串比较
int StrCompare(SString s1, SString s2) {
    int i = 1;
    while (s1.ch[i] == s2.ch[i]) {
        if (s1.ch[i] == '\0')
            return 0;
        i++;
    }
    return s1.ch[i] - s2.ch[i];
}

// 取出字符串S中位置在pos长度为len的子串
bool SubString(SString* sub, SString S, int pos, int len) {
    if (pos + len - 1 > S.length)
        return false;
    for (int i = pos; i < pos + len; i++)
        sub->ch[i - pos + 1] = S.ch[i];
    sub->ch[len + 1] = '\0';  // 以'\0'结尾
    sub->length = len;
    return true;
}

// 判断T是否为S的子串，如果是，返回子串开始位置
int Index(SString S, SString T) {
    SString sub;
    int len_s = S.length, len_t = T.length;
    int i = 1;
    while (i < len_s - len_t + 1) {
        SubString(&sub, S, i, len_t);
        if (StrCompare(sub, T) != 0)
            i++;
        else
            return i;
    }
    return -1;
}

int Index_2(SString s, SString t) {
    int i = 1, j = 1, k = i;

    while (i <= s.length && j <= t.length) {
        if (s.ch[i] == t.ch[j]) {
            i++;
            j++;
        } else {
            j = 1;
            i = k + 1;
        }
    }
    if (j > t.length)
        return k;
    else
        return 0;
}

int main() {
    SString s1 = {" llo", 3};
    SString s2 = {" hello", 5};
    int result = Index_2(s2, s1);
    printf("Result: %d\n", result);
    return 0;
}