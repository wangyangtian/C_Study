#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

bool IsPrimeNumber(int n){
    if (n <= 1) return false;  // 1及以下的数不是素数
    for (int i = 2; i <= sqrt(n); i++) {  // 遍历到sqrt(n)
        if (n % i == 0) 
            return false;  // 有因数，非素数
    }
    return true;
}

bool IsPalindromicNumber(int n){
    int digit=0,temp=n;
    while (temp>0)
    {
        temp/=10;
        digit++;
    }
    char *b=(char*)malloc(sizeof(char)*digit);
    itoa(n,b,10);
    int low=0,high=digit-1;
    while (low!=high)
    {
        if(b[low++]!=b[high--])
            return false;
    }
    return true;
}

int main() {
    for(int i=1;i<=1000;i++){
        if(IsPalindromicNumber(i)&&IsPrimeNumber(i))
            printf("%d ",i);
    }
    return 0;
}