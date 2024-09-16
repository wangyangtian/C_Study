#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char *encode(char *str){
    char *p=str;
    int pos=0;
    while(*p!='\0'){
        *p=*p+5+pos;
        pos++;
        p++;
    }
    return str;
}

char *decode(char *str) {
    char *p = str;
    int pos = 0;

    // 遍历字符串并进行解密
    while (*p != '\0') {
        *p = *p - (5 + pos); // 解密当前字符，减去加密时的偏移量
        pos++; // 增加位置偏移量
        p++; // 移动指针到下一个字符
    }

    return str;
}

int main() {
    char str[]="mrsoft";
    encode(str);
    printf("%s",str);
    return 0;
}