#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int MyAtoi(const char* str) {
    int result = 0;
    int sign = 1;

    while (*str == ' ') {
        str++;
    }
    while (*str == '-' || *str == '+') {
        sign = (*str == '-') ? -1 : 1;
        str++;
    }
    while (isdigit(*str)) {
        int digit = *str - '0';
        result = result * 10 + digit;
        str++;
    }
    return result * sign;
}

void* MyMemcpy(void* dest, const void* src, size_t n) {
    char* d = (char*)dest;
    const char* s = (const char*)src;
    while (n--) {
        *d++ = *s++;
    }
    return dest;
}

void* MyMemmove(void* dest, const void* src, size_t n) {
    char* d = (char*)dest;
    const char* s = (const char*)src;
    if (d == s)
        return dest;

    if (d < s || d > s + n) {
        while (n--) {
            *d++ = *s++;
        }
    } else {
        d += n;
        s += n;
        while (n--) {
            *(--d) = *(--s);
        }
    }
    return dest;
}

char* MyStrcpy(char* dest, const char* src) {
    char* d = dest;  // 保存dest的原始地址
    while ((*d++ = *src++) != '\0')
        ;         // 使用d进行指针操作
    return dest;  // 返回目标字符串的起始地址
}

char* MyStrncpy(char* dest, const char* src, size_t n) {
    char* d = dest;
    while (n--) {
        *d++ = *src++;
    }
    return dest;
}

char* MyStrcat(char* dest, char* src) {
    char* d = dest;
    while (*d != '\0') {
        d++;
    }
    while ((*d++ = *src++))
        ;
    return dest;
}

char* MyStrncat(char* dest, char* src, size_t n) {
    char* d = dest;
    while (*d != '\0') {
        d++;
    }
    while (n--) {
        *d++ = *src++;
    }
    return dest;
}

int MyMemcmp(const void* ptr1, const void* ptr2, size_t num) {
    const char* p1 = (const char*)ptr1;
    const char* p2 = (const char*)ptr2;
    while (num--) {
        if (*p1 == *p2) {
            p1++;
            p2++;
        } else
            return *p1 - *p2;
    }
    return 0;
}

int MyStrcmp(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

const char* MyStrstr(const char* haystack, const char* needle) {
    if (*needle == '\0') {
        // If needle is empty, return haystack
        return haystack;
    }

    while (*haystack) {
        const char* h = haystack;
        const char* n = needle;

        while (*h && *n && (*h == *n)) {
            h++;
            n++;
        }

        if (*n == '\0') {
            // If we reached the end of needle, it means we found a match
            return haystack;
        }

        haystack++;
    }

    return NULL;  // No match found
}

/**
 * @brief 查找字符在字符串中首次出现的位置
 *
 * @param str 输入字符串
 * @param ch 查找的字符
 * @return char* 返回字符首次出现的位置，如果未找到则返回NULL。
 */

char* MyStrchr(const char* str, int ch) {
    while (*str) {
        if (*str == ch) {
            return (char*)str;
        }
        str++;
    }
    return NULL;
}

static char* _strtok = NULL;

/**
 * @brief 分割字符串为一系列标记（tokens），这些标记由一组指定的分隔符分割。
 *
 * @param s 输入字符串，第一次调用时传入需要分割的字符串，后续调用时传入NULL。
 * @param delim 分隔符字符串，包含所有用于分割标记的字符。
 * @return char* 返回指向当前标记的指针，如果没有更多标记则返回NULL。
 */
char* MyStrtok(char* s, const char* delim) {
    char *sbegin, *send;

    // 如果提供了新的字符串s，则从该字符串开始分割，否则使用上一次分割的位置
    sbegin = s ? s : _strtok;

    // 如果没有更多字符串可分割，返回NULL
    if (!sbegin) {
        return NULL;
    }

    // 跳过字符串开头的所有分隔符字符
    while (*sbegin && MyStrchr(delim, *sbegin)) {
        sbegin++;
    }

    // 如果到达字符串末尾，则没有更多标记
    if (*sbegin == '\0') {
        _strtok = NULL;
        return NULL;
    }

    // 找到下一个分隔符的位置
    send = sbegin;
    while (*send && !MyStrchr(delim, *send)) {
        send++;
    }

    // 如果找到分隔符，则将其替换为'\0'，并更新_strtok指向下一个位置
    if (*send) {
        *send = '\0';
        _strtok = send + 1;
    } else {
        _strtok = NULL;
    }

    // 返回当前标记的起始位置
    return sbegin;
}

int main() {
    char str[] = "Hello, World! Welcome to C programming.";
    char* delim = " ,.!";

    char* token = MyStrtok(str, delim);
    while (token != NULL) {
        printf("%s\n", token);
        token = MyStrtok(NULL, delim);
    }

    return 0;
}