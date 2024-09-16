#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int main() {
    printf("输入一行字符：\n");
    char ch;
    bool inword=0;
    int count =0;
    while ((ch=getchar())!='\n'){
        if(isspace(ch)){
            inword=0;
        }
        else if(!inword){
            inword=1;
            count++;
        }
    }
    printf("总共有 %d 个单词\n",count);
    return 0;
}