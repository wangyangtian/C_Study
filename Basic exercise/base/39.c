#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

bool IsPalindrome(int n){
    int reverse=0,remainder,original=n;
    while (n!=0)
    {
        remainder=n%10;
        reverse=reverse*10+remainder;
        n/=10;
    }
    return reverse==original;
}

int main() {
    int n;
    printf("输入一个五位数:");
    scanf("%d",&n);
    if(IsPalindrome(n))
        printf("这是一个回文数");
    else
        printf("这不是一个回文数");
    return 0;
}