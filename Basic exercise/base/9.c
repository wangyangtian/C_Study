#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

char *Upper(char *a){
    char *p=a;
    while (*p!='\0')
    {
        if(*p>='a'&&*p<='z')
            *p=*p+('A'-'a');
        p++;
    }
    return a;
}

int main() {
        char a[]="acgFFGj";
    printf("%s",Upper(a));
    return 0;
}