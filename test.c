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

typedef struct{
	char *ch;	//按串长分配存储区，ch指向串的基地址
	int length;	//串的长度
}HString;



void DeleteI2J(SString* s, unsigned int i, unsigned int j) {
    if ((int)i > s->length)
        return;

    if (j <= s->length - i) {
        while (i <= s->length - j) {
            s->ch[i] = s->ch[i + j];
            i++;
        }
        s->length = s->length - j;
    } else {
        s->length = i + 1;
    }
}

void Ch1toCh2(char* str, int ch1, int ch2) {
    if (!*str)
        return;
    while (*str != '\0') {
        if (*str == ch1) {
            *str = ch2;
        }
        str++;
    }
}

void ReverseString(char* str, int len) {
    char* front = str;
    char* rear = str + len - 1;
    if (!str)
        return;

    while (front < rear) {
        char temp = *front;
        *front = *rear;
        *rear = temp;
        front++;
        rear--;
    }
}
char* DeleteCh(char* str, char ch) {
    if (!str)
        return str;
    char* newstr = str;
    char* start = str;
    while (*str) {
        if (*str != ch) {
            *newstr = *str;
            newstr++;
        }
        str++;
    }
    *newstr = '\0';
    return start;
}

int FindSubString(const char* str, const char* substr, int pos) {
    if (str == NULL || substr == NULL || pos < 0) {
        return -1;
    }

    int lenStr = strlen(str);
    int lenSubstr = strlen(substr);

    if (pos > lenStr || lenStr == 0) {
        return -1;
    }

    for (int i = pos; i <= lenStr - lenSubstr; i++) {
        int j;
        for (j = 0; j < lenSubstr; j++) {
            if (*(str + i + j) != *(substr + j)) {
                break;
            }
        }
        if (j == lenSubstr) {  // 完整匹配后才返回
            return i;
        }
    }
    return -1;  // 未找到匹配的子串
}

int main() {
    char str[] = "111133";
    // Ch1toCh2(str,'1','2');
    // ReverseString(str,6);
    DeleteCh(str, '1');
    printf("%s\n", str);

    const char* str2 = "hello world";
    const char* substr = "world";
    int pos = 2;

    int result = FindSubString(str2, substr, pos);
    if (result != -1) {
        printf("子串的位置: %d\n", result);
    } else {
        printf("未找到匹配的子串。\n");
    }
    SString s = {"123456789", 9};
    DeleteI2J(&s, 1, 5);
    printf("%s", s.ch);
    return 0;
}