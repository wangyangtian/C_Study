#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

bool IsPalindrome(char *str){
    char *left=str;
    char *right=str;
    while(*(right+1)!='\0'){
        right++;
    }
    while (left<right)
    {
        if(*left!=*right){
            return false;
        }
        left++;right--;
    }
    return true;
}

int main() {
    char a[]="1234567654321";
    if(IsPalindrome(a))
        printf("是回文");
    else
    printf("不是回文");
    return 0;
}