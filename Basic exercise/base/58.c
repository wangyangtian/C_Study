#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char *CapsLock(char *str){
    char *orig = str; 
    while (*str!='\0')
    {
        if(islower(*str))
            *str=toupper(*str);
        else if(isupper(*str))
            *str=tolower(*str);
        str++;
    }
    return orig;
}

int main() {
    char str[1024];
    printf("输入字符串：");
    gets(str);
    CapsLock(str);
    printf("%s\n",str);
    return 0;
}