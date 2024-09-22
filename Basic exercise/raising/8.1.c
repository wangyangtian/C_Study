#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>



int main() {
    char c;
    int inWord=0;
    int wordCount=0;

    printf("请输入一段英文文章：\n");
    while ((c=getchar())!=EOF)  
    {
        if(isalnum(c)){
            if(inWord==0){
                inWord=1;
                wordCount++;
            }

        }            
        else
            inWord=0;
    }
    printf("这篇文章共有 %d 个单词。\n", wordCount);    
    return 0;
}