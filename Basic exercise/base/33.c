#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int *reverse(int *a,int len){
    int i=0,j=len-1;
    int temp=a[i];
    while (i<j)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;j--;
    }
    return a;
}

int main() {
    int a[10]={0,1,2,3,4,5,6,7,8,9};
    int len=sizeof(a)/sizeof(a[1]);
    reverse(a,len);
    for(int i=0;i<len;i++){
        printf("%d ",a[i]);
    }
    return 0;
}