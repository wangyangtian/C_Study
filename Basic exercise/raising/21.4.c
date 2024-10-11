#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>

int mySqrt(int x){
    int left = 0, right = x;
    while(left<=right){
        int mid = left + (right - left) / 2;
        if(mid*mid==x)
            return mid;
        else if(mid*mid<x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    printf("%d", mySqrt(9));
    return 0;
}