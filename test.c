#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void swap(int *x,int *str,int i){
    int temp;
    temp=*x;
    *x=str[i];
    str[i]=temp;
}

void permute(char *str,int k,int n){
    if(k==0){
        for(int i=0;i<n;i++)
            printf("%d ",str[1]);
    }
    else{
        
    }
}

int main() {

    return 0;
}