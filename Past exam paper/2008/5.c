#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double avg(int* a, int n) {
    if (n == 0) {
        return 0;
    }

    // 递归计算总和，并最终除以数组长度
    return (a[0] + avg(a + 1, n - 1) * (n - 1)) / n;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    printf("%.2lf\n", avg(a, 5));
    return 0;
}
