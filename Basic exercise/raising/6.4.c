#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void transformation(int n,char *a,int digit){
    if(digit==0)
        return;
    else{
        a[digit-1]=n%10+'0';
        transformation(n/10,a,digit-1);
    }
}

int main() {
    char a[10];
    int b=114514;
    transformation(b,a,6);
    printf("%s",a);
    return 0;
}