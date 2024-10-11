#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>

int stairs(int n){
    int i = 1;
    int count = 0;
    while(i<=n){
        if(i%7==0&&i%6==5&&i%5==4&&i%3==2&&i%2==1){
            printf("%d\n", i);
            count++;
        }
        i++;
    }
    return count;
}

int main() {
    stairs(999);
    return 0;
}