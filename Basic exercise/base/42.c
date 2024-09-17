#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char *DeleteStar(char *str){
    char *left=str;
    char *right=str;
    char *current;
    while(*right!='\0'){
        right++;
    }
    right--;
    while(*left=='*')
        left++;
    while (*right=='*')
        right--;
    for(current=left;current<=right;current++){
        if(*current!='*'){
            *left=*current;
            left++;
        }
    }
    while (*current!='\0'){
        *left++='*';
        current++;
    }
    *left++='\0';
    return str;
}

int main() {
    char a[100];
    printf("输入字符串");
    scanf("%s",a);
    DeleteStar(a);
    printf("%s",a);
    return 0;
}