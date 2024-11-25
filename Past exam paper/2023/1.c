#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int max = INT_MIN;
    int min = INT_MAX;
    int a;
    for (int i = 0; i < 10; i++) {
        printf("输入第%d个数\n", i + 1);
        scanf("%d", &a);
        if (a > max)
            max = a;
        if (a < min)
            min = a;
    }
    printf("max=%d,min=%d", max, min);
    return 0;
}