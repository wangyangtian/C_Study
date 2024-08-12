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

typedef struct SNode    
{
    char ch;
    struct SNode *next;
}SNode;

char FindFirst(SNode *s1,SNode *s2){//假设不带头结点
    
    while (s1->next!=NULL)
    {
        SNode *temp2=s2;
        bool found=false;
        while (temp2!=NULL)
        {
            if(s1->ch==temp2->ch){
                found =true;
                break;
            }
            temp2=temp2->next;
        }
        if(found==false)
            return s1->ch;
        s1=s1->next;
    }
    return '\0';
}

int CountFreq(SString str1, SString str2) {
    int count = 0;
    for (int i = 0; i <= str1.length - str2.length; i++) {
        int j;
        for (j = 0; j < str2.length; j++) {
            if (str1.ch[i + j] != str2.ch[j])
                break;
        }
        if (j == str2.length) {
            count++;
        }
    }
    return count;
}

HString* SubCat(HString str1, HString str2, int i, int j) {
    if (i > str1.length || i > j)
        return NULL;

    HString* ret = (HString*)malloc(sizeof(HString));
    ret->length = str1.length + str2.length - (j - i + 1);
    ret->ch = (char*)malloc((ret->length + 1) *
                            sizeof(char));  // +1 for null-terminator
    int n1 = 0, n2 = 0;
    // Copy str1 up to i
    for (int k = 0; k < i; ++k) {
        ret->ch[n1++] = str1.ch[k];
    }

    // Copy str2 entirely
    while (str2.ch[n2]) {
        ret->ch[n1++] = str2.ch[n2++];
    }

    // Copy str1 from j onwards
    for (int k = j + 1; k < str1.length; ++k) {
        ret->ch[n1++] = str1.ch[k];
    }
    return ret;
}

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
    SString s1 = {"hello world", 11};
    SString s2 = {"world", 5};
    printf("%d\n", CountFreq(s1, s2));

    return 0;
}