#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMaxMin() {
    int arr;
    int max = INT_MIN, min = INT_MAX;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr);
        max = arr > max ? arr : max;
        min = arr < min ? arr : min;
    }
    printf("十个数中最大值为%d最小值为%d", max, min);
}

int main() {
    printMaxMin();
    return 0;
}