#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isSymmetry(char* str) {
    int len = strlen(str);
    int left = 0, right = len - 1;
    while (left < right) {
        if (str[left] != str[right])
            return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    char str[100];
    scanf("%s", str);
    if (isSymmetry(str))
        printf("%s为回文字符串\n", str);
    else
        printf("%s不是回文字符串\n", str);
    return 0;
}