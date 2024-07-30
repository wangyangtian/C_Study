#include <stdio.h>
#include <stdbool.h>
#define MAXLEN 100

typedef struct string {
    char ch[MAXLEN];
    int length;
} SString;

//字符串比较
int StrCompare(SString s1, SString s2) {
    int i = 1; // 从1开始
    while (i <= s1.length && i <= s2.length && s1.ch[i] == s2.ch[i]) {
        i++;
    }
    if (i > s1.length && i > s2.length) {
        return 0; // 两个字符串完全相同
    }
    if (i <= s1.length && i <= s2.length) {
        return s1.ch[i] - s2.ch[i];
    }
    return s1.length - s2.length;
}

//取出字符串S中位置在pos长度为len的子串
bool SubString(SString *sub, SString S, int pos, int len) {
    if (pos + len - 1 > S.length) {
        return false;
    }
    for (int i = 0; i < len; i++) {
        sub->ch[i + 1] = S.ch[pos + i];
    }
    sub->length = len;
    sub->ch[len + 1] = '\0'; // 以'\0'结尾
    return true;
}

//判断T是否为S的子串，如果是，返回子串开始位置
int Index(SString S, SString T) {
    SString sub;
    int len_s = S.length, len_t = T.length;
    for (int i = 1; i <= len_s - len_t + 1; i++) {
        if (SubString(&sub, S, i, len_t)) {
            if (StrCompare(sub, T) == 0) {
                return i; // 找到子串，返回起始位置
            }
        }
    }
    return -1; // 未找到子串
}

int main() {
    SString s1 = {" hello", 5}; // 第一个元素空出，从1开始
    SString s2 = {" ll", 2};    // 第一个元素空出，从1开始
    int result = Index(s1, s2);
    printf("Result: %d\n", result);
    return 0;
}
