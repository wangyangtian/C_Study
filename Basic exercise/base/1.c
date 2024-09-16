#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int MaxNum(int n1,int n2,int n3){
    int max=n1;
    if(n2>max)  max=n2;
    if(n3>max)  max=n3;
    return max;
}

int main() {
    int a=4,b=1,c=5;
    printf("%d",MaxNum(a,b,c));
    return 0;
}