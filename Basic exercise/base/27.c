#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool IsArmstrongNumber(int n) {
    int temp = n, sum = 0;
    while (temp != 0) {
        sum += (int)pow(temp % 10, 3);
        temp = temp / 10;
    }
    return sum == n; // 如果 sum 等于 n，返回 true，否则 false
}



int main() {
    for(int i=0;i<1000;i++){
        if(IsArmstrongNumber(i))
            printf("%d ",i);
    }

    return 0;
}