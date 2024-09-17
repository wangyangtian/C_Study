#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MyStrlen(char* string) {
    int len = 0;
    char* p = string;
    while (*p != '\0') {
        p++;
        len++;
    }
    return len;
}

int MyAtoi(char* s) {
    int n = 0;
    while (*s != '\0') {
        n = n * 10 + (*s - '0');
        s++;
    }
    return n;
}

void MyItoa(int n, char* s) {
    int digit = 0;
    int temp = n;
    int isNegative = 0;

    // 处理负数
    if (n < 0) {
        isNegative = 1;
        n = -n;  // 取绝对值
        temp = -temp;
    }

    if (n == 0) {
        s[digit++] = '0';
        s[digit] = '\0';
        return;
    }

    while (temp != 0) {
        digit++;
        temp /= 10;
    }
    if (isNegative != 1) {
        for (int i = digit - 1; i >= 0; i--) {
            s[i] = n % 10 + '0';
            n /= 10;
        }
    } else {
        for (int i = digit; i > 0; i--) {
            s[i] = n % 10 + '0';
            n /= 10;
        }
        s[0] = '-';
    }

    s[digit + isNegative] = '\0';
}

char* MyStrcat(char* strDes, const char* strSrc) {
    char* des = strDes;
    const char* src = strSrc;
    while (*des != '\0')
        des++;
    while (*src != '\0') {
        *des = *src;
        des++;
        src++;
    }
    return strDes;
}

char* MyStrcpy(char* strDes, const char* strSrc) {
    const char* src = strSrc;
    char* des = strDes;
    while (*src != '\0') {
        *(des++) = *(src++);
    }
    *des = '\0';
    return strDes;
}

char* MyStrncpy(char* strDes, const char* strSrc, int count) {
    const char* src = strSrc;
    char* des = strDes;
    while (count--) {
        *(des++) = *(src++);
    }
    *des = '\0';
    return strDes;
}

int MyStrcmp(const char* s, const char* t) {
    while (*s && (*s == *t)) {
        s++;
        t++;
    }
    return *s - *t;
}

int MyStrncmp(const char* s, const char* t, int count) {
    while (*s && (*s == *t) && count) {
        s++;
        t++;
        count--;
    }
    // 如果比较字符数达到 count 直接返回 0，因为字符都相等
    if (count == 0)
        return 0;
    return *s - *t;
}

int main() {
    char* str = "12121";
    printf("%d\n", MyStrlen(str));
    printf("%d\n", MyAtoi(str));
    char a[10];
    MyItoa(1234, a);
    printf("%s\n", a);
    char str1[10] = "good ";
    char str2[10] = "day";
    MyStrcat(str1, str2);
    printf("%s\n", str1);
    char str3[10] = "good ";
    char str4[10] = "better";
    MyStrcpy(str3, str4);
    printf("%s\n", str3);
    char str5[10] = "worst";
    char str6[10] = "unhappy";
    MyStrncpy(str5, str6, 3);
    printf("%s\n", str5);
    char str7[10] = "good";
    char str8[10] = "gooe";
    printf("%d", MyStrncmp(str7, str8, 3));
    return 0;
}