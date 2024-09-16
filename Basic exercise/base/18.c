#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int Sum(int n, int currentTerm) {
    if (n == 1)
        return currentTerm;  // 递归终止条件，返回最后一项
    else
        return currentTerm + Sum(n - 1, currentTerm * 10 + 2);  // 当前项 + 剩余项的和
}

int main() {
    printf("%d",Sum(5,2));
    return 0;
}