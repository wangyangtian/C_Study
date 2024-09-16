#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int MaxNum(){
    int a;int max=-9999;
    printf("请输入十个数");
    for(int i=0;i<10;i++){
        scanf("%d",&a);
        if(a>max)   max=a;
    }
    return max;
}

int main() {
    printf("%d",MaxNum());
    return 0;
}